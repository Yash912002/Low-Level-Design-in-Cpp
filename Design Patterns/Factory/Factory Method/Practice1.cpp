/*
Factory Method : It defines an interface for creating objects but allows
subclass to decide which class to instantiate.
Here McDonals/KFC decides which class to instantiate.
*/
#include <bits/stdc++.h>
using namespace std;

class Burger {
public:
  virtual void prepare() const = 0;
  virtual ~Burger() = default;
};

//* Concrete Product 1 ( Veg Burger )
class BasicBurger : public Burger {
public:
  void prepare() const override { cout << "Basic Burger is ready." << endl; }
};

class PremiumBurger : public Burger {
public:
  void prepare() const override { cout << "Premium Burger is ready." << endl; }
};

//* Concrete Product 2 ( Nonveg Burger )
class BasicNonvegBurger : public Burger {
public:
  void prepare() const override {
    cout << "Basic Nonveg Burger is ready." << endl;
  }
};

class PremiumNonvegBurger : public Burger {
public:
  void prepare() const override {
    cout << "Premium Nonveg Burger is ready." << endl;
  }
};

//* Factory Method
class BurgerFactory {
public:
  virtual Burger *createBurger(string type) const = 0;
  virtual ~BurgerFactory() = default;
};

//* Concrete Factory 1
class McDonalds : public BurgerFactory {
public:
  Burger *createBurger(string type) const override {
    if (type == "basic") {
      return new BasicBurger();
    } else if (type == "premium") {
      return new PremiumBurger();
    } else {
      cerr << "Invalid burger type" << endl;
      return nullptr;
    }
  }
};

//* Concrete Factory 2
class KFC : public BurgerFactory {
public:
  Burger *createBurger(string type) const override {
    if (type == "basic") {
      return new BasicNonvegBurger();
    } else if (type == "premium") {
      return new PremiumNonvegBurger();
    } else {
      cerr << "Invalid burger type" << endl;
      return nullptr;
    }
  }
};

int main() {
  BurgerFactory *mcdonalds = new McDonalds();

  Burger *basicBurger = mcdonalds->createBurger("basic");
  basicBurger->prepare();

  BurgerFactory *kfc = new KFC();

  Burger *premiumBurger = kfc->createBurger("premium");
  premiumBurger->prepare();

  delete basicBurger;
  delete premiumBurger;

  delete mcdonalds;
  delete kfc;
  return 0;
}