#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

string userFolder = "users";

void registerUser() {
    cout << "\n--- User Registration ---\n";

    string username, password;
    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin.ignore();              // clear leftover newline
    getline(cin, password);    // allows spaces in password

    // Validation
    if (username.empty() || password.empty()) {
        cout << "Error: Username or password cannot be empty.\n";
        return;
    }

    // Create folder if not exists
    if (!fs::exists(userFolder)) {
        fs::create_directory(userFolder);
    }

    string filename = userFolder + "/" + username + ".txt";

    // Check for duplicate username
    if (fs::exists(filename)) {
        cout << "Error: Username already exists.\n";
        return;
    }

    // Save credentials (plain text for now)
    ofstream file(filename);
    file << password;
    file.close();

    cout << "Registration successful!\n";
}

void loginUser() {
    cout << "\n--- User Login ---\n";

    string username, password;
    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin.ignore();              // clear leftover newline
    getline(cin, password);    // allows spaces in password

    string filename = userFolder + "/" + username + ".txt";

    // Check if user exists
    if (!fs::exists(filename)) {
        cout << "Error: User does not exist.\n";
        return;
    }

    // Read stored password
    ifstream file(filename);
    string savedPassword;
    getline(file, savedPassword);
    file.close();

    if (password == savedPassword) {
        cout << "Login successful! Welcome, " << username << "!\n";
    } else {
        cout << "Error: Incorrect password.\n";
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n====== MENU ======\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}