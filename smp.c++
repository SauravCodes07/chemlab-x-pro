#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <iomanip>

using namespace std;

// Function to get current timestamp
string getCurrentTime() {
    time_t now = time(0);
    char* dt = ctime(&now);
    return string(dt);
}

// Function to display last 5 transactions
void displayLastFive(vector<string>& transactions) {
    cout << "\n--- Last 5 Transactions ---\n";
    int start = max(0, (int)transactions.size() - 5);

    for (int i = start; i < transactions.size(); i++) {
        cout << transactions[i] << endl;
    }

    if (transactions.empty()) {
        cout << "No transactions available.\n";
    }
}

// Function to save mini statement to file
void saveToFile(vector<string>& transactions) {
    ofstream file("mini_statement.txt", ios::app);

    file << "\n--- Mini Statement ---\n";
    file << "Generated on: " << getCurrentTime();

    int start = max(0, (int)transactions.size() - 5);

    for (int i = start; i < transactions.size(); i++) {
        file << transactions[i] << endl;
    }

    file << "----------------------\n";

    file.close();

    cout << "Mini statement saved to file successfully!\n";
}

int main() {
    vector<string> transactions;
    int choice;

    do {
        cout << "\n===== Mini Statement Generator =====\n";
        cout << "1. Add Transaction\n";
        cout << "2. View Last 5 Transactions\n";
        cout << "3. Generate Mini Statement (Save to File)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // clear input buffer

        if (choice == 1) {
            string transaction;
            cout << "Enter transaction detail: ";
            getline(cin, transaction);

            string timeStamp = getCurrentTime();
            transactions.push_back(transaction + " | " + timeStamp);

            cout << "Transaction added successfully!\n";
        }
        else if (choice == 2) {
            displayLastFive(transactions);
        }
        else if (choice == 3) {
            saveToFile(transactions);
        }
        else if (choice == 4) {
            cout << "Exiting program...\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}