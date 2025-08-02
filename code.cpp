#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool UsernameExists(string InputUsername) 
{
    ifstream file("users.txt");
    string StoredUsername, StoredPassword;

    while (file >> StoredUsername >> StoredPassword) 
    {
        if (StoredUsername == InputUsername) {
            return true;
        }
    }

    return false;
}

void RegisterUser() {
    string username, password;

    cout << "User Registration" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (username.empty() || password.empty()) 
    {
        cout << "Error: Username or password cannot be empty." << endl;
        return;
    }

    if (UsernameExists(username)) 
    {
        cout << "Error: Username already exists. Try a different one." << endl;
        return;
    }

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;

    cout << "Registration successful!" << endl;
}

void LoginUser() {
    string username, password;
    string StoredUsername, StoredPassword;
    bool LoginSuccess = false;

    cout << "User Login" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");

    while (file >> StoredUsername >> StoredPassword) {
        if (StoredUsername == username && StoredPassword == password) {
            LoginSuccess = true;
            break;
        }
    }

    if (LoginSuccess) {
        cout << "Login successful! Welcome, " << username << "." << endl;
    }
    else {
        cout << "Error: Invalid username or password." << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "======= Login & Registration System =======" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            RegisterUser();
            break;
        case 2:
            LoginUser();
            break;
        case 3:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please select 1, 2, or 3." << endl;
        }

    } while (choice != 3);

    return 0;
}
