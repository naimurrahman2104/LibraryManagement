#include "Book.hpp"

Book::Book(int id, string title, string author)
    : Item(id, title), author(author) {}

void Book::display() const {
    cout << "[Book] ID: " << id
         << " | Title: " << title
         << " | Author: " << author
         << " | Borrowed: " << (isBorrowed ? "Yes" : "No")
         << "\n";
}

string Book::serialize() const {
    return "BOOK," + to_string(id) + "," + title + "," + author + "," +
           (isBorrowed ? "1" : "0");
}
