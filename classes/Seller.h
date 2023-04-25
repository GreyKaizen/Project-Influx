#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "Inventory.h"

using namespace std;

class Seller : public Person{
    int seller_ID, profit_margin, stockSold;
    Inventory seller_access_inventory;

    public:
        void setSellerID(int);//DONE
        int generate_sellerID();//DONE
        int getSellerID() const;//DONE

        // void setProduct(Inventory);
        // Inventory getProduct();

        //Using the Object of Inventory Call the view_Inventory method
        //call the view_inventory method
        void access_Inventory();

        void setProfit(int);//DONE
        int getProfit() const;//DONE

        void setStockSold(int);//DONE
        int getStockSold() const;//DONE

        //Overridde method to check personType
        void check_Person();//DONE
        void changeINFO() const;
        void print_info() const;//DONE
};

class WholeSaler : protected Seller{
    const string brandName;

    public:
        //OVERRIDE
        void access_Inventory();

};

class CommonSeller : protected Seller{
    string brandName;

    public:
        //OVERRIDE
        void access_Inventory();
};