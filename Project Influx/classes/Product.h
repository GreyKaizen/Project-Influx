#include <iostream>
//#include <iomanip>
#include <string>
//#include <cstring>

using namespace std;

class Product{
    string product_name;
    int price;
    string description;

    public:
        void setName(string);
        void setPrice(int);
        void setDescription(string);

        void SearchProduct(string);s

        void getProduct(string);
};