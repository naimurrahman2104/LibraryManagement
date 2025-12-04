#ifndef CUSTOM_EXCEPTION_HPP
#define CUSTOM_EXCEPTION_HPP

#include <stdexcept>
using namespace std;

class ItemNotFoundException : public runtime_error {
public:
    ItemNotFoundException(const string &msg)
        : runtime_error(msg) {}
};

#endif
