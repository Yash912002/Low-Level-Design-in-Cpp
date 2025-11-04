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

// Wrong way
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
};

class CartInvoicePrinter {
  ShoppingCart *sc;

public:
  CartInvoicePrinter(ShoppingCart *cart) { this->sc = cart; }

  // Print invoice
  void printInvoice() {
    double total = sc->calculateTotal();
    cout << "Total bill is " << total << " Rs" << endl;
  }
};

// Violation of Open-Close principle
class CartDbStorage {
  ShoppingCart *db;

public:
  CartDbStorage(ShoppingCart *cart) { this->db = cart; }
  // Save to database
  void saveToSQL() {
    cout << "Saved the price " << db->calculateTotal() << " to SQL database."
         << endl;
  }

  void saveToMongo() {
    cout << "Saved the price " << db->calculateTotal() << " to Mongo database."
         << endl;
  }

  void saveToFile() {
    cout << "Saved the price " << db->calculateTotal() << " to file." << endl;
  }
};

int main() {
  ShoppingCart *cart = new ShoppingCart();

  // Add all products
  cart->addProduct(new Product("Book", 1200.00));
  cart->addProduct(new Product("Sun glasses", 240.40));

  // Print all the products
  vector<Product *> cartProducts;
  cartProducts = cart->getAllProducts();

  for (auto p : cartProducts) {
    cout << p->name << " " << p->price << " Rs" << endl;
  }

  // Print the total price
  double totalCheckoutPrice = cart->calculateTotal();
  cout << totalCheckoutPrice << endl;

  // Print Invoice
  CartInvoicePrinter *invoice = new CartInvoicePrinter(cart);
  invoice->printInvoice();

  // Save to database
  CartDbStorage *db = new CartDbStorage(cart);
  db->saveToSQL();
  db->saveToMongo();
  db->saveToFile();
  return 0;
}