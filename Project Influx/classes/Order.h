#include <iostream>
//#include <iomanip>
#include <string>
//#include <cstring>
#include "Payment.h"
#include "Product.h"

using namespace std;

class Order{
    Payment payment;
    Product product;
    int OrderId;
    int Quantity;
    string ShippingDetails;

    public:
        // setQuantity(int q) { Quantity = q; }
        // getQuantity() { return Quantity;}

        //can be used in Order class
        void placeOrder();
        void cancelOrder();
}