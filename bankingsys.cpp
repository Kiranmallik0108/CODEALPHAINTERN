#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Account {
private:
    string accountNumber;
    string owner;
    double balance;
public:
    Account(string accNum, string own, double bal) {
        accountNumber = accNum;
        owner = own;
        balance = bal;
    }

    string getAccountNumber() { return accountNumber; }
    string getOwner() { return owner; }
    double getBalance() { return balance; }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited $" << amount << " successfully.\n";
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds!\n";
            return false;
        }
        balance -= amount;
        cout << "Withdrawn $" << amount << " successfully.\n";
        return true;
    }

    void displayAccountInfo() {
        cout << "\nAccount Number: " << accountNumber << "\nOwner: " << owner
             << "\nBalance: $" << fixed << setprecision(2) << balance << "\n";
    }
};

class Bank {
private:
    vector<Account> accounts;
public:
    void createAccount() {
        string accNum, owner;
        double balance;
        cout << "Enter Account Number: ";
        cin >> accNum;
        cout << "Enter Account Holder's Name: ";
        cin >> owner;
        cout << "Enter Initial Deposit: ";
        cin >> balance;

        accounts.push_back(Account(accNum, owner, balance));
        cout << "Account created successfully!\n";
    }

    Account* findAccount(string accNum) {
        for (auto& acc : accounts) {
            if (acc.getAccountNumber() == accNum)
                return &acc;
        }
        return nullptr;
    }

    void deposit() {
        string accNum;
        double amount;
        cout << "Enter Account Number: ";
        cin >> accNum;
        Account* acc = findAccount(accNum);
        if (acc) {
            cout << "Enter Amount to Deposit: ";
            cin >> amount;
            acc->deposit(amount);
        } else {
            cout << "Account not found!\n";
        }
    }

    void withdraw() {
        string accNum;
        double amount;
        cout << "Enter Account Number: ";
        cin >> accNum;
        Account* acc = findAccount(accNum);
        if (acc) {
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;
            acc->withdraw(amount);
        } else {
            cout << "Account not found!\n";
        }
    }

    void transfer() {
        string fromAcc, toAcc;
        double amount;
        cout << "Enter From Account Number: ";
        cin >> fromAcc;
        cout << "Enter To Account Number: ";
        cin >> toAcc;
        cout << "Enter Transfer Amount: ";
        cin >> amount;

        Account* sender = findAccount(fromAcc);
        Account* receiver = findAccount(toAcc);

        if (sender && receiver) {
            if (sender->withdraw(amount)) {
                receiver->deposit(amount);
                cout << "Transfer successful!\n";
            } else {
                cout << "Transfer failed! Insufficient funds.\n";
            }
        } else {
            cout << "One or both accounts not found!\n";
        }
    }

    void viewAccount() {
        string accNum;
        cout << "Enter Account Number: ";
        cin >> accNum;
        Account* acc = findAccount(accNum);
        if (acc) {
            acc->displayAccountInfo();
        } else {
            cout << "Account not found!\n";
        }
    }
};

int main() {
    Bank bank;
    int choice;

    while (true) {
        cout << "\n--- Banking System ---\n";
        cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. Transfer\n5. View Account\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: bank.createAccount(); break;
            case 2: bank.deposit(); break;
            case 3: bank.withdraw(); break;
            case 4: bank.transfer(); break;
            case 5: bank.viewAccount(); break;
            case 6: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }
}
