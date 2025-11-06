/*
Abstract Factory Method : Provides an interface for creating families of related
objects without specifying the concrete classes.
*/

#include "../../../utils/Logger.h"
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
  void prepare() const override { LOG_SUCCESS("Basic Burger is ready."); }
};

class PremiumBurger : public Burger {
public:
  void prepare() const override { LOG_SUCCESS("Premium Burger is ready."); }
};

//* Concrete Product 2 ( Nonveg Burger )
class BasicNonvegBurger : public Burger {
public:
  void prepare() const override {
    LOG_SUCCESS("Basic Nonveg Burger is ready.");
  }
};

class PremiumNonvegBurger : public Burger {
public:
  void prepare() const override {
    LOG_SUCCESS("Premium Nonveg Burger is ready.");
  }
};

class Drinks {
public:
  virtual void prepareDrink() const = 0;
};

class ThumbsUp : public Drinks {
public:
  void prepareDrink() const override { LOG_SUCCESS("Thumbs Up is ready"); }
};

class SevenUp : public Drinks {
public:
  void prepareDrink() const override { LOG_SUCCESS("SevenUp is ready"); }
};

class CocoCola : public Drinks {
public:
  void prepareDrink() const override { LOG_SUCCESS("CocoCola is ready"); }
};

class Pepsi : public Drinks {
public:
  void prepareDrink() const override { LOG_SUCCESS("Pepsi is ready"); }
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
      LOG_ERROR("Invalid burger type");
      return nullptr;
    }
  }
  
  Drinks *getDrink(string type) const override {
    if (type == "thumbsup") {
      return new ThumbsUp();
    } else if (type == "sevenup") {
      return new SevenUp();
    } else {
      LOG_ERROR("Invalid drink type");
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
      LOG_ERROR("Invalid Burger type");;
      return nullptr;
    }
  }

  Drinks *getDrink(string type) const override {
    if (type == "cococola") {
      return new CocoCola();
    } else if (type == "pepsi") {
      return new Pepsi();
    } else {
      LOG_ERROR("Invalid drink type");
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