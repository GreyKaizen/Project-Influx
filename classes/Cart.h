#include <iostream>
//#include <iomanip>
#include <string>
//#include <cstring>
#include "Product.h"

using namespace std;

class Cart{
    //share the same index for consistency of info
    Product items[];
    int quantity[];
    //int amount[]; each product object hold name,price in itself

    public:
        //can be used in Cart Class
        //void Add_to_Cart(int,Product,int);
        //void remove_from_cart(int,Product,int);
        void print_Cart_Products();
        void edit_Cart();
        //void editProduct_Attributes(int,Product,int);
        //print/view function
}