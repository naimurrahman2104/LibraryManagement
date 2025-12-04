#include "BorrowRecord.hpp"

BorrowRecord::BorrowRecord(int id, string member)
    : itemId(id), memberName(member) {}

string BorrowRecord::serialize() const {
    return to_string(itemId) + "," + memberName;
}
