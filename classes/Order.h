#include <iostream>
//#include <iomanip>
#include <string>
//#include <cstring>
#include "Payment.h"
#include "Product.h"
#include <fstream>

using namespace std;

class Order{
    Payment payment;
    //Dont' Need Complete Info of the Product
    //Will Use the Approach of Pass as a Parameter
    //To a Method of the Class
    //Product product[];
    int OrderId, Quantity, Amount;
    string ShippingDetails;
    fstream file_update_inventory;

    public:

        void setShippingDetails(string);
        string getShippingDetails() const;

        void setQuantity(int);
        void getQuantity();

        int getAmount() const;
        //First 5 Letter would be string i.e
        //PES101-1234567.
        void generate_OrderID();
        
        //void orderNow();
        //Quick Buy Now
        //(Quantity, Product_Info, Amount)
        void quickBuyNow(int,Product,int);
        //Cart Order
        //No Use of Quantity data member
        void cartOrder(Cart);

        //can be used in Order class
        //Would Initiate Payment Gateway and Invoice
        //Call for the payment object and then selectPaymentMethod, shippingCharges, check_copuon and gift_card.CHECKOUT
        //Then Payment Object will call the invoice
        void placeOrder();
        void cancelOrder();

}