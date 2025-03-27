#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void registerUser() {
    string username, password;
    cout << "Enter a new username: ";
    cin >> username;
    cout << "Enter a new password: ";
    cin >> password;
    ofstream file("database.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful!\n";
}
bool loginUser() {
    string username, password, u, p;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    ifstream file("database.txt");
    bool loginSuccess = false;

    while (file >> u >> p) {
        if (u == username && p == password) {
            loginSuccess = true;
            break;
        }
    }
    file.close();

    if (loginSuccess) {
        cout << "Login successful! Welcome, " << username << "!\n";
        return true;
    } else {
        cout << "Invalid username or password.\n";
        return false;
    }
}1

int main() {
    int choice;

    while (true) {
        cout << "\n1. Register\n2. Login\n3. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting the program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
