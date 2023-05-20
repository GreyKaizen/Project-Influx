#ifndef SELLER_H
#define SELLER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include "Person.h"
#include "Inventory.h"

using namespace std;

class Seller : public Person{
    protected:
        string seller_ID;
        int commission_margin, stockSold;
        string brand;
        //Inventory seller_access_inventory;

    public:
        void setSellerID(string);
        string getSellerID() const;//DONE

        void setBrand(string);
        string getBrand() const;

        // void setProduct(Inventory);
        // Inventory getProduct();
        void setCommissionMargin(int);//DONE
        int getCommissionMargin() const;//DONE

        void setStockSold(int);//DONE
        int getStockSold() const;//DONE

        void editINFO();//DONE
        //Overridden method to check personType
        void print_info() const;//DONE
        virtual string check_Person() const;//DONE
        //Using the Object of Inventory Call the view_Inventory method
        //call the view_inventory method
        virtual void sell_Product();

        void write();//DONE
};

class WholeSaler : public Seller{
    public:
        void setSellerID_whlSaler();//DONE
        string generate_sellerID_whlSaler();//DONE
        //OVERRIDE
        string check_Person() const;//DONE

        void sell_Product();

        friend istream&  operator>>(istream&, WholeSaler&);
        friend ostream&  operator<<(ostream& , const WholeSaler&);
};

class CommonSeller : public Seller{
    public:
        void setSellerID_C_Seller();//DONE
        string generate_sellerID_C_Seller();//DONE 
        //OVERRIDE
        string check_Person() const;//DONE

        void sell_Product();

        friend istream&  operator>>(istream&, CommonSeller&);
        friend ostream&  operator<<(ostream&, const CommonSeller&);
};

#endif