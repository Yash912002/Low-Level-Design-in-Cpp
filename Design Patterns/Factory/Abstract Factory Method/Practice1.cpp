/*
Abstract Factory Method : Provides an interface for creating families of related
objects without specifying the concrete classes.
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

class Drinks {
public:
  virtual void prepareDrink() const = 0;
};

class ThumbsUp : public Drinks {
public:
  void prepareDrink() const override { cout << "Thumbs Up is ready" << endl; }
};

class SevenUp : public Drinks {
public:
  void prepareDrink() const override { cout << "SevenUp is ready" << endl; }
};

class CocoCola : public Drinks {
public:
  void prepareDrink() const override { cout << "CocoCola is ready" << endl; }
};

class Pepsi : public Drinks {
public:
  void prepareDrink() const override { cout << "Pepsi is ready" << endl; }
};

//* Abstract Factory Method
class BurgerFactory {
public:
  virtual Burger *createBurger(string type) const = 0;
  virtual Drinks *getDrink(string type) const = 0;
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

  Drinks *getDrink(string type) const override {
    if (type == "thumbsup") {
      return new ThumbsUp();
    } else if (type == "sevenup") {
      return new SevenUp();
    } else {
      cerr << "Invalid drink type" << endl;
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

  Drinks *getDrink(string type) const override {
    if (type == "cococola") {
      return new CocoCola();
    } else if (type == "pepsi") {
      return new Pepsi();
    } else {
      cerr << "Invalid drink type" << endl;
      return nullptr;
    }
  }
};

int main() {
  BurgerFactory *mcdonalds = new McDonalds();

  Burger *basicBurger = mcdonalds->createBurger("basic");
  basicBurger->prepare();

  Drinks *mcDonaldDrink = mcdonalds->getDrink("sevenup");
  mcDonaldDrink->prepareDrink();

  BurgerFactory *kfc = new KFC();

  Burger *premiumBurger = kfc->createBurger("premium");
  premiumBurger->prepare();

  Drinks *kfcDrink = kfc->getDrink("pepsi");
  kfcDrink->prepareDrink();

  delete basicBurger;
  delete premiumBurger;

  delete mcDonaldDrink;
  delete kfcDrink;

  delete mcdonalds;
  delete kfc;
  return 0;
}