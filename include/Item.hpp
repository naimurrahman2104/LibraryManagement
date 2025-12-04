#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <iostream>
using namespace std;

class Item {
protected:
    int id;
    string title;
    bool isBorrowed;

public:
    Item(int id, string title) : id(id), title(title), isBorrowed(false) {}
    virtual ~Item() {}

    int getId() const { return id; }
    string getTitle() const { return title; }
    bool getBorrowedStatus() const { return isBorrowed; }
    void setBorrowedStatus(bool s) { isBorrowed = s; }

    virtual string serialize() const = 0;
    virtual void display() const = 0;
};

#endif
