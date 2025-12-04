#include "Magazine.hpp"

Magazine::Magazine(int id, string title, int issue)
    : Item(id, title), issueNumber(issue) {}

void Magazine::display() const {
    cout << "[Magazine] ID: " << id
         << " | Title: " << title
         << " | Issue: " << issueNumber
         << " | Borrowed: " << (isBorrowed ? "Yes" : "No")
         << "\n";
}

string Magazine::serialize() const {
    return "MAGAZINE," + to_string(id) + "," + title + "," +
           to_string(issueNumber) + "," + (isBorrowed ? "1" : "0");
}
