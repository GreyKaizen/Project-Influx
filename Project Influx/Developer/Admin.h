#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
//#include <iomanip>
#include <string>
//#include <cstring>
#include <fstream>
#include "Inventory.h"
#include "Person.h"
#include "FriendFunction.h"


using namespace std;

class Admin : public Person{
    //To access the Buyer and Seller Data
    //fstream  file_reader_buyer, file_reader_seller;
    //Inventory to access details about the inventory and product
    //Inventory access_inventory;

    //Data members should have been there if Admin had some use of them, but admin will mostly be using the Inventory and Product object inside the Function to perform Actions.

    public:
        //Admin()
        //For access of buyer and seller information
        void edit_Buyer_Seller_INFO();//DONE
        void edit_Product_INFO();//DONE
        void edit_Inventory_INFO();//DONE

        //to edit information about himself
        //it will call parent class Person member function to edit the information
        //void changeINFO();

        //Check Person Type, will be called by Inventory Class Method
        //OVERRIDE
        string check_Person() const;//DONE

        friend vector<string> split( string& str, char delimiter);

        //print information regarding the Person
        void print_info() const;//DONE
        void editINFO();
};

#endif