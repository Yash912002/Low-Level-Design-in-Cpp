#include <bits/stdc++.h>
using namespace std;

class Car {
private:
  int currentSpeed;
  bool isengineOn;

public:
  Car() {
    currentSpeed = 0;
    isengineOn = false;
  }

  void startEngine() {
    if (isengineOn == false) {
      isengineOn = true;
      cout << "Engine started." << endl;
      return;
    }

    cout << "Engine is already on." << endl;
  }

  void getSpeed() { cout << "Current speed: " << this->currentSpeed << endl; }

  void setSpeed(int speed) {
    if (isengineOn == false) {
      cout << "Engine is off." << endl;
      return;
    }

    if (speed > 0 && speed <= 200) {
      this->currentSpeed = speed;
      cout << "Speed set to: " << this->currentSpeed << endl;
    }
  }

  void stopEngine() {
    if (isengineOn == true) {
      isengineOn = false;
      this->currentSpeed = 0;
      cout << "Engine stopped." << endl;
      return;
    }
    cout << "Engine is already off." << endl;
  }
};

int main() {
  Car *car1 = new Car();
  car1->startEngine();
  car1->startEngine();

  car1->getSpeed();
  car1->setSpeed(100);

  car1->getSpeed();
  car1->stopEngine();

  car1->getSpeed();
  car1->stopEngine();
}
