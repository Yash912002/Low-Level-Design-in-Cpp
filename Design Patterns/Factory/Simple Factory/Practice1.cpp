/*
Simple Factory :- A factory class that decides which concrete class to
instantiate.
*/
#include "../../../utils/Logger.h"
#include <bits/stdc++.h>
using namespace std;

// Product
class Burger {
public:
  virtual void prepare() const = 0;
  virtual ~Burger() = default;
};

class BasicBurger : public Burger {
public:
  void prepare() const override { LOG_SUCCESS("Basic Burger is ready."); }
};

class PremiumBurger : public Burger {
public:
  void prepare() const override { LOG_SUCCESS("Premium Burger is ready."); }
};

//* Simple Factory
class BurgerFactory {
public:
  Burger *createBurger(string type) {
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

int main() {
  BurgerFactory *burgerFactory = new BurgerFactory();

  Burger *burger1 = burgerFactory->createBurger("basic");
  burger1->prepare();

  Burger *burger2 = burgerFactory->createBurger("premium");
  burger2->prepare();

  Burger *burger3 = burgerFactory->createBurger("premi");

  delete burger1;
  delete burger2;
  delete burger3;
  delete burgerFactory;
  return 0;
}