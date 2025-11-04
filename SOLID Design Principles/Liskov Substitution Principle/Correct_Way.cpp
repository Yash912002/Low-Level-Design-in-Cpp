#include <iostream>
#include <vector>
using namespace std;

class DepositOnlyAccount {
public:
  DepositOnlyAccount() {};
  virtual void deposit(int amount) = 0;
};

class WithdrawableAccount : public DepositOnlyAccount {
public:
  WithdrawableAccount() {};
  virtual void withdraw(int amount) = 0;
};

class SavingsAccount : public WithdrawableAccount {
private:
  int balance;

public:
  SavingsAccount() { balance = 0; }

  void deposit(int amount) override {
    balance += amount;
    cout << "Current balance is " << balance << endl;
  }

  void withdraw(int amount) override {
    if (balance >= amount) {
      balance -= amount;
      cout << "Amount after withdraw is " << balance << endl;
    } else {
      cout << "Insufficient balance" << endl;
    }
  }
};

class FDAccount : public DepositOnlyAccount {
private:
  int balance;

public:
  FDAccount() { balance = 0; }

  void deposit(int amount) {
    balance += amount;
    cout << "Current balance is " << balance << endl;
  }
};

class Client {
private:
  vector<WithdrawableAccount *> withdrawableAccount;
  vector<DepositOnlyAccount *> depositOnlyAccount;

public:
  Client(vector<WithdrawableAccount *> withdrawableAccount,
         vector<DepositOnlyAccount *> depositOnlyAccount) {
    this->withdrawableAccount = withdrawableAccount;
    this->depositOnlyAccount = depositOnlyAccount;
  }

  void processTransaction() {
    for (WithdrawableAccount *account : withdrawableAccount) {
      account->deposit(500);
      account->withdraw(100);
    }

    for (DepositOnlyAccount *account : depositOnlyAccount) {
      account->deposit(5000);
    }
  }
};

int main() {
  vector<WithdrawableAccount *> withdrawableAccount;
  withdrawableAccount.push_back(new SavingsAccount());

  vector<DepositOnlyAccount *> depositOnlyAccount;
  depositOnlyAccount.push_back(new FDAccount());

  Client *newClient = new Client(withdrawableAccount, depositOnlyAccount);
  newClient->processTransaction();

  delete newClient;
  return 0;
}