#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
//#include <iomanip>
#include <string>
#include <vector>
//#include <cstring>
#include "Product.h"
#include "FriendFunction.h"

using namespace std;

class Inventory{
    int stock;
    string Inventory_ID;
    string location;
    static string inventory_files[7], inventories[7];
    //Product access_Product[];
    //vector<Product> Products; 
    // Product for the usage of Admin to View All the Info Regarding Inventory and Product

    // Karachi, Pakistan: KHI101
    // Lahore, Pakistan: LHE102
    // Islamabad, Pakistan: ISB103
    // Peshawar, Pakistan: PEW104
    // Quetta, Pakistan: UET105
    // New York, USA: NYC106
    // London, UK: LON107
    // Dubai, UAE: DXB108
    
    public:
        void setStock(int);//DONE
        int getStock() const;//DONE

        friend vector<string> split( string& str, char delimiter);

        //string Inventories[7] = {"PES101", "KAR102", "LAR103", "MUL104", "ISL105", "QUE106", "BMR107"};
        //Use of Above Location+ID to track inventories
        void setLocation(string);//DONE
        string getLocation() const;//DONE

        void setID(string);//DONE
        string getID() const;//DONE

        //Will use the Product Class object of Inventory to write the seller products to the product files system

        //void save_Product(Product[]);
        
        //Product getProduct();
        
        //void search_Inventory();//DONE

        //Call the editInventory, deleteInventory searcInventory method in menu options
        //For viewing the product the object of Product inside the int main() will be used
        void view_Inventory();//DONE

        //To check Admin and Seller
        bool checkPerson_Call(string);//DONE


        void edit_Inventory();
        //for Inventory manipulation
        //Afterwards this method will get an array of Product class objects from the user and then pass it to the setProduct method
        //Check Person First, for ADMIN ONLY

};

#endif