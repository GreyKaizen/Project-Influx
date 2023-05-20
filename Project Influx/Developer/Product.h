#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
//#include <iomanip>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "Seller.h"
#include "FriendFunction.h"

//#include <cstring>


using namespace std;

// Electronics: ELC101
// Fashion: FSH102
// Beauty and Personal Care: BPC103
// Sports and Outdoors: SPO104
// Health and Wellness: HLW105
// Toys and Games: TNG106
// Pet Supplies: PET107
// Automotive: AUT108
// Books and Stationery: BKS109

//Inventory KHI101
// LHE102
// ISB103
// PEW104
// UET105
// NYC106
// LON107
// DXB108

// Product Code
// ELC101
// FSH102
// BPC103
// SPO104
// HLW105
// TNG106
// PET107
// AUT108
// BKS109

//Specific Form Comma Separator Format for the Product
// Inventory_ID,productID,stock,Name,Price,Model,Screen_Size,RAM,Storage

struct Cart;

struct Data{
    int index;
    int quantity;
};

class Product{
    protected:
        string brand, product_name, productID, description;
        int price;
        static string inventories[7], inventory_files[7];
        static string categories[8], product_files[8];

    public:
        void setBrand(string);//DONE
        string getBrand() const; //DONE

        void setName(string);//DONE
        string getName() const; //DONE

        void setPrice(int);//DONE
        int getPrice() const ;//DONE

        void setDescription(string);//DONE
        string getDescription() const ;//DONE
        
        void setProductID(string);//DONE
        string getProductID() const ;//DONE

        //User Specifically Wants to Search Something
        void search_Product( vector<Cart>&);//DONE
        void reset();//DONE
        
        //Quick Buy Now, pass ID
        //void printProduct(int);
        //Admin wants to see the whole Inventory
        bool checkPerson_Call(string);//DONE
        //Also for the Inventory Composition Relation

        //Should override it for all and for one category specific
        void view_Product(vector<Cart>&);//DONE

        void update_Collected_Products( vector<string>&, vector<string>&, vector<Data>&);//DONE
        
        void setProduct();//DONE
        //string getProduct();


        //Product* print_Inventory_Products();//DONE

        //Print Cart Products
        //void print_Cart_Products(Product[]);
        //For Seller to print his products, seller will enter his ID to view all the products he is selling on out platform
        //Should Drop this Logic since can't do it
        //void print_Seller_products(int);

        //Overriden in Derive Classes
        virtual void write();//DONE

        friend vector<string> split( string& str, char delimiter);

        vector<Product> extract_Product_INFO(vector<string>&);

        void theCart(vector<Product>&, vector<Data>&, vector<Cart>&);

        //From Inventory, Product Manipulation
        //Check Person First, for Admin ONLY
        void editProduct();//2 file logic
        //virtual void deleteProduct();//2 file logic

        friend ostream& operator<<(ostream&, const Product&);
};

class Electronics : public Product {
private:
    string model;
    double screen_size;
    int RAM, storage_capacity;
public:
    void setModel(string);//DONE
    string getModel() const;//DONE
    void setScreenSize(int);//DONE
    int getScreenSize() const;//DONE
    void setRAM(int);//DONE
    int getRAM() const;//DONE
    void setStorageCapacity(int);//DONE
    int getStorageCapacity() const;//DONE

    void view_Product_Electronic(vector<string>&,vector<Data>&);//DONE
    //void setProduct();

    //OVERLOADING
    //for reading the class's own data member outside 
    friend istream& operator>>(istream&, Electronics&);//DONE

    friend ostream& operator<<(ostream&, const Electronics&);//DONE

    void write();//DONE
};

class Fashion : public Product {
private:
    string size, color, material, style;
public:
    void setSize(string);//DONE
    string getSize() const;//DONE
    void setColor(string);//DONE
    string getColor() const;//DONE
    void setMaterial(string);//DONE
    string getMaterial() const;//DONE
    void setStyle(string);//DONE
    string getStyle() const;//DONE

    void view_Product_Fashion(vector<string>&,vector<Data>&);//DONE
    //void setProduct();

    //OVERLOADING
    //for reading the class's own data member outside 
    friend istream& operator>>(istream&, Fashion&);//DONE

    friend ostream& operator<<(ostream&, const Fashion&);//DONE

    void write();//DONE
};

class BeautyAndPersonalCare : public Product {
private:
    string type_of_product, ingredients, skin_hair_type, scent;
public:
    void setTypeOfProduct(string);//DONE
    string getTypeOfProduct() const;//DONE
    void setIngredients(string);//DONE
    string getIngredients() const;//DONE
    void setSkinHairType(string);//DONE
    string getSkinHairType() const;//DONE
    void setScent(string);//DONE
    string getScent() const;//DONE

