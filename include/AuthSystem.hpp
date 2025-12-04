#ifndef AUTHSYSTEM_HPP
#define AUTHSYSTEM_HPP

#include "User.hpp"
#include <vector>
using namespace std;

class AuthSystem {
private:
    vector<User> users;
    string filename;

    void loadUsers();
    void saveUsers();

public:
    AuthSystem(string file = "data/users.txt");

    bool signup(const string &username, const string &password, const string &role);
    User login(const string &username, const string &password);
};

class AuthException : public exception {
    string message;
public:
    AuthException(const string &msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

#endif
