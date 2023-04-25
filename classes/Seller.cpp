#include <iostream>
#include "Seller.h"
#include <cstdlib>

using namespace std;

void Seller::setSellerID(){
    seller_ID = generate_sellerID();
}
int Seller::generate_sellerID(){
    //To generate unique each time it executes
    srand(time(0));
    int random_generate = rand()%100000000001;
    //return to the set function
    return random_generate;
}
int Seller::getSellerID() const {
    return seller_ID;
}

void Seller::access_Inventory();

void Seller::setProfit(int profit_margin){
    this->profit_margin = profit_margin;
}
int Seller::getProfit() const {
    return profit_margin;
}

void Seller::setStockSold(int stockSold){
    this->stockSold = stockSold;
}
int Seller::getStockSold() const {
    return stockSold;
}

//Overridde method to check personType
void Seller::check_Person(){
    return "Seller";
}
void Seller::changeINFO() const;

void Seller::print_info() const {
    cout << "Buyer ID : " << get_buyerID() << endl << "Name of Buyer : " << getName() << endl << "Phone Number : " << getPhoneNumber() << endl << "username : " << getUsername() << endl << "password : " << getPassword() << endl << "Date of Joing : " << getDateOfJoining() << endl;
}

void WholeSaler::access_Inventory(){

}

void CommonSeller::access_Inventory(){
    
}