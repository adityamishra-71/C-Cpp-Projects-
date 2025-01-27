#include <iostream>
#include <string>
#include <iomanip>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>

using namespace std;

class Account {
private:
    string accountNumber;
    string accountHolderName;
    double balance;
    bool isSavingsAccount;
    double savingsInterestRate;

public:
    // Constructor
    Account() : balance(0.0), isSavingsAccount(false), savingsInterestRate(0.0) {}

    // Create a new account
    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        cout << "Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, accountHolderName);
        cout << "Enter Initial Balance: ";
        cin >> balance;
        cout << "Is this a Savings Account? (1 for Yes, 0 for No): ";
        cin >> isSavingsAccount;

        if (isSavingsAccount) {
            cout << "Enter Savings Interest Rate (%): ";
            cin >> savingsInterestRate;
        } else {
            savingsInterestRate = 0.0;
        }

        try {
            sql::Driver *driver;
            sql::Connection *con;
            sql::PreparedStatement *pstmt;

            driver = get_driver_instance();
            con = driver->connect("tcp://127.0.0.1:3306", "username", "password"); // Replace with your credentials
            con->setSchema("banking_db");

            pstmt = con->prepareStatement("INSERT INTO accounts (accountNumber, accountHolderName, balance, isSavingsAccount, savingsInterestRate) VALUES (?, ?, ?, ?, ?)");
            pstmt->setString(1, accountNumber);
            pstmt->setString(2, accountHolderName);
            pstmt->setDouble(3, balance);
            pstmt->setBoolean(4, isSavingsAccount);
            pstmt->setDouble(5, savingsInterestRate);
            pstmt->executeUpdate();

            cout << "\nAccount Created Successfully!\n";

            delete pstmt;
            delete con;
        } catch (sql::SQLException &e) {
            cout << "Error occurred: " << e.what() << endl;
        }
    }

    // Display account details
    void displayAccount(const string &accNum) {
        try {
            sql::Driver *driver;
            sql::Connection *con;
            sql::PreparedStatement *pstmt;
            sql::ResultSet *res;

            driver = get_driver_instance();
            con = driver->connect("tcp://127.0.0.1:3306", "username", "password"); // Replace with your credentials
            con->setSchema("banking_db");

            pstmt = con->prepareStatement("SELECT * FROM accounts WHERE accountNumber = ?");
            pstmt->setString(1, accNum);
            res = pstmt->executeQuery();

            if (res->next()) {
                cout << "Account Number: " << res->getString("accountNumber") << endl;
                cout << "Account Holder Name: " << res->getString("accountHolderName") << endl;
                cout << "Balance: $" << fixed << setprecision(2) << res->getDouble("balance") << endl;
                if (res->getBoolean("isSavingsAccount")) {
                    cout << "Account Type: Savings Account" << endl;
                    cout << "Savings Interest Rate: " << res->getDouble("savingsInterestRate") << "%" << endl;
                } else {
                    cout << "Account Type: Regular Account" << endl;
                }
            } else {
                cout << "Account not found!\n";
            }

            delete res;
            delete pstmt;
            delete con;
        } catch (sql::SQLException &e) {
            cout << "Error occurred: " << e.what() << endl;
        }
    }

    // Update account balance
    void updateAccount(const string &accNum, bool depositFlag, double amount) {
        try {
            sql::Driver *driver;
            sql::Connection *con;
            sql::PreparedStatement *pstmt;
            sql::ResultSet *res;

            driver = get_driver_instance();
            con = driver->connect("tcp://127.0.0.1:3306", "username", "password"); // Replace with your credentials
            con->setSchema("banking_db");

            pstmt = con->prepareStatement("SELECT balance FROM accounts WHERE accountNumber = ?");
            pstmt->setString(1, accNum);
            res = pstmt->executeQuery();

            if (res->next()) {
                double currentBalance = res->getDouble("balance");

                if (depositFlag) {
                    currentBalance += amount;
                } else {
                    if (currentBalance >= amount) {
                        currentBalance -= amount;
                    } else {
                        cout << "Insufficient balance!\n";
                        return;
                    }
                }

                pstmt = con->prepareStatement("UPDATE accounts SET balance = ? WHERE accountNumber = ?");
                pstmt->setDouble(1, currentBalance);
                pstmt->setString(2, accNum);
                pstmt->executeUpdate();

                cout << "\nAccount Updated!\n";
            } else {
                cout << "Account not found!\n";
            }

            delete res;
            delete pstmt;
            delete con;
        } catch (sql::SQLException &e) {
            cout << "Error occurred: " << e.what() << endl;
        }
    }

    // Delete an account
    void deleteAccount(const string &accNum) {
        try {
            sql::Driver *driver;
            sql::Connection *con;
            sql::PreparedStatement *pstmt;

            driver = get_driver_instance();
            con = driver->connect("tcp://127.0.0.1:3306", "username", "password"); // Replace with your credentials
            con->setSchema("banking_db");

            pstmt = con->prepareStatement("DELETE FROM accounts WHERE accountNumber = ?");
            pstmt->setString(1, accNum);
            pstmt->executeUpdate();

            cout << "Account Deleted Successfully!\n";

            delete pstmt;
            delete con;
        } catch (sql::SQLException &e) {
            cout << "Error occurred: " << e.what() << endl;
        }
    }

    // Calculate simple interest
    double calculateSimpleInterest(double principal, double rate, double time) {
        return (principal * rate * time) / 100;
    }

    // Calculate compound interest
    double calculateCompoundInterest(double principal, double rate, double time) {
        return principal * pow((1 + rate / 100), time) - principal;
    }
};

int main() {
    Account account;
    int choice;

    do {
        cout << "\nOnline Banking System\n";
        cout << "1. Create Account\n";
        cout << "2. Display Account\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Delete Account\n";
        cout << "6. Calculate Simple Interest\n";
        cout << "7. Calculate Compound Interest\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string accNum;
        double amount, rate, time;

        switch (choice) {
            case 1:
                account.createAccount();
                break;
            case 2:
                cout << "Enter Account Number: ";
                cin >> accNum;
                account.displayAccount(accNum);
                break;
            case 3:
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Deposit Amount: ";
                cin >> amount;
                account.updateAccount(accNum, true, amount);
                break;
            case 4:
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Withdrawal Amount: ";
                cin >> amount;
                account.updateAccount(accNum, false, amount);
                break;
            case 5:
                cout << "Enter Account Number: ";
                cin >> accNum;
                account.deleteAccount(accNum);
                break;
            case 6:
                cout << "Enter Principal Amount: ";
                cin >> amount;
                cout << "Enter Rate of Interest: ";
                cin >> rate;
                cout << "Enter Time (in years): ";
                cin >> time;
                cout << "Simple Interest: $" << account.calculateSimpleInterest(amount, rate, time) << endl;
                break;
            case 7:
                cout << "Enter Principal Amount: ";
                cin >> amount;
                cout << "Enter Rate of Interest: ";
                cin >> rate;
                cout << "Enter Time (in years): ";
                cin >> time;
                cout << "Compound Interest: $" << account.calculateCompoundInterest(amount, rate, time) << endl;
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
