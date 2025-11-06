#include "../../utils/Logger.h"
#include <bits/stdc++.h>
using namespace std;

class Singleton {
private:
  static Singleton *singleInstance;
  static mutex mtx;
  static mutex coutmutex;

  Singleton() {
    LOG_SUCCESS("Singleton constructor called. New object is created.");
  }

public:
  // Thread t1 and t2 can execute line 17 at the same time, and get into the
  // if block, but only one thread will get the lock at a time. Let's say t1
  // got the lock and created a singleton instance. Now t2 will check
  // again whether the singleInstance is pointing to null or is it created, if
  // it is created then t2 will not be able to create another instance.
  static Singleton *getInstance() {
    if (singleInstance == nullptr) {
      // Thread safety
      lock_guard<mutex> lock(mtx);
      if (singleInstance == nullptr) {
        singleInstance = new Singleton();
      }
    }
    return singleInstance;
  }

  // Thread specific logic. Ignore if you don't know.
  static void threadTask(int id) {
    Singleton *instance = Singleton::getInstance();
    {
      lock_guard<mutex> lock(coutmutex);
      cout << "Thread " << id << " got instance at address: " << instance
           << endl;
    }
  }
};

Singleton *Singleton::singleInstance = nullptr;
mutex Singleton::mtx;
mutex Singleton::coutmutex;

int main() {
  vector<thread> threads;

  // Launch 10 threads calling getInstance()
  for (int i = 0; i < 10; ++i) {
    threads.push_back(thread(Singleton::threadTask, i));
  }

  // Join all threads
  for (auto &t : threads)
    t.join();
  return 0;
}