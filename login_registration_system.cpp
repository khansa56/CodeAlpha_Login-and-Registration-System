#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

// Function to validate username (min 3 characters, alphanumeric)
bool isValidUsername(string username) {
    if (username.length() < 3) {
        return false;
    }
    for (char c : username) {
        if (!isalnum(c) && c != '_') {
            return false;
        }
    }
    return true;
}

// Function to validate password (min 6 characters)
bool isValidPassword(string password) {
    return password.length() >= 6;
}

// Registration function with confirm password
void registerUser() {
    string username, password, confirmPassword;
    
    cout << "\n========== REGISTRATION ==========\n";
    cout << "Enter username (min 3 characters): ";
    cin >> username;
    
    // Validate username
    if (!isValidUsername(username)) {
        cout << "[ERROR] Username must be at least 3 characters and contain only letters, numbers, or underscore!\n";
        return;
    }
    
    // Check if user already exists
    string filename = username + ".txt";
    ifstream check(filename);
    if (check) {
        cout << "[ERROR] Username already exists! Please choose another.\n";
        return;
    }
    check.close();
    
    cout << "Enter password (min 6 characters): ";
    cin >> password;
    
    // Validate password
    if (!isValidPassword(password)) {
        cout << "[ERROR] Password must be at least 6 characters long!\n";
        return;
    }
    
    cout << "Confirm password: ";
    cin >> confirmPassword;
    
    // Check if passwords match
    if (password != confirmPassword) {
        cout << "[ERROR] Passwords do not match!\n";
        return;
    }
    
    // Store credentials in file
    ofstream file(filename);
    if (file.is_open()) {
        file << username << endl;
        file << password << endl;
        file.close();
        cout << "[SUCCESS] Registration successful! You can now login.\n";
    } else {
        cout << "[ERROR] Could not save user data!\n";
    }
}

// Login function
void loginUser() {
    string username, password, storedUser, storedPass;
    
    cout << "\n========== LOGIN ==========\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    
    // Read from file
    string filename = username + ".txt";
    ifstream file(filename);
    
    if (!file) {
        cout << "[ERROR] Username not found! Please register first.\n";
        return;
    }
    
    getline(file, storedUser);
    getline(file, storedPass);
    file.close();
    
    // Verify credentials
    if (storedUser == username && storedPass == password) {
        cout << "[SUCCESS] Login successful! Welcome " << username << "!\n";
    } else {
        cout << "[ERROR] Incorrect password! Please try again.\n";
    }
}

// Function to show all registered users (for admin/debugging)
void listAllUsers() {
    cout << "\n========== REGISTERED USERS ==========\n";
    system("dir *.txt /b 2>nul"); // For Windows
    // For Linux/Mac: system("ls *.txt 2>/dev/null");
}

int main() {
    int choice;
    
    cout << "\n============================================\n";
    cout << "   Code Alpha Internship - Task 2           \n";
    cout << "   Login and Registration System (C++)      \n";
    cout << "============================================\n";
    
    do {
        cout << "\n========== MAIN MENU ==========\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. View All Users (Admin)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                listAllUsers();
                break;
            case 4:
                cout << "\n[INFO] Exiting system. Thank you for using CodeAlpha Login System!\n";
                break;
            default:
                cout << "[ERROR] Invalid choice! Please enter 1-4.\n";
        }
    } while(choice != 4);
    
    return 0;
}
