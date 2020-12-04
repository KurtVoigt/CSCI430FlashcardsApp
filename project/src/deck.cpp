

#include "deck.h"

/*
This function is a callback function for sqlite, it is called for every individual result of an sql query
void *ret - a space where one may cast a data structure in order to acess this data out of the function, i.e:
  -std::vector<myData> *list = reinterpret_cast<std::vector<myData> *>(ret);
    -keep in mind here that it may be useful to create a struct that will hold all the information collected at every call
     like the one commented above.
  -you will also have to pass the data structure by reference into the exec function, this will be passed as the ret parameter
    -rc = sqlite3_exec(db, sql.c_str(), callback, &DATASTRUCTURE, &zErrMsg);
int argc - the number of columns which a query returns, useful for iterating through an entire row of results
  -from i=0 to argc-1 print argv[i], azColName[i]
char **argv - a 2d string of the data result. The size of it will be the number of columns you requested in the order
that the sql query was formed in. For example if you gave sqlite SELECT name, id, sex:
  -argv[0] will be the name at a call
  -argv[1] will be the id at a call
  -argv[2] will be the sex at a call
char **azcolname - similar to argv but instead of the data of the row and column specified it will be the column name,
for the argv example:
  -azColName[0] will be the c string "name" at call
  -azColName[1] will be the c string "id" at call
  -azColName[2] will be the c string "sex" at call
If you do not need to use a callback function (for example for inserting into the table or making a new table)
you may type in NULL into the sqlite3_exec for the callback. This is what the documentation says to do.
*/
int cardcallback(void *ret, int argc, char **argv, char **azColName){
    deck *deckObject = reinterpret_cast<deck *>(ret);
    //order is WEIGHT, DATA, ANSWER, SENTENCE
    card c = card(std::string(argv[1]), std::string(argv[2]), std::string(argv[3]));
    c.setWeight(atof(argv[0]));
    //card is now made, push into deck's prio queue
    deckObject->pushCard(c);
    return 0;
}

int deckcallback(void *ret, int argc, char **argv, char **azColName){
  deck *deckObject = reinterpret_cast<deck *>(ret);
  double weight = atof(argv[0]);
  deckObject->setWeight(weight);
  return 0;
}

int randomAnswercallback(void *ret, int argc, char **argv, char **azColName){
  std::vector<std::string> *answers = reinterpret_cast<std::vector<std::string> *>(ret);
  answers->push_back(std::string(argv[0]));
  return 0;
}


/*
Constructor used to pull a deck from the database
needs only the unique deck name
*/
deck::deck(std::string deckName){
  name = deckName;
  weight = 0.6;
  this->readDeck();
}
/*creation of a new deck from scratch, will make a new entry on database
for the deck as well as create the necessary tables on the DB if they don't exist
this can also be used to add new cards into a deck by passing in a name that
is already in existence, will have constructed a new object though*/
deck::deck(std::string newName, bool flag){
    name = newName;
    weight = 0.0;

    std::string sql;
    int rc;
    sqlite3 *db;
    char *zErrMsg = 0;

    rc = sqlite3_open(str(DBNAME), &db);
    if(rc) {//if rc == 1 that means that whatever sqlite operation failed, 0 is good!
     std::cerr << "DB Error: " << sqlite3_errmsg(db) << std::endl;
   } 

    //enables foreign keys in SQLite
    sql = "PRAGMA foreign_keys = ON";
    rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &zErrMsg);

    //create the decks table if it doesn't already exist
    //two decks may not have the same name so a text primary key is acceptable
    sql = "CREATE TABLE IF NOT EXISTS DECKS ("  \
      "NAME TEXT PRIMARY KEY     NOT NULL," \
      "WEIGHT           DOUBLE    NOT NULL);";

    

    rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &zErrMsg);

    //database is now open and the table of decks was made if it was not already there
    //add the deck entry to the table

    sql = "INSERT INTO DECKS ('NAME', 'WEIGHT') VALUES ('"+newName+"', '"+"0"+"');";

    rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &zErrMsg);

    //create the cards table if it is not created
    //a card may only belong to one deck, but two cards may have the same name
    //therefore it will have a numeric ID as the primary key
    //if you insert a card into the table, put NULL for the ID, SQLite automatically increments it itself
    sql = "CREATE TABLE IF NOT EXISTS CARDS ("  \
      "ID        INTEGER   PRIMARY KEY, " \
      "WEIGHT    DOUBLE    NOT NULL, " \
      "DATA      TEXT      NOT NULL, " \
      "ANSWER    TEXT      NOT NULL, " \
      "SENTENCE  TEXT, " \
      "DECK      TEXT      NOT NULL, " \
      "FOREIGN KEY(DECK) REFERENCES DECKS(NAME));";

    rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &zErrMsg);

    rc = sqlite3_close(db);

}

//pushes a card into the decks priority queue
void deck::pushCard(card c){
  deckInstance.push(c);
  //std::cout << "pushed "<<c.getData() <<" with weight " <<c.getWeight() <<std::endl;
}


