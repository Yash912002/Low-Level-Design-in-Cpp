#include <bits/stdc++.h>
#include "../../utils/Logger.h"
using namespace std;

class Persistance {
public:
  virtual void save(string data)  = 0;
  virtual ~Persistance() = default;
};

class MongoDatabase : public Persistance {
public:
  void save(string data) override {
    LOG_SUCCESS(data, " saved to MongoDB");
  }
};

class MySQLDatabase : public Persistance {
public:
  void save(string data) override {
    LOG_SUCCESS(data, " saved to MySQL");
  }
};

class UserService {
private:
  Persistance *db;

public:
  explicit UserService(Persistance* database) : db(database) {};

  void saveUser(string name) {
    db->save(name);
  }
};

int main() { 
  MongoDatabase *mongo = new MongoDatabase();
  UserService *user1 = new UserService(mongo);
  user1->saveUser("yash");

  MySQLDatabase *mysql = new MySQLDatabase();
  UserService *user2 = new UserService(mysql);
  user2->saveUser("yash");
  return 0; 
}