    void view_Product_BeautyAndPersonalCare(vector<string>&, vector<Data>&);//DONE
    //void setProduct();

    //OVERLOADING
    //for reading the class's own data member outside 
    friend istream& operator>>(istream&, BeautyAndPersonalCare&);//DONE

    friend ostream& operator<<(ostream&, const BeautyAndPersonalCare&);//DONE

    void write();//DONE
};

class SportsAndOutdoors : public Product {
private:
    string size, color, material, sport_activity_type;
public:
    void setSize(string);//DONE
    string getSize() const;//DONE
    void setColor(string);//DONE
    string getColor() const;//DONE
    void setMaterial(string);//DONE
    string getMaterial() const;//DONE
    void setSportActivityType(string);//DONE
    string getSportActivityType() const;//DONE

    void view_Product_SportsAndOutdoors(vector<string>&, vector<Data>&);//DONE
    //void setProduct();

    //OVERLOADING
    //for reading the class's own data member outside 
    friend istream& operator>>(istream&, SportsAndOutdoors&);//DONE

    friend ostream& operator<<(ostream&, const SportsAndOutdoors&);//DONE
    
    void write();//DONE
};

class MedsAndHerbs : public Product {
private:
    string type, dosage, expiry;
    //string ingredients;
    //string target_health_condition; 
public:
    void setTypeOfProduct(string);//DONE
    string getTypeOfProduct() const;//DONE
    void setDosage(string);//DONE
    string getDosage() const;//DONE
    void setExpiry(string);//DONE
    string getExpiry() const;//DONE

    void view_Product_MedsAndHerbs(vector<string>&, vector<Data>&);//DONE
    //void setProduct();

    //OVERLOADING
    //for reading the class's own data member outside 
    friend istream& operator>>(istream&, MedsAndHerbs&);//DONE

    friend ostream& operator<<(ostream&, const MedsAndHerbs&);//DONE
    
    void write();//DONE
};

class ToysAndGames : public Product {
private:
    string age_range, number_of_players, type_of_game;
public:
    void setAgeRange(string);//DONE
    string getAgeRange() const;//DONE
    void setTypeOfToyGame(string);//DONE
    string getTypeOfToyGame() const;//DONE
    void setNumberOfPlayers(int);//DONE
    string getNumberOfPlayers() const;//DONE

    void view_Product_ToysAndGames(vector<string>&, vector<Data>&);//DONE
    //void setProduct();

    //OVERLOADING
    //for reading the class's own data member outside 
    friend istream& operator>>(istream&, ToysAndGames&);//DONE

    friend ostream& operator<<(ostream&, const ToysAndGames&);//DONE
    
    void write();//DONE
};

class PetSupplies : public Product {
private:
    string type_of_product, animal_type, age_range;
public:
    void setTypeOfProduct(string);//DONE
    string getTypeOfProduct() const;//DONE
    void setAnimalType(string);//DONE
    string getAnimalType() const;//DONE
    void setAgeRange(string);//DONE
    string getAgeRange() const;//DONE

    void view_Product_PetSupplies(vector<string>&, vector<Data>&);//DONE
    //void setProduct();

    //OVERLOADING
    //for reading the class's own data member outside 
    friend istream& operator>>(istream&, PetSupplies&);//DONE

    friend istream& operator<<(istream&, const PetSupplies&);//DONE
    
    void write();//DONE
};

class Automotive : public Product {
private:
    string model, vehicleType;
    int year, engineSize;
public:
    // Automotive() : Product() {}
    // Automotive(string prodID, string prodName, double prodPrice, string brand, string model, int year, string vehicleType, int engineSize) : Product(prodID, prodName, prodPrice), brand(brand), model(model), year(year), vehicleType(vehicleType), engineSize(engineSize) {}
    void setModel(string);//DONE
    string getModel() const;//DONE
    void setYear(int);//DONE
    int getYear() const;//DONE
    void setVehicleType(string);////DONEDONE
    string getVehicleType() const;//DONE
    void setEngineSize(int);//DONE
    int getEngineSize() const;//DONE

    void view_Product_Automotive(vector<string>&, vector<Data>&);//DONE
    //void setProduct();

    //OVERLOADING
    //for reading the class's own data member outside 
    friend istream& operator>>(istream&, Automotive&);//DONE

    friend ostream& operator<<(ostream&, const Automotive&);//DONE
    
    void write();//DONE
};

struct Cart{
    int quantity;
    Product product;
    
    void displayProducts(const vector<Cart>&) const;
    //Contains Remove, Clear and Change the Quantity of Certain Product Functionality
    void remove_Cart(vector<Cart>&);
    //Calculate Price Function
    int CalculateTotalPrice(const vector<Cart>&);

    //friend ostream& operator<<(ostream&, const Cart&);
};

#endif