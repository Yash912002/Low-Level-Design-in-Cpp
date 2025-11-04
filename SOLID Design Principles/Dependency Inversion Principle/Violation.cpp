#include <bits/stdc++.h>
#include "../../utils/Logger.h"
using namespace std;

class MongoDatabase {
public:
  void saveToMongo(string data) {
    LOG_SUCCESS(data, " saved to MongoDB");
  }
};

class MySQLDatabase {
public:
  void saveToMySQL(string data) {
    LOG_SUCCESS(data, " saved to MySQL");
  }
};

class UserService {
private:
  MongoDatabase mongo;
  MySQLDatabase sql;

public:
  void saveUserToMongo(string name) { mongo.saveToMongo(name); }

  void saveUserToMySQL(string name) { sql.saveToMySQL(name); }
};

int main() {
  UserService user;
  user.saveUserToMongo("yash");
  user.saveUserToMySQL("shreyash");
  return 0;
}