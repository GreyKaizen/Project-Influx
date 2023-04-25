#include <iostream>
//#include <iomanip>
#include <string>
//#include <cstring>
#include "Product.h"

using namespace std;

class Inventory{
    int stock;
    string Inventory_ID;
    string location;
    //Product access_Product[];
    Product product[]; // Product for the usage of Admin to View All the Info Regarding Inventory and Product

    public:
        void setStock(int);
        int getStock();

        //string Inventories[7] = {"PES101", "KAR102", "LAR103", "MUL104", "ISL105", "QUE106", "BMR107"};
        //Use of Above Location+ID to track inventories
        void setLocation(string);
        string getLocation();

        void setID(string);
        string getID();

        //Will use the Product Class object of Inventory to write the seller products to the product files sytem
        void save_Product(Product[]);
        //Product getProduct();

        //for Inventory manipulation
        //Afterwards this method will get an array of Product class objects from the user and then pass it to the setProduct method
        void edit_Inventory();
        //Check Person First, for ADMIN ONLY
        void delete_Inventory();

        void search_Inventory();

        //Call the editInventory, deleteInventory searcInventory method in menu options
        //For viewing the product the object of Product inside the int main() will be used
        void view_Inventory();

        //To check Admin and Seller
        void checkPerson_Call();
}

// Karachi, Pakistan: KHI101
// Lahore, Pakistan: LHE102
// Islamabad, Pakistan: ISB103
// Peshawar, Pakistan: PEW104
// Quetta, Pakistan: UET105
// New York, USA: NYC106
// London, UK: LON107
// Dubai, UAE: DXB108