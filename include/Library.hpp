#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <vector>
#include <memory>
#include <string>
#include "Item.hpp"
#include "BorrowRecord.hpp"
#include "CustomException.hpp"

using namespace std;

class Library {
    vector<shared_ptr<Item>> catalog;
    vector<BorrowRecord> records;

public:
    void addItem(shared_ptr<Item> item);
    void displayCatalog() const;

    void borrowItem(int id, const string &member);
    void returnItem(int id);

    void save();
    void load();
};

#endif