//writes the deck into the database
void deck::writeDeck(){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    std::string sql;

    rc = sqlite3_open(str(DBNAME), &db);

    if( rc ) {
      std::cout << "DB Error: " << sqlite3_errmsg(db) << std::endl;
    }
    while(!deckInstance.empty()){
        card c = deckInstance.top();
        deckInstance.pop();
        sql = "INSERT INTO CARDS ('ID', 'WEIGHT', 'DATA', 'ANSWER', 'SENTENCE', 'DECK') VALUES (NULL, '"+std::to_string(c.getWeight())+
        "', '"+c.getData()+"', '"+c.getAnswer()+"', '"+c.getSentence()+"', '"+name+"');";
        rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &zErrMsg);
    }
}





//updates the deck weight and card weights in the database
void deck::updateDeck(){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    std::string sql;
    double avg = 0.0;
    int size = deckInstance.size();
    rc = sqlite3_open(str(DBNAME), &db);

    if( rc ) {
      std::cout << "DB Error: " << sqlite3_errmsg(db) << std::endl;
    } 

    //update cards
    while(!deckInstance.empty()){
        card c = deckInstance.top();
        deckInstance.pop();
        //just realized that there is no way to access a card's unique id. deck, data and answer should be enough but if there are repeats it will update both
        sql = "UPDATE CARDS SET WEIGHT = '"+std::to_string(c.getWeight())+"' WHERE DECK = '"+this->name+"' AND DATA = '"+c.getData()+"' AND ANSWER = '"
        +c.getAnswer()+"';";
        rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &zErrMsg);
        avg = avg + c.getWeight();
    }
    avg = avg/size;
    sql = "UPDATE DECKS SET WEIGHT = '"+std::to_string(avg)+"' WHERE NAME = '"+this->name+"';";
    rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &zErrMsg);
    rc = sqlite3_close(db);
}

/*
Using the decks name, build the deck from the database
*/
void deck::readDeck(){
  std::string sql;
  int rc;
  sqlite3 *db;
  char *zErrMsg = 0;

  rc = sqlite3_open(str(DBNAME), &db);
  if(rc) {//if rc == 1 that means that whatever sqlite operation failed, 0 is good!
    std::cerr << "DB Error: " << sqlite3_errmsg(db) << std::endl;
  } 

  //deck is made, get its weight from the database
  sql = "SELECT WEIGHT FROM 'DECKS'" \
        " WHERE NAME = '"+this->name+"';";
  rc = sqlite3_exec(db, sql.c_str(), deckcallback, this, &zErrMsg);
  //deck object now has correct name and weight as was stored in the database
  //time to populate its prioqueue with the cards which are assigned to it.
  sql = "SELECT WEIGHT, DATA, ANSWER, SENTENCE FROM 'CARDS' WHERE DECK = '"+this->name+"';";
  rc = sqlite3_exec(db, sql.c_str(), cardcallback, this, &zErrMsg);
  //prio queue is now populated with cards that were associated with this deckName
  rc = sqlite3_close(db);
  
}

/* 
"CREATE TABLE IF NOT EXISTS CARDS ("  \
      "ID        INTEGER   PRIMARY KEY, " \
      "WEIGHT    DOUBLE    NOT NULL, " \
      "DATA      TEXT      NOT NULL, " \
      "ANSWER    TEXT      NOT NULL, " \
      "SENTENCE  TEXT, " \
      "DECK      TEXT      NOT NULL, " \
      "FOREIGN KEY(DECK) REFERENCES DECKS(NAME));";*/


/*
 *Returns the a pointer to the card at the top of the prio queue
 * for the purpose of passing it through the gui
 */

card* deck::displayDeck(){

  if(deckInstance.top().getWeight() != 1.0){

      card *c = new card(deckInstance.top().getData(),deckInstance.top().getAnswer(),deckInstance.top().getSentence());
      c->setWeight(deckInstance.top().getWeight());
      deckInstance.pop();
      return c;
  }
  else{

      card *c = new card("does not", "matter", "here");
      c->setWeight(1.0);
      return c;
  }
}


/*
 * Returns a vector of answers from the corresponding deck with the name
    name. For the purposes of creating random answers on the review deck funtion

 */
std::vector<std::string> deck::randomAnswers(std::string name){
    std::vector<std::string> ret;
    std::vector<std::string> *ptr = &ret;
    srand(time(NULL));
    std::string sql;
    int rc;
    sqlite3 *db;
    char *zErrMsg = 0;

    rc = sqlite3_open(str(DBNAME), &db);
    if(rc) {//if rc == 1 that means that whatever sqlite operation failed, 0 is good!
      std::cerr << "DB Error: " << sqlite3_errmsg(db) << std::endl;
    }

    //deck is made, get its weight from the database
    sql = "SELECT ANSWER FROM 'CARDS'" \
          " WHERE DECK = '"+name+"';";
    rc = sqlite3_exec(db, sql.c_str(), randomAnswercallback, ptr, &zErrMsg);
    if(rc) {//if rc == 1 that means that whatever sqlite operation failed, 0 is good!
      std::cerr << "DB Error: " << sqlite3_errmsg(db) << std::endl;
    }
    return ret;

}


 
