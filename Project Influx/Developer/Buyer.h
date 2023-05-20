#ifndef BUYER_H
#define BUYER_H

#include <iostream>
//#include <iomanip>
#include <string>
#include <time.h>
#include <vector>
#include <ctime>
#include <cstdlib>
//#include <cstring>
#include "Person.h"
#include <fstream>
// #include "Cart.h"
// #include "Order.h"
#include "Product.h"
#include <random>
#include "FriendFunction.h"

using namespace std;

class Order;
class Payment;
// class Invoice;
class Buyer;
class Invoice
{
    int invoice_id;
    string Invoice_Type;

    public:

    /* Constructor For The Invoice */
        Invoice(){}
    /* Setter Function For The Invoice Type */
        void setInvoiceID();//DONE
        void setInvoiceType(string);//DONE

        /* Getter Function For The Invoice Type */

        int getInvoiceID() const;//DONE
        string getInvoiceType() const;//DONE
        // void getReturnDate() const;//DONE
    
        /* Main Function Definition For The Main */

        int generate_invoiceID();//DONE
        void generate_ReturnDate(); //done

        void GenerateInvoiceType();     //Done


        //First Check for the Status of the Payment if Done by the other than Cash ON Deleivery choice then user would have following options
        //BusinessInvoice(Bulk Buy),NormalInvoice, InternationalInvoice
        //Call generate_invoiceID,returnDate,invoiceType

        // friend void generate_invoice(const Buyer&,const Order&, Payment&,const vector <Cart>);

        friend void print_Invoice(const Buyer&,const Order&,const Payment&, vector <Cart>&, Invoice&);//DONE but NEED UI
        // void Invoice_INFO(const Buyer&,const Order&,const Payment&,vector<Cart>&);

};

class Payment{
    int transaction_ID;
    string Pay_Method;
    int shipping_charges;
    double total_bill;
    public:
    Invoice invoice;
    /* Constructor For The Class Payment Class */
        // Payment() {};
    // Payment():invoice(){}
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

        friend void generate_invoice(const Buyer&,const Order&, Payment&, vector <Cart>);

        // friend void print_Invoice(const Buyer&,const Order&,const Payment&,const vector <Cart>&,Invoice&);
};

class Order{
        //Dont' Need Complete Info of the Product
        //Will Use the Approach of Pass as a Parameter
        //To a Method of the Class
        string OrderId;
        double Amount;
        string ShippingDetails;
        //fstream file_update_inventory;
        // Cart cart;
    public:
        Payment payment;
        Order():payment(){}
        /* Setter Functions */
        void setOrderId(); //DONE
        // void setQuantity(int);  //done
        void setAmount(const vector<Cart>&);    //done
        void setShippingDetails(); //done
        /* Getter Functions */

        Payment getPayment();
        string getOrderId() const;  
        double getAmount();  
        string getShippingDetails() const;  //done
        
        /* Main Functicppons */

        //First 5 Letter would be string i.e
        //PES101-1234567.
        string generate_random_word();  //done
        /* The Upper Function is just Used in The Below Function */
        string generate_OrderID();    
        
        //can be used in Order class
        //Would Initiate Payment Gateway and Invoice
        //Call for the payment object and then selectPaymentMethod, shippingCharges, check_copuon and gift_card.CHECKOUT
        void cancelOrder();

        // //Then Payment Object will call the invoice
        // friend void initiate_Order_Quick_Buy(Buyer& buyer, vector<Cart>& cart);

        friend void placeOrder(Buyer& ,vector<Cart>&,Order&, Payment&);

        friend void Check_Out(Buyer&, vector<Cart>&, Order&, Payment&);// When The product file is created then this fucntion will work
        // void Buyer_INFO(const Buyer&,const Order&, vector<Cart>&);

        // friend void generate_invoice(const Buyer&,const Order&, Payment&,const vector <Cart>);

        // friend void print_Invoice(const Buyer&,const Order&,const Payment&,const vector <Cart>&,Invoice&);
};

class Buyer : public Person{
    protected:
        string BuyerID;
        double available_balance;
        Order order;
        // Cart cart;
        //static string user_files[4];
    
    public:
        Buyer(): order(){}
        
        void setBuyerID(string);
        //void addToCart(Cart&);
        string get_buyerID() const;
        //Set and Get for Balance
        void setBalance(double);//DONE
        double getBalance() const;//DONE

        void editINFO();//DONE, with a NOTE CERTAIN THINGS CAN'T BE CHANGED

        //for Overriding
        virtual void print_info() const;//DONE
        virtual string check_Person() const;//DONE

        void setCart(vector<Product>&);

        //can be used in Order class
        // void placeOrder();
        // void cancelOrder();

        //can be used in Cart Class
        // void Add_to_Cart();
        // void remove_from_cart();


        //Process of Placing MULTIPLE Order Begin Here
        //(Quantity, Product_Info, Amount)
        //void usingCart(int,Product,int);
        //view stored elements in cart
        //can Call print Cart function
        //Also Ask for, checkout/buy cart
        void viewCart(vector<Product>&) const;//DONE

        virtual void write(); //DONE

        //Call for the Order Object Member Function
        friend void initiate_Order_Quick_Buy(Buyer&, vector<Cart>&);

        friend vector<string> split( string& str, char delimiter);

        // friend void Check_Out(Buyer&, vector<Cart>&, Order&, Payment&);

        // friend void placeOrder(Buyer& ,vector<Cart>&,Order&, Payment&);

        // friend void generate_invoice(const Buyer&,const Order&, Payment&,const vector <Cart>);

        // friend void print_Invoice(const Buyer&,const Order&,const Payment&,const vector <Cart>&, Invoice&);
};

class Standard_Buyer : public Buyer{
    public:
        void setBuyerID_std();//DONE
        string generate_buyerID_std();//DONE
        
        void print_info() const ; //DONE
        string check_Person() const ;//DONE

        //Write To File Info
        void write();//DONE
        //Process of Placing Order Begin Here

        //Overloading Here
        friend istream&  operator>>(istream& is,Standard_Buyer& buyer);//DONE
        friend ostream&  operator<<(ostream& os, const Standard_Buyer& buyer);//DONE
};

class EliteBuyer : public Buyer{
    double monthly_subscription;
    
    public:
        void setBuyerID_elt();//DONE
        string generate_buyerID_elt();

        void setMonthlySubsciption(double);//DONE
        double getMonthlySubsciption() const;//DONE

    //Write To File Info
        void write();//DONE

    //Override Function, with their own implementation
        void print_info() const; //DONE
    string check_Person() const;//DONE

    //Overloading Here
        friend istream&  operator>>(istream& is,EliteBuyer& buyer);//DONE
        friend ostream&  operator<<(ostream& os, const EliteBuyer& buyer);//DONE
};



 




#endif
