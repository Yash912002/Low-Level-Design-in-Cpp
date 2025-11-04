#include <iostream>
using namespace std;

class Calculator {
public:
  int add(int a, double b) { return a + b; }
  int add(double b, int a) { return a + b; }

  double add(double b, double a) { return a + b; }

  ~Calculator() { cout << "destructor called" << endl; }
};

int main() {
  Calculator *c = new Calculator();
  cout << c->add(3, 4.9) << endl;
  cout << c->add(3.3, 4) << endl;
  cout << c->add(3.3, 4.4) << endl;
  delete c;
  return 0;
}