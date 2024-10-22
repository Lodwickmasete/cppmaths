#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BankAccount {
public:
    BankAccount(string accountNumber, string name, double balance) 
        : accountNumber(accountNumber), name(name), balance(balance) {}

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful. New balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        }
    }

    void displayBalance() {
        cout << "Account balance: " << balance << endl;
    }

    string getAccountNumber() {
        return accountNumber;
    }

private:
    string accountNumber;
    string name;
    double balance;
};

int main() {
    vector<BankAccount> accounts;

    while (true) {
        cout << "\nBank Management System" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string accountNumber, name;
                double initialBalance;

                cout << "Enter account number: ";
                cin >> accountNumber;

                cout << "Enter account holder name: ";
                cin.ignore(); // Clear input buffer
                getline(cin, name);

                cout << "Enter initial balance: ";
                cin >> initialBalance;

                accounts.push_back(BankAccount(accountNumber, name, initialBalance));
                cout << "Account created successfully." << endl;
                break;
            }
            case 2: {
                string accountNumber;
                double amount;

                cout << "Enter account number: ";
                cin >> accountNumber;

                cout << "Enter deposit amount: ";
                cin >> amount;

                for (auto& account : accounts) {
                    if (account.getAccountNumber() == accountNumber) {
                        account.deposit(amount);
                        break;
                    }
                }
                break;
            }
            case 3: {
                string accountNumber;
                double amount;

                cout << "Enter account number: ";
                cin >> accountNumber;

                cout << "Enter withdrawal amount: ";
                cin >> amount;

                for (auto& account : accounts) {
                    if (account.getAccountNumber() == accountNumber) {
                        account.withdraw(amount);
                        break;
                    }
                }
                break;
            }
            case 4: {
                string accountNumber;

                cout << "Enter account number: ";
                cin >> accountNumber;

                for (const auto& account : accounts) {
                    if (account.getAccountNumber() == accountNumber) {
                        account.displayBalance();
                        break;
                    }
                }
                break;
            }
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
