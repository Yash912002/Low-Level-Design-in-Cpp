#include <iostream>
using namespace std;

class Car {
private:
  int currentSpeed;
  bool isEngineOn;

public:
  Car() {
    cout << "CAR CONSTRUCTOR CALLED" << endl;
    this->currentSpeed = 0;
    this->isEngineOn = false;
  }

  void startTheCar() {
    if (this->isEngineOn == true) {
      cout << "Engine is already on." << endl;
      return;
    }

    this->isEngineOn = true;
    cout << "Car started" << endl;
  }

  int getCurrentSpeed() { return this->currentSpeed; }

  virtual ~Car() { cout << "Car destructor is called " << endl; }
};

class Audi : public Car {
private:
  string tyre;

public:
  Audi() {
    cout << "AUDI CONSTRUCTOR CALLED" << endl;
    this->tyre = "CEAT";
  }

  void getTyreBrand() {
    cout << "Audi is using " << this->tyre << " tyres " << endl;
  }

  void setTyreBrand(string tyreBrand) {
    if (this->tyre == tyreBrand) {
      cout << "Audi already have " << this->tyre << " tyres" << endl;
      return;
    }
    this->tyre = tyreBrand;
    cout << "Audi is now using " << this->tyre << " tyres" << endl;
  }

  ~Audi() override { cout << "Audi destructor is called " << endl; }
};

int main() {
  // Car *car = new Car();
  Car *car = new Audi();
  car->startTheCar();
  int speed = car->getCurrentSpeed();
  cout << speed << " km/hr" << endl;

  // car->getTyreBrand();
  // car->setTyreBrand("MRF");

  delete car;
  return 0;
}