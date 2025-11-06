/*
Factory Method : It defines an interface for creating objects but allows
subclass to decide which class to instantiate.
Here McDonals/KFC decides which class to instantiate.
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
      LOG_ERROR("Invalid burger type");
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
      LOG_ERROR("Invalid burger type");
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