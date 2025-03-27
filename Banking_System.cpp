#include <iostream>
#include <vector>
using namespace std;

class Account {
public:
    string accountNumber;
    double balance;

    Account(string accNum, double bal) : accountNumber(accNum), balance(bal) {}
    void deposit(double amount) { balance += amount; }
    bool withdraw(double amount) { if (amount > balance) return false; balance -= amount; return true; }
};

class Customer {
public:
    string name;
    string customerId;
    vector<Account> accounts;

    Customer(string n, string id) : name(n), customerId(id) {}
    void addAccount(string accNum, double initialBalance) { accounts.push_back(Account(accNum, initialBalance)); }
    Account* getAccount(string accNum) { for (auto &acc : accounts) if (acc.accountNumber == accNum) return &acc; return nullptr; }
};

class Bank {
public:
    vector<Customer> customers;
    void addCustomer(string name, string id) { customers.push_back(Customer(name, id)); }
    Customer* getCustomer(string id) { for (auto &cust : customers) if (cust.customerId == id) return &cust; return nullptr; }
};

int main() {
    Bank bank;
    int choice;
    while (true) {
        cout << "\n1. Add Customer\n2. Add Account\n3. Deposit\n4. Withdraw\n5. View Balance\n6. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name, id;
            cout << "Enter Customer Name: ";
            cin >> name;
            cout << "Enter Customer ID: ";
            cin >> id;
            bank.addCustomer(name, id);
        } else if (choice == 2) {
            string id, accNum;
            double initialBalance;
            cout << "Enter Customer ID: ";
            cin >> id;
            Customer* customer = bank.getCustomer(id);
            if (customer) {
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Initial Balance: ";
                cin >> initialBalance;
                customer->addAccount(accNum, initialBalance);
            } else {
                cout << "Customer not found!" << endl;
            }
        } else if (choice == 3) {
            string id, accNum;
            double amount;
            cout << "Enter Customer ID: ";
            cin >> id;
            Customer* customer = bank.getCustomer(id);
            if (customer) {
                cout << "Enter Account Number: ";
                cin >> accNum;
                Account* account = customer->getAccount(accNum);
                if (account) {
                    cout << "Enter Deposit Amount: ";
                    cin >> amount;
                    account->deposit(amount);
                } else {
                    cout << "Account not found!" << endl;
                }
            } else {
                cout << "Customer not found!" << endl;
            }
        } else if (choice == 4) {
            string id, accNum;
            double amount;
            cout << "Enter Customer ID: ";
            cin >> id;
            Customer* customer = bank.getCustomer(id);
            if (customer) {
                cout << "Enter Account Number: ";
                cin >> accNum;
                Account* account = customer->getAccount(accNum);
                if (account) {
                    cout << "Enter Withdrawal Amount: ";
                    cin >> amount;
                    if (!account->withdraw(amount)) {
                        cout << "Insufficient funds!" << endl;
                    }
                } else {
                    cout << "Account not found!" << endl;
                }
            } else {
                cout << "Customer not found!" << endl;
            }
        } else if (choice == 5) {
            string id, accNum;
            cout << "Enter Customer ID: ";
            cin >> id;
            Customer* customer = bank.getCustomer(id);
            if (customer) {
                cout << "Enter Account Number: ";
                cin >> accNum;
                Account* account = customer->getAccount(accNum);
                if (account) {
                    cout << "Current Balance: " << account->balance << endl;
                } else {
                    cout << "Account not found!" << endl;
                }
            } else {
                cout << "Customer not found!" << endl;
            }
        } else if (choice == 6) {
            break;
        } else {
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}