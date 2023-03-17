#include <iostream>
//#include <iomanip>
#include <string>
//#include <cstring>
#include "Cart.h"
#include "Order.h"

using namespace std;

class Buyer{
    Order order;
    Cart cart;
    double budget;

    public:
        void setBudget(int);
        int getBudget();

        //can be used in Order class
        // void placeOrder();
        // void cancelOrder();

        //can be used in Cart Class
        // void Add_to_Cart();
        // void remove_from_cart();
};