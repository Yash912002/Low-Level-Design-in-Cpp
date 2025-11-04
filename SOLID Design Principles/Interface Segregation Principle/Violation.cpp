#include <cmath>
#include <iostream>

#include "../../utils/Logger.h"

using namespace std;

class Shape {
public:
  virtual double area() const = 0;
  virtual double cube() const = 0;
  virtual ~Shape() = default;
};

class Square : public Shape {
private:
  double side;

public:
  explicit Square(double s) : side(s) {};

  double area() const override { return side * side; }

  double cube() const override {
    throw logic_error("Square does not have a cube property.");
  }
};

class RectangleShape : public Shape {
private:
  double length, width;

public:
  RectangleShape(double l, double w) : length(l), width(w) {};

  double area() const override { return length * width; }

  double cube() const override {
    throw logic_error("Rectangle does not have a cube property.");
  }
};

class Cylinder : public Shape {
private:
  double radius, height;

public:
  Cylinder(double r, double h) : radius(r), height(h) {}

  // Surface area of cylinder = 2πr(h + r)
  double area() const override { return 2 * M_PI * radius * (height + radius); }

  // Volume of cylinder = πr²h
  double cube() const override { return M_PI * radius * radius * height; }
};

int main() {
  try {
    Square square(5);
    RectangleShape rectangle(4, 6);
    Cylinder cylinder(3, 10);

    cout << fixed;
    cout.precision(2);

    LOG_SUCCESS("Square area: ", square.area(), " sq.units");
    LOG_SUCCESS("Rectangle area: ", rectangle.area(), " sq.units");
    LOG_SUCCESS("Cylinder surface area: ", cylinder.area(), " sq.units");
    LOG_SUCCESS("Cylinder volume (cube): ", cylinder.cube(), " cubic units");

    //! Violations
    LOG_INFO("Attempting to calculate cube for 2D shapes...");
    square.cube();    // Throws error
    rectangle.cube(); // Throws error

  } catch (const logic_error &e) {
    LOG_ERROR("Exception caught: ", e.what());
  }

  return 0;
}
