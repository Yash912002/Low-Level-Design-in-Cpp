#include <iostream>
using namespace std;

// Encapsulation start
class Car {
protected:
  int currentSpeed;
  bool isEngineOn;

public:
  Car() {
    this->currentSpeed = 0;
    this->isEngineOn = false;
  }

  // Abstraction & runtime polymorphism
  virtual void accelerate() = 0;
  virtual void accelerate(int speed) = 0;
  virtual ~Car() { cout << "Car destructor called " << endl; }
};
// Encapsulation end

// Inheritance
class Audi : public Car {
public:
  // Compile time polymorphism start
  void accelerate() override {
    if (isEngineOn == false) {
      isEngineOn = true;
      cout << "Turned on the Engine" << endl;
    }

    this->currentSpeed += 10;
    cout << "Current speed of Audi is " << this->currentSpeed << " Km/hr"
         << endl;
  }

  void accelerate(int speed) override {
    if (isEngineOn == false) {
      isEngineOn = true;
    }

    this->currentSpeed += speed;
    cout << "Current speed of Audi is " << this->currentSpeed << " Km/hr"
         << endl;
  }

  // Compile time polymorphism end
  ~Audi() override { cout << "Audi destructor called " << endl; }
};

int main() {
  Car *car = new Audi();
  car->accelerate();
  car->accelerate(70);
  delete car;
  return 0;
}