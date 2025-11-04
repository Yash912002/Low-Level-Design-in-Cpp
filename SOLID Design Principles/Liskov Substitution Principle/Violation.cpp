#include <iostream>
#include <vector>
using namespace std;

class Account {
public:
  virtual void deposit(double amount) = 0;
  virtual void withdraw(int amount) = 0;
};

class Savings : public Account {
private:
  double balance;

public:
  Savings() { balance = 0; }

  void deposit(double amount) {
    balance += amount;
    cout << amount << " Rs is deposited in your Savings Account." << endl;
  }

  void withdraw(int amount) {
    if (balance >= amount) {
      balance -= amount;
      cout << amount << " Rs is withdrawn from your Savings Account." << endl;
    } else {
      cout << "Insufficient balance." << endl;
      return;
    }
  }
};

class Current : public Account {
private:
  double balance;

public:
  Current() { balance = 0; }

  void deposit(double amount) {
    balance += amount;
    cout << amount << " Rs is deposited in your Current Account." << endl;
  }

  void withdraw(int amount) {
    if (balance >= amount) {
      balance -= amount;
      cout << amount << " Rs is withdrawn from your Current Account." << endl;
    } else {
      cout << "Insufficient balance." << endl;
      return;
    }
  }
};

class FixedDeposit : public Account {
private:
  double balance;

public:
  FixedDeposit() { balance = 0; }

  void deposit(double amount) {
    balance += amount;
    cout << amount << " Rs is deposited in your FixedDeposit Account." << endl;
  }

  void withdraw(int amount) {
    throw logic_error("withdrawal not allowed in Fixed Deposit Account.");
  }
};

class Client {
private:
  vector<Account *> clientAccounts;

public:
  Client(vector<Account *> accounts) { clientAccounts = accounts; }

  void processTransaction() {
    for (Account *account : clientAccounts) {
      if (typeid(*account) == typeid(FixedDeposit)) {
        account->deposit(1000);
      } else {
        account->deposit(1000);
        account->withdraw(500);
      }
    }
  }
};

int main() {
  vector<Account *> accounts;

  accounts.push_back(new Savings());
  accounts.push_back(new Current());
  accounts.push_back(new FixedDeposit());

  Client *c = new Client(accounts);
  c->processTransaction();
  return 0;
}