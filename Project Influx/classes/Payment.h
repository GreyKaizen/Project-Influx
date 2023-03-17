#include <iostream>
//#include <iomanip>
#include <string>
//#include <cstring>
#include "Invoice.h"

using namespace std;

class Payment{
    Invoice invoice;
    int total_bill;
    int transaction_ID;
    string Pay_Method;
    string Coupon, Gift_Card;

    public:
        void setTransactionID(int);
        int getTransactionID() const;
        
        void check_Coupon();

        void check_gift_card();
};