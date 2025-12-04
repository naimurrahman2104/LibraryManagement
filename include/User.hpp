#ifndef USER_HPP
#define USER_HPP

#include <string>
using namespace std;

class User {
public:
    string username;
    string password;
    string role; // "admin" or "user"

    User();
    User(string u, string p, string r);

    string toLine() const;           // for saving to file
    static User fromLine(const string &line); // read from file line
};

#endif
