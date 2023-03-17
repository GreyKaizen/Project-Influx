#include <iostream>
//#include <iomanip>
#include <string>
//#include <cstring>
#include "Product.h"

using namespace std;

class Cart{
    Product product[];
    int Quantity;

    public:
        //can be used in Cart Class
        void Add_to_Cart();
        void remove_from_cart();
}