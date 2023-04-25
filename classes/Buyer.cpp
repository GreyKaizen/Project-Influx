#include <iostream>
#include "Buyer.h"
#include <cstdlib>

using namespace std;

void Buyer::setBuyerID(){
    //No Values taken from outside will generate automatically
    BuyerID = generate_buyerID();
}
int Buyer::generate_buyerID(){
    //To generate unique each time it executes
    srand(time(0));
    int random_generate = rand()%100000000001;
    //return to the set function
    return random_generate;
}
int Buyer::get_buyerID() const {
    return BuyerID;
}

void Guest::register_user(){
    //write the info to the buyer's file
    //Utilize File Handling Here
}

void Guest::log_out(){
    //should make this a global function
}

void Guest::print_Register_toBuy(){
    cout << "Buy" << endl << "Get Discount" << endl << "Avail Coupons and Gift Cards" << endl << "And Many more great deals waiting for you" << endl << endl << "Register Now and Avail Everything We have to Offer" << endl;
}

void Registered_Buyer::setBalance(double available_balance){
    this->available_balance = available_balance;
}
double Registered_Buyer::getBalance() const{
    return available_balance;
}

//OVERRIDE
void Registered_Buyer::changeINFO();
//File handling to read the data and then change it
//Problem if there are ten users and we read the information of 7th user and do we write the whole file again or what

void Registered_Buyer::check_Person(){
    return "Buyer";
}

void Registered_Buyer::print_info() const{
    cout << "Buyer ID : " << get_buyerID() << endl << "Name of Buyer : " << getName() << endl << "Phone Number : " << getPhoneNumber() << endl << "username : " << getUsername() << endl << "password : " << getPassword() << endl << "Date of Joing : " << getDateOfJoining() << endl;
}

void Registered_Buyer::initiate_Order_Quick_Buy(){

}

void Registered_Buyer::usingCart(){

}

void Registered_Buyer::viewCart(){

}