#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to register a new user
void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    if (file.is_open()) {
        file << username << " " << password << endl;
        file.close();
        cout << "Registration successful!\n";
    } else {
        cout << "Error in opening file.\n";
    }
}

// Function to login a user
bool loginUser() {
    string username, password, u, p;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    if (file.is_open()) {
        while (file >> u >> p) {
            if (u == username && p == password) {
                file.close();
                return true;
            }
        }
        file.close();
    } else {
        cout << "Error in opening file.\n";
    }
    return false;
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nChoose an option: ";
    cin >> choice;

    if (choice == 1) {
        registerUser();
    } else if (choice == 2) {
        if (loginUser()) {
            cout << "Login successful!\n";
        } else {
            cout << "Invalid credentials. Try again.\n";
        }
    } else {
        cout << "Invalid choice!\n";
    }

    return 0;
}
