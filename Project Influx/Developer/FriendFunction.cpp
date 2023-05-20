// #include "Buyer.h"
// #include "Admin.h"
// #include "Inventory.h"
// #include "Product.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include "FriendFunction.h"

// #include "Order.h"
// #include "Payment.h"
// #include "Invoice.h"
// #include "Product.h"

using namespace std;

vector<string> split( string& str, char delimiter) {
    //tokens => FullLine
    //token  => partOfLine
    //delimiter => Vantage Point

    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// void print_Invoice(const Buyer& buyer,const Order& order,const Payment& payment,const vector <Cart>& cart, Invoice& invoice) {

//     string file_name = buyer.get_buyerID();
//     string File_Location = "Invoice/" + file_name;
//     fstream write(File_Location, ios::app);
//     /* Buyer Data */
//     cout << "Buyer ID : " << buyer.get_buyerID() << endl;
//     cout << "Buyer Name : " << buyer.getName() << endl;
//     cout << "Phone Number : " << buyer.getPhoneNumber() << endl;
//     /* Check Person if the person is elite or stander*/


//     /* End OF Buyer Data */

//     /* Order Data */

//     cout << "Order ID : " << order.getOrderId() << endl;
//     cout << "Shipping Detail : " << order.getShippingDetails() <<endl;

//     /* End of Order Detail */

//     /* Payment Data */

//     cout << "Transaction ID : " << payment.getTransactionID() << endl;
//     cout << "Payment Detail : " << payment.getPaymentMethod() << endl; 
//     cout << "Shipping Charge : " << payment.getShippingCharges() << endl;
//     cout << "Total Bill :  " << payment.getTotalBill() << endl;

//     /* End OF The Payment Detail */
    
//     /* Invoid Detail */
//     cout << "Invoice ID : " << invoice.getInvoiceID() << endl;
//     cout << "Invoice Type : " << invoice.getInvoiceType() << endl;
    
//     invoice.generate_ReturnDate();

//     write <<"==================================="<<endl;
//     write <<"|\tBuyer ID : " << buyer.get_buyerID() << "\t|\n";
//     write <<"|\tBuyer Name : " << buyer.getName() << "\t|\n";
//     write <<"|\tPhone Number : " << buyer.getPhoneNumber() <<"\t|\n" << endl;
    
//     write << "|\tOrder ID : " << order.getOrderId() << "\t|\n";
//     write << "|\tShipping Detail : " << order.getShippingDetails() <<"\t|\n";
//     write << "|\tTransaction ID : " << payment.getTransactionID() <<"\t|\n";
//     write << "|\tPayment Detail : " << payment.getPaymentMethod() <<"\t|\n"; 
//     write << "|\tShipping Charge : " << payment.getShippingCharges() <<"\t|\n";
//     write << "|\tTotal Bill :  " << payment.getTotalBill() <<"\t|\n";
//     write << "|\tInvoice ID : " << invoice.getInvoiceID() <<"\t|\n";
//     write << "|\tInvoice Type : " << invoice.getInvoiceType() <<"\t|\n";
//     // write << getReturnDate() <<"\t|\n";

// }

// void generate_invoice(const Buyer& buyer,const Order& order, Payment& payment,const vector <Cart> cart){
// //     //Will use the object invoice to create a Invoice
// //     //Calls the member Function check_Payement and check that payment is set properly
// //     //check_shipping_charges function will also be used, check the header file for logic adn explanation
// //     check_Payment();
// //     check_shipping_charges();
//     // Invoice& invoice_temp = payment.getInvoice();
//     payment.invoice.setInvoiceID();
//     payment.invoice.GenerateInvoiceType();
//     payment.invoice.generate_ReturnDate();
//     print_Invoice(buyer,order,payment,cart,payment.invoice);


//     // char choixe;
//     // cout << "Do You Want To Print The Invoice " <<endl;
//     // cin>>choixe;
//     // if (choixe == 'y' || choixe == 'Y')
//     // {
//     //     return;
//     // }
//     // else
//     // {
//     //     return;
//     // }

// }
 
// void Check_Out(Buyer& buyer, vector<Cart>& cart, Order& order, Payment& payment)
// {
//     payment.setTotalBill(order.getAmount());
//     payment.setTransactionID();
//     payment.select_PaymentMethod();
//     payment.ApplyDiscount();
//     payment.setShipcharge(buyer.get_buyerID());
//     generate_invoice(buyer,order,payment,cart);
// }

// void placeOrder(Buyer& buyer, vector<Cart>& cart, Order& order, Payment& payment)
// {
//     order.setOrderId();
//     order.setShippingDetails();
//     order.setAmount(cart);

//     char choice;
//     cout << "Do You want to Checkout ?" << endl;
//     cout << "[Y] YES\t [N] NO" << endl;
//     cin >> choice;

//     if(choice == 'y' || choice == 'Y'){
//         Check_Out(buyer,cart,order,payment);
//     }
//     else if (choice == 'n' || choice == 'N')
//     {
//         order.cancelOrder();
//         return;
//     }
//     // // quickBuyNow();
//     // string detail;
//     // cout<<"Your Order is Successfully Created"<<endl;
//     // Payment pay;
//     // pay.select_PaymentMethod();

//     // getline(cin,detail);

//     // setShippingDetails();
// }

// void initiate_Order_Quick_Buy(Buyer& buyer, vector<Cart>& cart){
//     //Order& order_temp = buyer.order;
//     placeOrder(buyer,cart,(buyer.order),(buyer.order.payment));
//     // order.payment.
// }


//Kashan Code

// void print_Invoice(const Buyer& buyer,const Order& order,const Payment& payment,const vector <Cart>& cart,Invoice& invoice) {

//     string file_name = buyer.get_buyerID();
//     string File_Location = "Invoice/" + file_name;
//     fstream write(File_Location, ios::app);
//     /* Buyer Data */
//     cout << "Buyer ID : " << buyer.get_buyerID() << endl;
//     cout << "Buyer Name : " << buyer.getName() << endl;
//     cout << "Phone Number : " << buyer.getPhoneNumber() << endl;
//     /* Check Person if the person is elite or stander*/


//     /* End OF Buyer Data */

//     /* Order Data */

//     cout << "Order ID : " << order.getOrderId() << endl;
//     cout << "Shipping Detail : " << order.getShippingDetails() <<endl;

//     /* End of Order Detail */

//     /* Payment Data */

//     cout << "Transaction ID : " << payment.getTransactionID() << endl;
//     cout << "Payment Detail : " << payment.getPaymentMethod() << endl; 
//     cout << "Shipping Charge : " << payment.getShippingCharges() << endl;
//     cout << "Total Bill :  " << payment.getTotalBill() << endl;

//     /* End OF The Payment Detail */
    
//     /* Invoid Detail */
//     cout << "Invoice ID : " << invoice.getInvoiceID() << endl;
//     cout << "Invoice Type : " << invoice.getInvoiceType() << endl;
    
//     invoice.generate_ReturnDate();

//     write <<"==================================="<<endl;
//     write <<"|\tBuyer ID : " << buyer.get_buyerID() << "\t|\n";
//     write <<"|\tBuyer Name : " << buyer.getName() << "\t|\n";
//     write <<"|\tPhone Number : " << buyer.getPhoneNumber() <<"\t|\n" << endl;
    
//     write << "|\tOrder ID : " << order.getOrderId() << "\t|\n";
//     write << "|\tShipping Detail : " << order.getShippingDetails() <<"\t|\n";
//     write << "|\tTransaction ID : " << payment.getTransactionID() <<"\t|\n";
//     write << "|\tPayment Detail : " << payment.getPaymentMethod() <<"\t|\n"; 
//     write << "|\tShipping Charge : " << payment.getShippingCharges() <<"\t|\n";
//     write << "|\tTotal Bill :  " << payment.getTotalBill() <<"\t|\n";
//     write << "|\tInvoice ID : " << invoice.getInvoiceID() <<"\t|\n";
//     write << "|\tInvoice Type : " << invoice.getInvoiceType() <<"\t|\n";
//     // write << getReturnDate() <<"\t|\n";

// }


// void generate_invoice(const Buyer& buyer,const Order& order,const Payment& payment,const vector <Cart> cart,Invoice& invoice){
// //     //Will use the object invoice to create a Invoice
// //     //Calls the member Function check_Payement and check that payment is set properly
// //     //check_shipping_charges function will also be used, check the header file for logic adn explanation
// //     check_Payment();
// //     check_shipping_charges();
//     invoice.setInvoiceID();
//     invoice.GenerateInvoiceType();
//     invoice.generate_ReturnDate();
//     print_Invoice(buyer,order,payment,cart);


//     // char choixe;
//     // cout << "Do You Want To Print The Invoice " <<endl;
//     // cin>>choixe;
//     // if (choixe == 'y' || choixe == 'Y')
//     // {
//     //     return;
//     // }
//     // else
//     // {
//     //     return;
//     // }


// }
// void placeOrder(const Buyer& buyer,const vector<Cart>& cart, Order& order, Payment& payment)
// {
//     order.setOrderId();
//     order.setShippingDetails();
//     order.setAmount(cart);

//     char choice;
//     cout << "Do You want to Checkout ?" << endl;
//     cout << "[Y] YES\t [N] NO" << endl;
//     cin >> choice;

//     if(choice == 'y' || choice == 'Y'){
//         Check_Out(buyer,cart,order,payment);
//     }
//     else if (choice == 'n' || choice == 'N')
//     {
//         order.cancelOrder();
//         return;
//     }



// void initiate_Order_Quick_Buy(const Buyer& buyer, const vector<Cart>& cart)
// {
//     placeOrder(buyer,cart,(buyer.order),(buyer.order.payment));
//     // order.payment.
//     Order order;
//     order.
// }

// void Check_Out(const Buyer& buyer,const vector<Cart>& cart, Order& order, Payment& payment)
// {
//     payment.setTotalBill(Amount);
//     payment.setPayMethod();
//     payment.setShipcharge(BuyerType);
//     generate_invoice(buyer,order,payment,cart);

// }


//     // // quickBuyNow();
//     // string detail;
//     // cout<<"Your Order is Successfully Created"<<endl;
//     // Payment pay;
//     // pay.select_PaymentMethod();

//     // getline(cin,detail);

//     // setShippingDetails();
// }

// void initiate_Order_Quick_Buy(const Buyer& buyer, const vector<Cart>& cart)
// {
//     placeOrder(buyer,cart,(buyer.order),(buyer.order.payment));
//     // order.payment.
//     Order order;
//     order.
// }

// void Check_Out(const Buyer& buyer,const vector<Cart>& cart, Order& order, Payment& payment)
// {
//     payment.setTotalBill(Amount);
//     payment.setPayMethod();
//     payment.setShipcharge(BuyerType);
//     generate_invoice(buyer,order,payment,cart);

// }


    // // quickBuyNow();
    // string detail;
    // cout<<"Your Order is Successfully Created"<<endl;
    // Payment pay;
    // pay.select_PaymentMethod();

    // getline(cin,detail);

    // setShippingDetails();
