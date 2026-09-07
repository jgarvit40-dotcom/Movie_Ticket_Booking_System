#ifndef CUSTOMER_CPP
#define CUSTOMER_CPP

#include <string>
using namespace std;

class Customer {
private:
    string customerName;
    string customerPhone;

public:
    Customer(string name, string phone)
        : customerName(name), customerPhone(phone) {}

    string getName() const {
        return customerName;
    }

    string getPhone() const {
        return customerPhone;
    }
};

#endif
