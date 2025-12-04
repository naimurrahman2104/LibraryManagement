#include "AuthSystem.hpp"
#include <fstream>
#include <iostream>

AuthSystem::AuthSystem(string file) {
    filename = file;
    loadUsers();
}

void AuthSystem::loadUsers() {
    users.clear();
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        users.push_back(User::fromLine(line));
    }
}

void AuthSystem::saveUsers() {
    ofstream file(filename);
    for (auto &u : users) {
        file << u.toLine() << "\n";
    }
}

bool AuthSystem::signup(const string &username, const string &password, const string &role) {
    for (auto &u : users) {
        if (u.username == username)
            throw AuthException("Username already exists!");
    }
    User newUser(username, password, role);
    users.push_back(newUser);
    saveUsers();
    return true;
}

User AuthSystem::login(const string &username, const string &password) {
    for (auto &u : users) {
        if (u.username == username && u.password == password)
            return u;
    }
    throw AuthException("Invalid username or password!");
}
