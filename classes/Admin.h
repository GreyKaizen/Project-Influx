#include <iostream>
//#include <iomanip>
#include <string>
//#include <cstring>
#include "Inventory.h"
#include "Person.h"
#include <fstream>

using namespace std;

class Admin : protected Person{
    //To access the Buyer and Seller Data
    fstream  file_reader_buyer, file_reader_seller;
    //Inventory to access details about the inventory and product
    Inventory access_inventory;

    public:
        //Admin()
        //For access of buyer and seller information
        void deleteUser();
        void editUser();

        //to edit information about himself
        //it will call parent class Person member function to edit the information
        void changeINFO();

        //Check Person Type, will be called by Inventory Class Method
        //OVERRIDE
        void check_Person() const;//DONE

        //print information regarding the Person
        void print_info() const;//DONE
};