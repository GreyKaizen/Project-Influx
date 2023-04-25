#include <iostream>
//#include <iomanip>
#include <string>
//#include <cstring>
#include "Person.h"
#include "Cart.h"
#include "Order.h"

using namespace std;

class Buyer : public Person{
    int BuyerID;
    double available_balance;
    Order order;
    Cart cart;
    
    public:
        void setBuyerID();//DONE
        int generate_buyerID();//DONE
        int get_buyerID() const;//DONE
        //void addToCart(Cart&);

        //can be used in Order class
        // void placeOrder();
        // void cancelOrder();

        //can be used in Cart Class
        // void Add_to_Cart();
        // void remove_from_cart();
};

class Guest : private Buyer{
    public:
        //register the user to system
        //and log out.
       void register_user();
       void log_out();
       void print_Register_toBuy() const;//DONE
};

class Registered_Buyer : protected Buyer{

    public:
        //OVERRIDE
        void changeINFO();
        void check_Person();//DONE
        void print_info() const;//DONE

        void setBalance(double);//DONE
        double getBalance() const;//DONE

        //Process of Placing Order Begin Here
        //Call for the Order Object Member Function
        void initiate_Order_Quick_Buy();
        //Process of Placing MULTIPLE Order Begin Here
        //(Quantity, Product_Info, Amount)
        void usingCart(int,Product,int);
        //view stored elements in cart
        //can Call print Cart function
        //Also Ask for, checkout/buy cart
        void viewCart() const;
};
