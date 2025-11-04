/*
  Dynamic polymorphism OR
  Runtime Polymorphism OR
  Method Overriding OR
  Late Binding.
  All of this are same concept.
*/

/*
  Even though both pointers are of type Car*,
  the actual object type (BMW or Audi) decides which function runs.

  At runtime:
  1) The compiler uses a virtual table.

  2) Each object of a class with virtual functions
    has a hidden pointer (vptr)

  3) That pointer points to the class's vtable.

  4) When you call a virtual function, C++ looks up the
    correct function address in that table and calls it dynamically.

*/

#include <iostream>
using namespace std;

class Car {
public:
  // virtual enables runtime polymorphism
  virtual void start() { cout << "Starting a generic car..." << endl; }

  virtual void stop() { cout << "Stopping a generic car..." << endl; }

  // virtual destructor ( Good Practice )
  virtual ~Car() {}
};

class BMW : public Car {
public:
  void start() override {
    cout << "BMW started with push-button ignition!" << endl;
  }

  void stop() override {
    cout << "BMW stopped using auto braking system!" << endl;
  }
};

class Audi : public Car {
public:
  void start() override {
    cout << "Audi started silently (hybrid mode)!" << endl;
  }

  void stop() override {
    cout << "Audi stopped with regenerative braking!" << endl;
  }
};

int main() {
  Car *bmw = new BMW();
  Car *audi = new Audi();

  bmw->start(); // calls BMW::start() at runtime
  bmw->stop();  // calls BMW::stop()

  audi->start(); // calls Audi::start() at runtime
  audi->stop();  // calls Audi::stop()

  delete bmw;
  delete audi;

  return 0;
}
