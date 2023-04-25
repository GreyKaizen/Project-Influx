#include <iostream>
#include "Payment.h"
#include <cstdlib>

using namespace std;

void Payment::setTransactionID(){
    transaction_ID = generate_TransactionID();
}
void Payment::generate_TransactionID(){
    //To generate unique each time it executes
    srand(time(0));
    int random_generate = rand()%100000000001;
    //return to the set function
    return random_generate;
}
int Payment::getTransactionID() const {
    return transaction_ID;
}

double Payment::getTotalBill() const{
    return total_bill;
}

string Payment::getPaymentMethod() const {
    return Pay_Method;
}

void Payment::select_PaymentMethod(){
    string Methods_of_Payment[5] = {"COD", "Mobile Payment", "MasterCard/VISA", "Credit Card", "Debit Card"};
    int input;

    for(int i = 0; i < 5 ; i++){
        cout << i+1 << ". " << Methods_of_Payment[i] << endl;
        if(i==5){
            cout << "Chosoe the Method, Please ...";
            cin >> input;
        }
    }

    //this sets the selected method of payment to the data member
    setPaymentMethod(Methods_of_Payment[i-1]);
}

void Payment::setPaymentMethod(string Pay_Method){
    this->Pay_Method = Pay_Method;
}

void Payment::check_Coupon(string Coupon){
    //fstream usage to read file and match the coupon in the file
    //Will Reduce the amount of Total Bill
    //Save the coupon in the following format
    //PEHLAORDER2022.20
    //20 in the end represent amount of discount the coupon will give

}

void Payment::check_gift_card(string Gift_Card){
    //same logic for this too
    //might have to drop this idea since coupon and gift card both provide the same functionality : reducing the total Billing Amount
}

bool Payment::check_Payment(){
    return !(Pay_Method.empty());
}

void Payment::generate_invoice(){
    //Will use the object invoice to create a Invoice
    //Calls the member Function check_Payement and check that payment is set properly
    //check_shipping_charges function will also be used, check the header file for logic adn explanation
    check_Payment();
    check_shipping_charges();
}

void Payment::check_shipping_charges(){
    // if(total_bill>2000){
    //     shipping_charges = 0;
    // }
    // else{
    //     shipping_charges = 400;
    // }

    //above reflects the same condition
    //i used one liner
    shipping_charges = total_bill>2000 ? 0 : 400;
}

