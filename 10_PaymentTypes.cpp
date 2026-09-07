#ifndef PAYMENTTYPES_CPP
#define PAYMENTTYPES_CPP

#include <iostream>
#include <string>
#include "09_Payment.cpp"
using namespace std;

class UpiPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "  [UPI] Rs." << amount << " paid successfully" << endl;
        return true;
    }

    string getMethodName() const override {
        return "UPI";
    }
};

class CardPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "  [CARD] Processing Rs." << amount << " ..." << endl;
        cout << "  [CARD] Rs." << amount << " paid successfully" << endl;
        return true;
    }

    string getMethodName() const override {
        return "CARD";
    }
};

class CashPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "  [CASH] Rs." << amount << " collected successfully" << endl;
        return true;
    }

    string getMethodName() const override {
        return "CASH";
    }
};

#endif
