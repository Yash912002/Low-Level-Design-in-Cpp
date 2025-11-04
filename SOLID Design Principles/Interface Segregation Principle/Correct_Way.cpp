#include <cmath>
#include <iostream>

#include "../../utils/Logger.h"

using namespace std;

class TwoDimensionalShape {
public:
  virtual double area() const = 0;
  virtual ~TwoDimensionalShape() = default;
};

class ThreeDimensionalShape {
public:
  virtual double surfaceArea() const = 0;
  virtual double volume() const = 0;
  virtual ~ThreeDimensionalShape() = default;
};

class Square : public TwoDimensionalShape {
private:
  double side;

public:
  explicit Square(double s) : side(s) {};

  double area() const override { return side * side; }
};

class RectangleShape : public TwoDimensionalShape {
private:
  double length, width;

public:
  RectangleShape(double l, double w) : length(l), width(w) {};

  double area() const override { return length * width; }
};

class Cylinder : public ThreeDimensionalShape {
private:
  double radius, height;

public:
  Cylinder(double r, double h) : radius(r), height(h) {}

  // Surface area of cylinder = 2πr(h + r)
  double surfaceArea() const override {
    return 2 * M_PI * radius * (height + radius);
  }

  // Volume of cylinder = πr²h
  double volume() const override { return M_PI * radius * radius * height; }
};

int main() {
  Square square(5);
  RectangleShape rectangle(4, 6);
  Cylinder cylinder(3, 10);

  cout << fixed;
  cout.precision(2);

  LOG_SUCCESS("Square area: ", square.area(), " sq.units");
  LOG_SUCCESS("Rectangle area: ", rectangle.area(), " sq.units");
  LOG_SUCCESS("Cylinder surface area: ", cylinder.surfaceArea(), " sq.units");
  LOG_SUCCESS("Cylinder volume (cube): ", cylinder.volume(), " cubic units");

  return 0;
}
