#include <iostream>
#include <memory>
#include "AuthSystem.hpp"
#include "Library.hpp"
#include "Book.hpp"
#include "Magazine.hpp"

using namespace std;

int main() {
    AuthSystem auth;
    Library lib;
    lib.load(); // load catalog and borrowed records

    while (true) {
        cout << "\n=== Welcome to Library System ===\n";
        cout << "1. Signup\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        int choice;
        cin >> choice;
        cin.ignore();

        try {
            if (choice == 1) {
                string user, pass, role;
                cout << "Enter username: "; getline(cin, user);
                cout << "Enter password: "; getline(cin, pass);
                cout << "Enter role (admin/user): "; getline(cin, role);
                auth.signup(user, pass, role);
                cout << "Signup successful! You can now login.\n";
            }
            else if (choice == 2) {
                string user, pass;
                cout << "Enter username: "; getline(cin, user);
                cout << "Enter password: "; getline(cin, pass);

                User loggedIn = auth.login(user, pass);
                cout << "Login successful! Welcome, " 
                     << loggedIn.username << " (" << loggedIn.role << ")\n";

                // Role-based menu
                bool logout = false;
                while (!logout) {
                    if (loggedIn.role == "admin") {
                        cout << "\n--- Admin Menu ---\n"
                             << "1. Display catalog\n"
                             << "2. Add Book\n"
                             << "3. Add Magazine\n"
                             << "4. Save & Logout\n"
                             << "Choose: ";
                        int adminChoice;
                        cin >> adminChoice;
                        cin.ignore();

                        if (adminChoice == 1)
                            lib.displayCatalog();
                        else if (adminChoice == 2) {
                            int id; string title, author;
                            cout << "ID: "; cin >> id; cin.ignore();
                            cout << "Title: "; getline(cin, title);
                            cout << "Author: "; getline(cin, author);
                            lib.addItem(make_shared<Book>(id, title, author));
                        }
                        else if (adminChoice == 3) {
                            int id, issue; string title;
                            cout << "ID: "; cin >> id; cin.ignore();
                            cout << "Title: "; getline(cin, title);
                            cout << "Issue number: "; cin >> issue; cin.ignore();
                            lib.addItem(make_shared<Magazine>(id, title, issue));
                        }
                        else if (adminChoice == 4) {
                            lib.save();
                            logout = true;
                        }
                        else
                            cout << "Invalid option!\n";
                    }
                    else if (loggedIn.role == "user") {
                        cout << "\n--- User Menu ---\n"
                             << "1. Display catalog\n"
                             << "2. Borrow Item\n"
                             << "3. Return Item\n"
                             << "4. Save & Logout\n"
                             << "Choose: ";
                        int userChoice;
                        cin >> userChoice;
                        cin.ignore();

                        if (userChoice == 1)
                            lib.displayCatalog();
                        else if (userChoice == 2) {
                            int id; string member;
                            cout << "Item ID: "; cin >> id; cin.ignore();
                            member = loggedIn.username; // automatically use logged-in username
                            lib.borrowItem(id, member);
                        }
                        else if (userChoice == 3) {
                            int id;
                            cout << "Item ID: "; cin >> id; cin.ignore();
                            lib.returnItem(id);
                        }
                        else if (userChoice == 4) {
                            lib.save();
                            logout = true;
                        }
                        else
                            cout << "Invalid option!\n";
                    }
                    else {
                        cout << "Unknown role. Logging out.\n";
                        logout = true;
                    }
                }
            }
            else if (choice == 3) {
                cout << "Goodbye!\n";
                break;
            }
            else {
                cout << "Invalid choice!\n";
            }
        }
        catch (AuthException &e) {
            cout << "Auth error: " << e.what() << "\n";
        }
        catch (exception &e) {
            cout << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}
