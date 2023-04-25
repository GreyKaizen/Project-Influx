#include <iostream>
//#include <iomanip>
#include <string>
//#include <cstring>
#include "Invoice.h"

using namespace std;

class Payment{
    Invoice invoice;
    double total_bill;
    int transaction_ID;
    string Pay_Method;
    string Coupon, Gift_Card;
    int shipping_charges;

    public:

        //call by check_coupon,gift_card, shipping_charges
        double getTotalBill() const;//DONE
        //installments
        void setTransactionID();//DONE
        void generate_TransactionID();//DONE
        int getTransactionID() const;//DONE



        //String of the choices in the method
        //Pay_Method[] = {"EasyPaisa", "JazzCash", "Debit Card", "COD", "Installment"};
        void setPaymentMethod(string);//DONE
        void select_PaymentMethod();//DONE
        string getPaymentMethod() const;//DONE

        //no shipping charges over Rs.2000 order
        //else there would be at least Rs.400 
        //pass amount of Order Class
        void check_shipping_charges();//DONE

        //check's that data members are not NULL
        //if so then invoice can't be generated
        bool check_Payment();//DONE

        //Call for the member functions of invoice class through the invoice object of Payment Class
        
        //Call for Invoice Class print_invoice
        void generate_invoice();


        //fstream file reader's are there too check coupon and gift card
        //will reduce total_bill 
        //pass amount of Order Class
        void check_Coupon(string);
        void check_gift_card(string);
};