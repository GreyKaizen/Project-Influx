#include <iostream>
//#include <iomanip>
#include <string>
//#include <cstring>

using namespace std;

class Product{
    private:
        string brand, product_name, productID, description;
        int price;

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
        Product* search_Product();
        //Need a Brand ONLY search too
        void reset();//DONE
        bool is_empty(string);//DONE
        bool is_empty(string,string);//DONE
        
        virtual void view_Product();//DONE
        
        void setProduct(string, int, string);
        //string getProduct();

        //From Inventory, Product Manipulation
        //Check Person First, for Admin ONLY
        void editProduct();
        void deleteProduct();

        //Quick Buy Now, pass ID
        //void printProduct(int);
        //Admin wants to see the whole Inventory
        bool checkPerson_Call(string);//DONE
        //Also for the Inventory Composition Relatio
        void print_Inventory_Products(string);

        //Print Cart Products
        //void print_Cart_Products(Product[]);
        //For Seller to print his products, seller will enter his ID to view all the products he is selling on out platform
        void print_Seller_products(int);
};

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


class Electronics : public Product {
private:
    string model;
    int screen_size, RAM, storage_capacity;
public:
    void setModel(string);
    string getModel() const;
    void setScreenSize(int);
    int getScreenSize() const;
    void setRAM(int);
    int getRAM() const;
    void setStorageCapacity(int);
    int getStorageCapacity() const;
    void view_Product();
};

class Fashion : public Product {
private:
    string size, color, material, style;
public:
    void setSize(string);
    string getSize() const;
    void setColor(string);
    string getColor() const;
    void setMaterial(string);
    string getMaterial() const;
    void setStyle(string);
    string getStyle() const;
};

class BeautyAndPersonalCare : public Product {
private:
    string type_of_product, ingredients, skin_hair_type, scent;
public:
    void setTypeOfProduct(string);
    string getTypeOfProduct() const;
    void setIngredients(string);
    string getIngredients() const;
    void setSkinHairType(string);
    string getSkinHairType() const;
    void setScent(string);
    string getScent() const;
};

class SportsAndOutdoors : public Product {
private:
    string size, color, material, sport_activity_type;
public:
    void setSize(string);
    string getSize() const;
    void setColor(string);
    string getColor() const;
    void setMaterial(string);
    string getMaterial() const;
    void setSportActivityType(string);
    string getSportActivityType() const;
};

class MedsAndHerbs : public Product {
private:
    string type, dosage, expiry;
    //string ingredients;
    //string target_health_condition; 
public:
    void setTypeOfProduct(string);
    string getTypeOfProduct() const;
    void setDosage(string);
    string getDosage() const;
    void setExpiry(string);
    string getExpiry() const;
};

class ToysAndGames : public Product {
private:
    string age_range, number_of_players, type_of_game;
public:
    void setAgeRange(int);
    int getAgeRange() const;
    void setTypeOfToyGame(string);
    string getTypeOfToyGame() const;
    void setNumberOfPlayers(int);
    int getNumberOfPlayers() const;
};

class PetSupplies : public Product {
private:
    string type_of_product, animal_type, age_range;
public:
    void setTypeOfProduct(string);
    string getTypeOfProduct() const;
    void setAnimalType(string);
    string getAnimalType() const;
    void setAgeRange(string);
    string getAgeRange() const;
};

class Automotive : public Product {
private:
    string model, vehicleType;
    int year, engineSize;
public:
    // Automotive() : Product() {}
    // Automotive(string prodID, string prodName, double prodPrice, string brand, string model, int year, string vehicleType, int engineSize) : Product(prodID, prodName, prodPrice), brand(brand), model(model), year(year), vehicleType(vehicleType), engineSize(engineSize) {}
    void setModel(string model);
    string getModel() const;
    void setYear(int year);
    int getYear() const;
    void setVehicleType(string vehicleType);
    string getVehicleType() const;
    void setEngineSize(int engineSize);
    int getEngineSize() const;
};
