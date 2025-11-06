#include "../../utils/Logger.h"
#include <bits/stdc++.h>
using namespace std;

class Singleton {
private:
  static Singleton *singleInstance;
  Singleton() {
    LOG_SUCCESS("Singleton constructor called. New object is created.");
  }

public:
  static Singleton *getInstance() {
    if (singleInstance == nullptr) {
      singleInstance = new Singleton();
    }
    return singleInstance;
  }
};

Singleton *Singleton::singleInstance = nullptr;

int main() {
  Singleton *s1 = Singleton::getInstance();
  Singleton *s2 = Singleton::getInstance();

  cout << (s1 == s2) << endl;
  return 0;
}