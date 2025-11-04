#include <iostream>
#include <vector>
using namespace std;

class Product {
public:
  double price;
  string name;

  Product(string name, double price) {
    this->price = price;
    this->name = name;
  }
};

// Violation of SRP
class ShoppingCart {
private:
  vector<Product *> products;

public:
  void addProduct(Product *p) { products.push_back(p); }

  const vector<Product *> &getAllProducts() { return products; }

  // Calculate total price
  double calculateTotal() {
    double total = 0;

    for (auto p : products) {
      total += p->price;
    }

    return total;
  }

  // Print invoice
  void printInvoice() {
    double total = calculateTotal();
    cout << "Total bill is " << total << " Rs" << endl;
  }

  // Save to database
  void saveToDB() { cout << "Saved the price to database" << endl; }
};

int main() {
  ShoppingCart *cart = new ShoppingCart();

  cart->addProduct(new Product("Book", 1200.00));
  cart->addProduct(new Product("Sun glasses", 240.40));

  double totalCheckoutPrice = cart->calculateTotal();
  cout << totalCheckoutPrice << endl;

  vector<Product *> cartProducts;
  cartProducts = cart->getAllProducts();

  for (auto p : cartProducts) {
    cout << p->name << " " << p->price << " Rs" << endl;
  }

  cart->printInvoice();
  cart->saveToDB();
  return 0;
}