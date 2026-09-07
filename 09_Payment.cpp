#ifndef PAYMENT_CPP
#define PAYMENT_CPP

#include <string>
using namespace std;

// Payment (abstract): the payment CONTRACT only.
// Abstraction: pure virtual pay() - every subclass must implement it.
// Must NOT know about Booking, seats, or prices - only an amount.
class Payment {
public:
    virtual bool pay(double amount) = 0;
    virtual string getMethodName() const = 0;
    virtual ~Payment() {}
};

#endif
