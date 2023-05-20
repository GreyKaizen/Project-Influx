#ifndef PAYMENT_H
#define PAYMENT_H

#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include "Buyer.h"
#include "Invoice.h"
#include "Product.h"


using namespace std;


class Buyer;

class Payment{
    int transaction_ID;
    string Pay_Method;
    int shipping_charges;
    double total_bill;
    string BuyerType;

    public:
    Invoice invoice;
    /* Constructor For The Class Payment Class */
        // Payment() {};
    Payment(): invoice(){}
    /* Declarations OF Setter Function For The Payment Class */

        Invoice getInvoice();
        //void setCoupen(int); //done
        //void setGiftcard(int);   //done
        void setShipcharge(string);    //done
        void setTransactionID();    //DONE
        void setTotalBill(double);  //done
        void setPaymentMethod(string);//DONE
        
        /* The Below Two Functions Will Call the Check coupon 
        and check gift card functions to check the coupon and gift cards 
        and then it will set it values */
        // string set_check_coupon(string coupon);
        void set_check_giftcard(string coupon);
        
        /* Declaration of The Getter Functions */
        // int getcoupen(); 
        // int getgiftcard();
        int getShippingCharges()const;
        double getTotalBill() const;//DONE
        //installments
        int generate_TransactionID();//DONE
        int getTransactionID() const;//DONE

        /* Declaration For The Class Of Payment Setter Function */

        //String of the choices in the method
        //Pay_Method[] = {"EasyPaisa", "JazzCash", "Debit Card", "COD", "Installment"};
        void select_PaymentMethod();//DONE
        string getPaymentMethod() const;//DONE

        //no shipping charges over Rs.2000 order
        //else there would be at least Rs.400 
        //pass amount of Order Class
        //void check_shipping_charges();//DONE

        //check's that data members are not NULL
        //if so then invoice can't be generated
        bool check_Payment();//DONE

        //Call for the member functions of invoice class through the invoice object of Payment Class
        
        //Call for Invoice Class print_invoice


        //fstream file reader's are there too check coupon and gift card
        //will reduce total_bill 
        //pass amount of Order Class
        int check_Coupon(string); // done
        int check_gift_card(string);  //done
        //void setPayMethod();
        void ApplyDiscount();
        // void Order_info(const Buyer&,const Order&,vector<Cart>&);

        // friend void initiate_Order_Quick_Buy(Buyer& buyer, vector<Cart>& cart);
        
        // friend void Check_Out(Buyer&, vector<Cart>&, Order&, Payment&);

        // friend void placeOrder(Buyer& ,vector<Cart>&,Order&, Payment&);

        friend void generate_invoice(const Buyer&,const Order&, Payment&,const vector <Cart>);

        // friend void print_Invoice(const Buyer&,const Order&,const Payment&,const vector <Cart>&,Invoice&);
}; 

#endif