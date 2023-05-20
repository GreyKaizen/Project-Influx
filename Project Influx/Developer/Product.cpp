#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include "Product.h"

using namespace std; 

void Cart::displayProducts(const vector<Cart>& cart) const {
    if(cart.empty()){
        cout << "Cart is empty!\nBut You can Always Fill his Stomach with Some Products" << endl;

        return;
    }
    else{
        cout << "Your Cart Contains ...\n";

        for(int i = 0; i < cart.size(); i++){
            cout << i+1 << ". " << cart[i].product << " | " << cart[i].quantity << endl;
        }

        return;
    }
}

void Cart::remove_Cart(vector<Cart>& cart){
    displayProducts(cart);

    cout << "ENTER -1 to EXIT REMOVE PRODUCT FROM CART MODE." << endl << endl;

    while(1){
        cout << endl << "Enter Item Serial Number, you want to Remove From Your Cart : ";
        int input;
        cin >> input;

        if(input == -1){
            cout << "DONE, with Cart Change\nLet's Explore More...";

            return;
        }
        if(input > cart.size() || input <= 0){
            cout << "Please Check you input Again\n You might have done some mistake!" << endl;

            continue;
        }

        cart.erase(cart.begin()+input);
        
        cout << endl << "Product Has been successfully removed from cart." << endl << endl;
    }

    return;
}

int Cart::CalculateTotalPrice(const vector<Cart>& cart){
    int sum;
    if(cart.empty()){
        cout << "Add Products First,\nThen We will be able to calculate total sum price"<< endl << endl;
    }
    else{
        displayProducts(cart);

        for(int i = 0; i < cart.size(); i++){
            sum += cart[i].quantity;
        }

        cout << "\t\t\tTotal Price : " << sum << endl;
    }

    return sum;
}


string Product::categories[8] = { "ELC101", "FSH102", "BPC103", "SPO104", "HLW105", "TNG106", "PET107", "AUT108"};
string Product::product_files[8] = {"Products/Categories/ELC101.txt","Products/Categories/FSH102.txt","Products/Categories/BPC103.txt","Products/Categories/SPO104.txt","Products/Categories/MED105.txt","Products/Categories/TNG106.txt","Products/Categories/PET107.txt","Products/Categories/AUT108.txt"};
 
string Product::inventories[7] = {"KAR101", "LHE102", "ISB103", "PEW104", "QET105", "NYC106", "DXB108"};
string Product::inventory_files[7] = {"Products/Inventories/KAR101.txt", "Products/Inventories/LAH102.txt", "Products/Inventories/ISB103.txt", "Products/Inventories/PEW104.txt", "Products/Inventories/QET105.txt", "Products/Inventories/NYC106.txt", "Products/Inventories/DXB108.txt"};

//Write Functions down here
void Product::write(){
    //empty for overriding
}

ostream& operator<<(ostream& os, const Product& Product){
    os << " | " << "Product ID: " << setw(8) << Product.getProductID() << " | " << "Brand: " << setw(8) << Product.getBrand() << " | " << "Name: " << setw(10) << Product.getName() << " | " << "Price: $" << setw(10) << Product.getPrice() << " | " << endl;
    return os;
}

//Electronics Class
void Electronics::setModel(string model){
    this->model = model;
}
string Electronics::getModel() const{
    return model;
}
void Electronics::setScreenSize(int screen_size){
    this->screen_size = screen_size;
}
int Electronics::getScreenSize() const{
    return screen_size;
}
void Electronics::setRAM(int RAM){
    this->RAM = RAM;
}
int Electronics::getRAM() const{
    return RAM;
}
void Electronics::setStorageCapacity(int storage_capacity){
    this->storage_capacity = storage_capacity;
}
int Electronics::getStorageCapacity() const{
    return storage_capacity;
}
//Writing to file
void Electronics::write(){
    // Check if all data members are empty
    if (brand.empty() || product_name.empty() || productID.empty() || description.empty() || model.empty() || screen_size == 0.0 || RAM == 0 || storage_capacity == 0 || price == 0) {
        cout << "Please provide all necessary information before writing." << endl << "Ciao ..." << endl;
        return;
    }

    // Ask user which inventory to save data to
    cout << endl << "Choose in Which Inventory Should your Product be saved?" << endl << "1. Karachi" << endl << "2. Lahore" << endl << "3. Islamabad" << endl << "4. Peshawar" << endl << "5. Quetta" << endl << "6.New York" << endl << "7.Dubai" << endl << endl << "Awaiting Response => ";
    int input;
    cin >> input;

    // Ask user how much stock do we have
    int stock;
    cout << "Enter stock: ";
    cin >> stock;
     
    //To Open the Specific Inventory File, matching the location user provided
    fstream File_Inventory(inventory_files[input-1],ios::app);
    if (!File_Inventory.is_open()) {
        cerr << "Error opening All_Products file for writing" << endl;
        return;
    }

    //This is fix, as we are working for the Electronic class
    fstream File_Category("Products/Categories/ELC101.txt",ios::app);
    if (!File_Category.is_open()) {
        cerr << "Error opening All_Products file for writing" << endl;
        return;
    }

    //All Product List Update
    fstream All_Product("Products/All_Product.txt");
    if (!All_Product.is_open()) {
        cerr << "Error opening All_Products file for writing" << endl;
        return;
    }

    //Category have all information
    File_Category << endl << inventories[input-1] << "," << productID << "," << stock << "," << brand << "," << product_name << "," << price << "," << model << "," << screen_size << "," << RAM << "," << storage_capacity << "," << description << endl;
    //Inventory and All Product list has all except description
    File_Inventory << endl << inventories[input-1] << "," << productID << "," << stock << "," << brand << "," << product_name << "," << price << "," << model << "," << screen_size << "," << RAM << "," << storage_capacity << endl;

    // Write data to All_Products file
    All_Product << endl << inventories[input-1] << "," << productID << "," << stock << "," << brand << "," << product_name << "," << price << "," << model << "," << screen_size << "," << RAM << "," << storage_capacity << endl;

    // Close All_Products file
    File_Category.close();
    All_Product.close();
    File_Inventory.close();

    cout << "Data written to files successfully" << endl;
}

//Overloaded Operator
istream& operator>>(istream& is, Electronics& electronicProduct) {
    string input;

    // input for inherited data members from Product class
    cout << "Provide Information for Electronic Products" << endl;
   
    electronicProduct.setProductID("ELC101");

    cin.ignore();
    cout << "Brand : ";
    getline(is, input);
    electronicProduct.setBrand(input);

    cout << "Name : ";
    getline(is, input);
    electronicProduct.setName(input);
    
    cout << "Price : ";
    getline(is, input);
    electronicProduct.setPrice(stoi(input));

    //input for Electronics data members
    cout << "Model : ";
    getline(is, input);
    electronicProduct.setModel(input);

    cout << "Screen Size : ";
    getline(is, input);
    electronicProduct.setScreenSize(stod(input));

    cout << "RAM Size : ";
    getline(is, input);
    electronicProduct.setRAM(stoi(input));

    cout << "Storage Capacity : ";
    getline(is, input);
    electronicProduct.setStorageCapacity(stoi(input));

    cout << "Description : ";
    getline(is, input);
    electronicProduct.setDescription(input);

    return is;


}

ostream& operator<<(ostream& os, const Electronics& electronicProduct) {

    os << "Product ID: " << electronicProduct.getProductID() << endl;
    os << "Brand: " << electronicProduct.getBrand() << endl;
    os << "Product Name: " << electronicProduct.getName() << endl;
    os << "Price: " << electronicProduct.getPrice() << endl;
    os << "Model: " << electronicProduct.getModel() << endl;
    os << "Screen Size: " << electronicProduct.getScreenSize() << endl;
    os << "RAM Size: " << electronicProduct.getRAM() << endl;
    os << "Storage Capacity: " << electronicProduct.getStorageCapacity() << endl;
    os << "Description: " << electronicProduct.getDescription() << endl;

    return os;
}


//Fashion Class
void Fashion::setSize(string size){
    this->size = size;
}
string Fashion::getSize() const{
    return size;
}
void Fashion::setColor(string color){
    this->color = color;
}
string Fashion::getColor() const{
    return color;
}
void Fashion::setMaterial(string material){
    this->material = material;
}
string Fashion::getMaterial() const{
    return material;
}
void Fashion::setStyle(string style){
    this->style = style;
}
string Fashion::getStyle() const{
    return style;
}
//Write to File
void Fashion::write(){
    // Check if all data members are empty
    if (brand.empty() || product_name.empty() || productID.empty() || description.empty() || size.empty() || color.empty() || material.empty() || style.empty()) {
        cout << "Please provide all necessary information before writing." << endl << "Ciao ..." << endl;
        return;
    }

    // Ask user which inventory to save data to
    cout << "Choose in Which Inventory Should your Product be saved?" << endl << "1. Karachi" << endl << "2. Lahore" << endl << "3. Islamabad" << endl << "4. Peshawar" << endl << "5. Quetta" << endl << "6.New York" << endl << "7.Dubai" << endl << endl << "Awaiting Response => ";
    int input;
    cin >> input;

    // Ask user how much stock do we have
    int stock;
    cout << "Enter stock: ";
    cin >> stock;
     
    //To Open the Specific Inventory File, matching the location user provided
    fstream File_Inventory(inventory_files[input-1],ios::app);
    if (!File_Inventory.is_open()) {
        cerr << "Error opening All_Products file for writing" << endl;
        return;
    }

    //This is fix, as we are working for the Electronic class
    fstream File_Category("Products/Categories/ELC101.txt",ios::app);
    if (!File_Category.is_open()) {
        cerr << "Error opening All_Products file for writing" << endl;
        return;
    }

    //All Product List Update
    fstream All_Product("Products/All_Product.txt");
    if (!All_Product.is_open()) {
        cerr << "Error opening All_Products file for writing" << endl;
        return;
    }

    //Category have all information
    File_Category << endl << inventories[input-1] << productID << stock << "," << brand << "," << product_name << "," << price << "," << size << "," << color << "," << material << "," << style << "," << description << endl;
    //Inventory and All Product list has all except description
    File_Inventory<< endl << inventories[input-1] << productID << stock << "," << brand << "," << product_name << "," << price << "," << size << "," << color << "," << material << "," << style<< endl;

    // Write data to All_Products file
    All_Product<< endl << inventories[input-1] << productID << stock << "," << brand << "," << product_name << "," << price << "," << size << "," << color << "," << material << "," << style<< endl;

    // Close All_Products file
    File_Category.close();
    All_Product.close();
    File_Inventory.close();

    cout << "Data written to files successfully" << endl;
}
//Overloaded operator
istream& operator>>(istream& is, Fashion& fashionProduct) {

    string input;

    // input for inherited data members from Product class
    cout << "Provide Information for Fashion Products" << endl;
   
    fashionProduct.setProductID("FSH102");

    cin.ignore();
    cout << "Brand : ";
    getline(is, input);
    fashionProduct.setBrand(input);

    cout << "Name : ";
    getline(is, input);
    fashionProduct.setName(input);
    
    cout << "Price : ";
    getline(is, input);
    fashionProduct.setPrice(stoi(input));

    //input for Fashion data members
    cout << "Size : ";
    getline(is, input);
    fashionProduct.setSize(input);

    cout << "Color : ";
    getline(is, input);
    fashionProduct.setColor(input);

    cout << "Material : ";
    getline(is, input);
    fashionProduct.setMaterial(input);

    cout << "Style : ";
    getline(is, input);
    fashionProduct.setStyle(input);

    return is;
}

ostream& operator<<(ostream& os, const Fashion& fashionProduct) {

    os << "Product ID: " << fashionProduct.getProductID() << endl;
    os << "Brand: " << fashionProduct.getBrand() << endl;
    os << "Product Name: " << fashionProduct.getName() << endl;
    os << "Price: " << fashionProduct.getPrice() << endl;
    os << "Size: " << fashionProduct.getSize() << endl;
    os << "Color: " << fashionProduct.getColor() << endl;
    os << "Material: " << fashionProduct.getMaterial() << endl;
    os << "Style: " << fashionProduct.getStyle() << endl;
    os << "Description: " << fashionProduct.getDescription() << endl;

    return os;
}


//Beauty&Care Class
void BeautyAndPersonalCare::setTypeOfProduct(string type_of_product){
    this->type_of_product = type_of_product;
}
string BeautyAndPersonalCare::getTypeOfProduct() const{
    return type_of_product;
}
void BeautyAndPersonalCare::setIngredients(string ingredients){
    this->ingredients = ingredients;
}
string BeautyAndPersonalCare::getIngredients() const{
    return ingredients;
}
void BeautyAndPersonalCare::setSkinHairType(string skin_hair_type){
    this->skin_hair_type = skin_hair_type;
}
string BeautyAndPersonalCare::getSkinHairType() const{
    return skin_hair_type;
}
void BeautyAndPersonalCare::setScent(string scent){
    this->scent = scent;
}
string BeautyAndPersonalCare::getScent() const{
    return scent;
}
//Write to File
void BeautyAndPersonalCare::write(){
    // Check if all data members are empty
    if (brand.empty() || product_name.empty() || productID.empty() || description.empty() || type_of_product.empty() || ingredients.empty() || skin_hair_type.empty() || scent.empty()) {
        cout << "Please provide all necessary information before writing." << endl << "Ciao ..." << endl;
        return;
    }

    // Ask user which inventory to save data to
    cout << "Choose in Which Inventory Should your Product be saved?" << endl << "1. Karachi" << endl << "2. Lahore" << endl << "3. Islamabad" << endl << "4. Peshawar" << endl << "5. Quetta" << endl << "6.New York" << endl << "7.Dubai" << endl << endl << "Awaiting Response => ";
    int input;
    cin >> input;

    // Ask user how much stock do we have
    int stock;
    cout << "Enter stock: ";
    cin >> stock;
     
    //To Open the Specific Inventory File, matching the location user provided
    fstream File_Inventory(inventory_files[input-1],ios::app);
    if (!File_Inventory.is_open()) {
        cerr << "Error opening All_Products file for writing" << endl;
        return;
    }

    //This is fix, as we are working for the Electronic class
    fstream File_Category("Products/Categories/ELC101.txt",ios::app);
    if (!File_Category.is_open()) {
        cerr << "Error opening All_Products file for writing" << endl;
        return;
    }

    //All Product List Update
    fstream All_Product("Products/All_Product.txt");
    if (!All_Product.is_open()) {
        cerr << "Error opening All_Products file for writing" << endl;
        return;
    }

    //Category have all information
    File_Category << endl<< inventories[input-1] << productID << "," << stock << "," << brand << "," << product_name << "," << price << "," << type_of_product << "," << ingredients << "," << skin_hair_type << "," << scent << "," << description<< endl;
    //Inventory and All Product list has all except description
    File_Inventory << endl<< inventories[input-1] << productID << "," << stock << "," << brand << "," << product_name << "," << price << "," << type_of_product << "," << ingredients << "," << skin_hair_type << "," << scent<< endl;

    // Write data to All_Products file
    All_Product << endl<< inventories[input-1] << productID << "," << stock << "," << brand << "," << product_name << "," << price << "," << type_of_product << "," << ingredients << "," << skin_hair_type << "," << scent<< endl;

    // Close All_Products file
    File_Category.close();
    All_Product.close();
    File_Inventory.close();

    cout << "Data written to files successfully" << endl;
}

//Overloaded Operator
istream& operator>>(istream& is, BeautyAndPersonalCare& personalCareProduct) {

    string input;

    // input for inherited data members from Product class
    cout << "Provide Information for Beauty and Personal Care Products" << endl;
   
    personalCareProduct.setProductID("BPC103");

    cin.ignore();
    cout << "Brand : ";
    getline(is, input);
    personalCareProduct.setBrand(input);

    cout << "Name : ";
    getline(is, input);
    personalCareProduct.setName(input);
    
    cout << "Price : ";
    getline(is, input);
    personalCareProduct.setPrice(stoi(input));

    //input for BeautyAndPersonalCare data members
    cout << "Type of Product : ";
    getline(is, input);
    personalCareProduct.setTypeOfProduct(input);

    cout << "Ingredients : ";
    getline(is, input);
    personalCareProduct.setIngredients(input);

    cout << "Skin/Hair Type : ";
    getline(is, input);
    personalCareProduct.setSkinHairType(input);

    cout << "Scent : ";
    getline(is, input);
    personalCareProduct.setScent(input);

    cout << "Description : ";
    getline(is, input);
    personalCareProduct.setDescription(input);

    return is;
}

ostream& operator<<(ostream& os, const BeautyAndPersonalCare& personalCareProduct) {

    os << "Product ID: " << personalCareProduct.getProductID() << endl;
    os << "Brand: " << personalCareProduct.getBrand() << endl;
    os << "Product Name: " << personalCareProduct.getName() << endl;
    os << "Price: " << personalCareProduct.getPrice() << endl;
    os << "Type of Product: " << personalCareProduct.getTypeOfProduct() << endl;
    os << "Ingredients: " << personalCareProduct.getIngredients() << endl;
    os << "Skin/Hair Type: " << personalCareProduct.getSkinHairType() << endl;
    os << "Scent: " << personalCareProduct.getScent() << endl;
    os << "Description: " << personalCareProduct.getDescription() << endl;

    return os;
}


void SportsAndOutdoors::setSize(string size){
    this->size = size;
}
string SportsAndOutdoors::getSize() const{
    return size;
}
void SportsAndOutdoors::setColor(string color){
    this->color = color;
}
string SportsAndOutdoors::getColor() const{
    return color;
}
void SportsAndOutdoors::setMaterial(string material){
    this->material = material;
}
string SportsAndOutdoors::getMaterial() const{
    return material;
}
void SportsAndOutdoors::setSportActivityType(string sport_activity_type){
    this->sport_activity_type = sport_activity_type;
}
string SportsAndOutdoors::getSportActivityType() const{
    return sport_activity_type;
}
//Write to File
void SportsAndOutdoors::write(){
    // Check if all data members are empty
    if (brand.empty() || product_name.empty() || productID.empty() || description.empty() || size.empty() || color.empty() || material.empty() || sport_activity_type.empty()) {
        cout << "Please provide all necessary information before writing." << endl << "Ciao ..." << endl;
        return;
    }

    // Ask user which inventory to save data to
    cout << "Choose in Which Inventory Should your Product be saved?" << endl << "1. Karachi" << endl << "2. Lahore" << endl << "3. Islamabad" << endl << "4. Peshawar" << endl << "5. Quetta" << endl << "6.New York" << endl << "7.Dubai" << endl << endl << "Awaiting Response => ";
    int input;
    cin >> input;

    // Ask user how much stock do we have
    int stock;
    cout << "Enter stock: ";
    cin >> stock;
     
    //To Open the Specific Inventory File, matching the location user provided
    fstream File_Inventory(inventory_files[input-1],ios::app);
    if (!File_Inventory.is_open()) {
        cerr << "Error opening All_Products file for writing" << endl;
        return;
    }

    //This is fix, as we are working for the Electronic class
    fstream File_Category("Products/Categories/ELC101.txt",ios::app);
    if (!File_Category.is_open()) {
        cerr << "Error opening All_Products file for writing" << endl;
        return;
    }

    //All Product List Update
    fstream All_Product("Products/All_Product.txt");
    if (!All_Product.is_open()) {
        cerr << "Error opening All_Products file for writing" << endl;
        return;
    }

    //Category have all information
    File_Category << endl<< inventories[input-1] << productID << "," << stock << "," << brand << "," << product_name << "," << price << "," << size << "," << color << "," << material << "," << sport_activity_type << "," << description<< endl;
    //Inventory and All Product list has all except description
    File_Inventory << endl<< inventories[input-1] << productID << "," << stock << "," << brand << "," << product_name << "," << price << "," << size << "," << color << "," << material << "," << sport_activity_type<< endl;

    // Write data to All_Products file
    All_Product << endl<< inventories[input-1] << productID << "," << stock << "," << brand << "," << product_name << "," << price << "," << size << "," << color << "," << material << "," << sport_activity_type<< endl;

    // Close All_Products file
    File_Category.close();
    All_Product.close();
    File_Inventory.close();

    cout << "Data written to files successfully" << endl;
}

//Overloaded Operator here
istream& operator>>(istream& is, SportsAndOutdoors& sportsProduct) {

    string input;

    // input for inherited data members from Product class
    cout << "Provide Information for Sports and Outdoors Products" << endl;

    sportsProduct.setProductID("SPO104");

    cin.ignore();
    cout << "Brand : ";
    getline(is, input);
    sportsProduct.setBrand(input);

    cout << "Name : ";
    getline(is, input);
    sportsProduct.setName(input);

    cout << "Price : ";
    getline(is, input);
    sportsProduct.setPrice(stoi(input));

    //input for Sports and Outdoors data members
    cout << "Size : ";
    getline(is, input);
    sportsProduct.setSize(input);

    cout << "Color : ";
    getline(is, input);
    sportsProduct.setColor(input);

    cout << "Material : ";
    getline(is, input);
    sportsProduct.setMaterial(input);

    cout << "Sport Activity Type : ";
    getline(is, input);
    sportsProduct.setSportActivityType(input);

    cout << "Description : ";
    getline(is, input);
    sportsProduct.setDescription(input);

    return is;
}

ostream& operator<<(ostream& os, const SportsAndOutdoors& sportsProduct) {

    os << "Product ID: " << sportsProduct.getProductID() << endl;
    os << "Brand: " << sportsProduct.getBrand() << endl;
    os << "Product Name: " << sportsProduct.getName() << endl;
    os << "Price: " << sportsProduct.getPrice() << endl;
    os << "Size: " << sportsProduct.getSize() << endl;
    os << "Color: " << sportsProduct.getColor() << endl;
    os << "Material: " << sportsProduct.getMaterial() << endl;
    os << "Sport Activity Type: " << sportsProduct.getSportActivityType() << endl;
    os << "Description: " << sportsProduct.getDescription() << endl;

    return os;
}



void MedsAndHerbs::setTypeOfProduct(string type){
    this->type = type;
}
string MedsAndHerbs::getTypeOfProduct() const{
    return type;
}
void MedsAndHerbs::setDosage(string dosage){
    this->dosage = dosage;
}
string MedsAndHerbs::getDosage() const{
    return dosage;
}
void MedsAndHerbs::setExpiry(string expiry){
    this->expiry = expiry;
}
string MedsAndHerbs::getExpiry() const{
    return expiry;
}
//Write to File
void MedsAndHerbs::write(){
    // Check if all data members are empty
    if (brand.empty() || product_name.empty() || productID.empty() || description.empty() || type.empty() || dosage.empty() || expiry.empty()) {
        cout << "Please provide all necessary information before writing." << endl << "Ciao ..." << endl;
        return;
    }

    // Ask user which inventory to save data to
    cout << "Choose in Which Inventory Should your Product be saved?" << endl << "1. Karachi" << endl << "2. Lahore" << endl << "3. Islamabad" << endl << "4. Peshawar" << endl << "5. Quetta" << endl << "6.New York" << endl << "7.Dubai" << endl << endl << "Awaiting Response => ";
    int input;
    cin >> input;

    // Ask user how much stock do we have
    int stock;
    cout << "Enter stock: ";
    cin >> stock;
     
    //To Open the Specific Inventory File, matching the location user provided
    fstream File_Inventory(inventory_files[input-1],ios::app);
    if (!File_Inventory.is_open()) {
        cerr << "Error opening All_Products file for writing" << endl;
        return;
    }

    //This is fix, as we are working for the Electronic class
    fstream File_Category("Products/Categories/ELC101.txt",ios::app);
    if (!File_Category.is_open()) {
        cerr << "Error opening All_Products file for writing" << endl;
        return;
    }

    //All Product List Update
    fstream All_Product("Products/All_Product.txt");
    if (!All_Product.is_open()) {
        cerr << "Error opening All_Products file for writing" << endl;
        return;
    }

    //Category have all information
    File_Category << endl<< inventories[input-1] << productID << "," << stock << "," << brand << "," << product_name << "," << price << "," << type << "," << dosage << "," << expiry << "," << description<< endl;
    //Inventory and All Product list has all except description
    File_Inventory << endl<< inventories[input-1] << productID << "," << stock << "," << brand << "," << product_name << "," << price << "," << type << "," << dosage << "," << expiry<< endl;

    // Write data to All_Products file
    All_Product << endl<< inventories[input-1] << productID << "," << stock << "," << brand << "," << product_name << "," << price << "," << type << "," << dosage << "," << expiry<< endl;

    // Close All_Products file
    File_Category.close();
    All_Product.close();
    File_Inventory.close();

    cout << "Data written to files successfully" << endl;
}

//Overloaded Operator here
istream& operator>>(istream& is, MedsAndHerbs& medsProduct) {

    string input;

    // input for inherited data members from Product class
    cout << "Provide Information for Medicines and Herbs Products" << endl;
   
    medsProduct.setProductID("MED105");

    cin.ignore();
    cout << "Brand : ";
    getline(is, input);
    medsProduct.setBrand(input);

    cout << "Name : ";
    getline(is, input);
    medsProduct.setName(input);
    
    cout << "Price : ";
    getline(is, input);
    medsProduct.setPrice(stoi(input));

    //input for MedsAndHerbs data members
    cout << "Type : ";
    getline(is, input);
    medsProduct.setTypeOfProduct(input);

    cout << "Dosage : ";
    getline(is, input);
    medsProduct.setDosage(input);

    cout << "Expiry : ";
    getline(is, input);
    medsProduct.setExpiry(input);

    cout << "Description : ";
    getline(is, input);
    medsProduct.setDescription(input);

    return is;
}

// output operator for MedsAndHerbs class
ostream& operator<<(ostream& os, const MedsAndHerbs& medsProduct) {

    os << "Product ID: " << medsProduct.getProductID() << endl;
    os << "Brand: " << medsProduct.getBrand() << endl;
    os << "Product Name: " << medsProduct.getName() << endl;
    os << "Price: " << medsProduct.getPrice() << endl;
    os << "Type: " << medsProduct.getTypeOfProduct() << endl;
    os << "Dosage: " << medsProduct.getDosage() << endl;
    os << "Expiry: " << medsProduct.getExpiry() << endl;
    os << "Description: " << medsProduct.getDescription() << endl;

    return os;
}


void ToysAndGames::setAgeRange(string age_range){
    this->age_range = age_range;
}
string ToysAndGames::getAgeRange() const{
    return age_range;
}
void ToysAndGames::setTypeOfToyGame(string type_of_game){
    this->type_of_game = type_of_game;
}
string ToysAndGames::getTypeOfToyGame() const{
    return type_of_game;
}
void ToysAndGames::setNumberOfPlayers(int number_of_players){
    this->number_of_players = number_of_players;
}
string ToysAndGames::getNumberOfPlayers() const{
    return number_of_players;
}
//Write to file
void ToysAndGames::write(){
    // Check if all data members are empty
    if (brand.empty() || product_name.empty() || productID.empty() || description.empty() || age_range.empty() || number_of_players.empty() || type_of_game.empty()) {
        cout << "Please provide all necessary information before writing." << endl << "Ciao ..." << endl;
        return;
    }

    // Ask user which inventory to save data to
    cout << "Choose in Which Inventory Should your Product be saved?" << endl << "1. Karachi" << endl << "2. Lahore" << endl << "3. Islamabad" << endl << "4. Peshawar" << endl << "5. Quetta" << endl << "6.New York" << endl << "7.Dubai" << endl << endl << "Awaiting Response => ";
    int input;
    cin >> input;

    // Ask user how much stock do we have
    int stock;
    cout << "Enter stock: ";
    cin >> stock;
     
    //To Open the Specific Inventory File, matching the location user provided
    fstream File_Inventory(inventory_files[input-1],ios::app);
    if (!File_Inventory.is_open()) {
        cerr << "Error opening All_Products file for writing" << endl;
        return;
    }

    //This is fix, as we are working for the Electronic class
    fstream File_Category("Products/Categories/ELC101.txt",ios::app);
    if (!File_Category.is_open()) {
        cerr << "Error opening All_Products file for writing" << endl;
        return;
    }

    //All Product List Update
    fstream All_Product("Products/All_Product.txt");
    if (!All_Product.is_open()) {
        cerr << "Error opening All_Products file for writing" << endl;
        return;
    }

    //Category have all information
    File_Category << endl<< inventories[input-1] << productID << "," << stock << "," << brand << "," << product_name << "," << price << "," << age_range << "," << number_of_players << "," << type_of_game << "," << description<< endl;
    //Inventory and All Product list has all except description
    File_Inventory << endl<< inventories[input-1] << productID << "," << stock << "," << brand << "," << product_name << "," << price << "," << age_range << "," << number_of_players << "," << type_of_game<< endl;

    // Write data to All_Products file
    All_Product << endl<< inventories[input-1] << productID << "," << stock << "," << brand << "," << product_name << "," << price << "," << age_range << "," << number_of_players << "," << type_of_game<< endl;

    // Close All_Products file
    File_Category.close();
    All_Product.close();
    File_Inventory.close();

    cout << "Data written to files successfully" << endl;
}

//Overloaded Operator here
istream& operator>>(istream& is, ToysAndGames& game) {

    string input;

    // input for inherited data members from Product class
    cout << "Provide Information for Toys and Games" << endl;

    cin.ignore();
    game.setProductID("TNG106");

    cout << "Brand : ";
    getline(is, input);
    game.setBrand(input);

    cout << "Name : ";
    getline(is, input);
    game.setName(input);

    cout << "Price : ";
    getline(is, input);
    game.setPrice(stoi(input));

    // input for ToysAndGames data members
    cout << "Age Range : ";
    getline(is, input);
    game.setAgeRange(input);

    cout << "Number of Players : ";
    getline(is, input);
    game.setNumberOfPlayers(stoi(input));

    cout << "Type of Game : ";
    getline(is, input);
    game.setTypeOfToyGame(input);

    cout << "Description : ";
    getline(is, input);
    game.setDescription(input);

    return is;
}

ostream& operator<<(ostream& os, const ToysAndGames& game) {

    os << "Product ID: " << game.getProductID() << endl;
    os << "Brand: " << game.getBrand() << endl;
    os << "Product Name: " << game.getName() << endl;
    os << "Price: " << game.getPrice() << endl;
    os << "Age Range: " << game.getAgeRange() << endl;
    os << "Number of Players: " << game.getNumberOfPlayers() << endl;
    os << "Type of Game: " << game.getTypeOfToyGame() << endl;
    os << "Description: " << game.getDescription() << endl;

    return os;
}


void PetSupplies::setTypeOfProduct(string type_of_product){
    this->type_of_product = type_of_product;
}
string PetSupplies::getTypeOfProduct() const{
    return type_of_product;
}
void PetSupplies::setAnimalType(string animal_type){
    this->animal_type = animal_type;
}
string PetSupplies::getAnimalType() const{
    return animal_type;
}
void PetSupplies::setAgeRange(string age_range){
    this->age_range = age_range;
}
string PetSupplies::getAgeRange() const{
    return age_range;
}
//Wrie to file
void PetSupplies::write(){
    // Check if all data members are empty
    if (brand.empty() || product_name.empty() || productID.empty() || description.empty() || type_of_product.empty() || animal_type.empty() || age_range.empty()) {
        cout << "Please provide all necessary information before writing." << endl << "Ciao ..." << endl;
        return;
    }

    // Ask user which inventory to save data to
    cout << "Choose in Which Inventory Should your Product be saved?" << endl << "1. Karachi" << endl << "2. Lahore" << endl << "3. Islamabad" << endl << "4. Peshawar" << endl << "5. Quetta" << endl << "6.New York" << endl << "7.Dubai" << endl << endl << "Awaiting Response => ";
    int input;
    cin >> input;

    // Ask user how much stock do we have
    int stock;
    cout << "Enter stock: ";
    cin >> stock;
     
    //To Open the Specific Inventory File, matching the location user provided
    fstream File_Inventory(inventory_files[input-1],ios::app);
    if (!File_Inventory.is_open()) {
        cerr << "Error opening All_Products file for writing" << endl;
        return;
    }

    //This is fix, as we are working for the Electronic class
    fstream File_Category("Products/Categories/ELC101.txt",ios::app);
    if (!File_Category.is_open()) {
        cerr << "Error opening All_Products file for writing" << endl;
        return;
    }

    //All Product List Update
    fstream All_Product("Products/All_Product.txt");
    if (!All_Product.is_open()) {
        cerr << "Error opening All_Products file for writing" << endl;
        return;
    }

    //Category have all information
    File_Category << endl<< inventories[input-1] << productID << "," << stock << "," << brand << "," << product_name << "," << price << "," << type_of_product << "," << animal_type << "," << age_range << "," << description<< endl;
    //Inventory and All Product list has all except description
    File_Inventory  << endl<< inventories[input-1] << productID << "," << stock << "," << brand << "," << product_name << "," << price << "," << type_of_product << "," << animal_type << "," << age_range<< endl;

    // Write data to All_Products file
    All_Product << endl<< inventories[input-1] << productID << "," << stock << "," << brand << "," << product_name << "," << price << "," << type_of_product << "," << animal_type << "," << age_range<< endl;

    // Close All_Products file
    File_Category.close();
    All_Product.close();
    File_Inventory.close();

    cout << "Data written to files successfully" << endl;
}

//Overloaded Operator here
istream& operator>>(istream& is, PetSupplies& petSupplyProduct) {
    string input;

    // input for inherited data members from Product class
    cout << "Provide Information for Pet Supplies" << endl;

    petSupplyProduct.setProductID("PET107");

    cin.ignore();
    cout << "Brand : ";
    getline(is, input);
    petSupplyProduct.setBrand(input);

    cout << "Product Name : ";
    getline(is, input);
    petSupplyProduct.setName(input);

    cout << "Price : ";
    getline(is, input);
    petSupplyProduct.setPrice(stoi(input));

    // input for PetSupplies data members
    cout << "Type of Product : ";
    getline(is, input);
    petSupplyProduct.setTypeOfProduct(input);

    cout << "Animal Type : ";
    getline(is, input);
    petSupplyProduct.setAnimalType(input);

    cout << "Age Range : ";
    getline(is, input);
    petSupplyProduct.setAgeRange(input);

    cout << "Description : ";
    getline(is, input);
    petSupplyProduct.setDescription(input);

    return is;
}

ostream& operator<<(ostream& os, const PetSupplies& petSupplyProduct) {
    os << "Product ID: " << petSupplyProduct.getProductID() << endl;
    os << "Brand: " << petSupplyProduct.getBrand() << endl;
    os << "Product Name: " << petSupplyProduct.getName() << endl;
    os << "Price: " << petSupplyProduct.getPrice() << endl;
    os << "Type of Product: " << petSupplyProduct.getTypeOfProduct() << endl;
    os << "Animal Type: " << petSupplyProduct.getAnimalType() << endl;
    os << "Age Range: " << petSupplyProduct.getAgeRange() << endl;
    os << "Description: " << petSupplyProduct.getDescription() << endl;

    return os;
}


void Automotive::setModel(string model){
    this->model = model;
}
string Automotive::getModel() const{
    return model;
}
void Automotive::setYear(int year){
    this->year = year;
}
int Automotive::getYear() const{
    return year;
}
void Automotive::setVehicleType(string vehicleType){
    this->vehicleType = vehicleType;
}
string Automotive::getVehicleType() const{
    return vehicleType;
}
void Automotive::setEngineSize(int engineSize){
    this->engineSize = engineSize;
}
int Automotive::getEngineSize() const{
    return engineSize;
}
//write to file
void Automotive::write(){
    // Check if all data members are empty
    if (brand.empty() || product_name.empty() || productID.empty() || description.empty() || model.empty() || vehicleType.empty() || year == 0 || engineSize == 0 ) {
        cout << "Please provide all necessary information before writing." << endl << "Ciao ..." << endl;
        return;
    }

    // Ask user which inventory to save data to
    cout << "Choose in Which Inventory Should your Product be saved?" << endl << "1. Karachi" << endl << "2. Lahore" << endl << "3. Islamabad" << endl << "4. Peshawar" << endl << "5. Quetta" << endl << "6.New York" << endl << "7.Dubai" << endl << endl << "Awaiting Response => ";
    int input;
    cin >> input;

    // Ask user how much stock do we have
    int stock;
    cout << "Enter stock: ";
    cin >> stock;
     
    //To Open the Specific Inventory File, matching the location user provided
    fstream File_Inventory(inventory_files[input-1],ios::app);
    if (!File_Inventory.is_open()) {
        cerr << "Error opening All_Products file for writing" << endl;
        return;
    }

    //This is fix, as we are working for the Electronic class
    fstream File_Category("Products/Categories/ELC101.txt",ios::app);
    if (!File_Category.is_open()) {
        cerr << "Error opening All_Products file for writing" << endl;
        return;
    }

    //All Product List Update
    fstream All_Product("Products/All_Product.txt");
    if (!All_Product.is_open()) {
        cerr << "Error opening All_Products file for writing" << endl;
        return;
    }

    //Category have all information
    File_Category  << endl<< inventories[input-1] << productID << "," << stock << "," << brand << "," << product_name << "," << price << "," << model << "," << vehicleType << "," << year << "," << engineSize << "," << description << endl;
    //Inventory and All Product list has all except description
    File_Inventory  << endl<< inventories[input-1] << productID << "," << stock << "," << brand << "," << product_name << "," << price << "," << model << "," << vehicleType << "," << year << "," << engineSize << endl;

    // Write data to All_Products file
    All_Product  << endl<< inventories[input-1] << productID << "," << stock << "," << brand << "," << product_name << "," << price << "," << model << "," << vehicleType << "," << year << "," << engineSize << endl;

    // Close All_Products file
    File_Category.close();
    All_Product.close();
    File_Inventory.close();

    cout << "Data written to files successfully" << endl;
}

//Overloaded Operator here
istream& operator>>(istream& is, Automotive& automotiveProduct) {

    string input;

    // input for inherited data members from Product class
    cout << "Provide Information for Automotive Products" << endl;
   
    automotiveProduct.setProductID("AUT108");

    cin.ignore();
    cout << "Brand : ";
    getline(is, input);
    automotiveProduct.setBrand(input);

    cout << "Name : ";
    getline(is, input);
    automotiveProduct.setName(input);
    
    cout << "Price : ";
    getline(is, input);
    automotiveProduct.setPrice(stoi(input));

    // input for Automotive data members
    cout << "Model : ";
    getline(is, input);
    automotiveProduct.setModel(input);

    cout << "Vehicle Type : ";
    getline(is, input);
    automotiveProduct.setVehicleType(input);

    cout << "Year : ";
    getline(is, input);
    automotiveProduct.setYear(stoi(input));

    cout << "Engine Size : ";
    getline(is, input);
    automotiveProduct.setEngineSize(stoi(input));

    cout << "Description : ";
    getline(is, input);
    automotiveProduct.setDescription(input);

    return is;
}

ostream& operator<<(ostream& os, const Automotive& automotiveProduct) {

    os << "Product ID: " << automotiveProduct.getProductID() << endl;
    os << "Brand: " << automotiveProduct.getBrand() << endl;
    os << "Product Name: " << automotiveProduct.getName() << endl;
    os << "Price: " << automotiveProduct.getPrice() << endl;
    os << "Model: " << automotiveProduct.getModel() << endl;
    os << "Vehicle Type: " << automotiveProduct.getVehicleType() << endl;
    os << "Year: " << automotiveProduct.getYear() << endl;
    os << "Engine Size: " << automotiveProduct.getEngineSize() << endl;
    os << "Description: " << automotiveProduct.getDescription() << endl;

    return os;
}


//Product Class Work Starts from below
void Product::setBrand(string brand){
    this->brand = brand;
}
string Product::getBrand() const{
    return brand;
}

void Product::setName(string product_name){
    this->product_name = product_name;
}

string Product::getName() const {
    return product_name;
}

 void Product::setPrice(int price) {
    this->price = price;
 }
int Product::getPrice() const {
    return price;
}

void Product::setDescription(string description) {
    this->description = description;
}
string Product::getDescription() const {
    return description;
}
        
void Product::setProductID(string productID){
    this->productID = productID;
}
string Product::getProductID() const {
    return productID;
}

void Product::reset(){
    brand = "";
    product_name = "";
    productID = "";
    description = "";
    price = 0;
}

//Quick Buy Now, pass ID
//void Product::printProduct(int);
//Admin wants to see the whole Inventory
bool Product::checkPerson_Call(string PersonCheck){
    if(PersonCheck == "admin")
        return true;
    else
        return false;
}
//Also for the Inventory Composition Relatio
// Product* Product::print_Inventory_Products(){
// }
//Print Cart Products
//void Product::print_Cart_Products(Product[]);
//For Seller to print his products, sellewill enter his ID to view all the products his selling on out platform

void Product::search_Product(vector<Cart>& cart){
    // int count_Number_of_searched_products = 0;
    // int select_search;
    // Product *search;
    // Product *found_searchs[20];
    // int count_found_products = 0;
    // Product *searches_choosen[20];
    // int count_choosen_products = 0;
    
    vector<string> displayed_products;

    string search_product_name, search_brand_name;
    string IID, Stock, temp;
    bool product_found_check = false;
    bool check_brand = true;

    fstream file_reader_product;

    cout << "Searching for products..." << endl << "Provide Information about products" << endl;

    cin.ignore();
    cout << "Brand => ";
    getline(cin,search_brand_name);
    if(search_brand_name == "" || search_brand_name == "\n" || search_brand_name == " "){
        check_brand = false;
    }
    cout << "Name => ";
    getline(cin,search_product_name);

    cout << endl << "Let the Magic Search Begin ... " << endl << endl;


    cout << "Searching the Product : " << search_product_name << endl;

    //Algorithm to Open Multiple Files and check in each one of them
    for(int i = 0; i < 8 ; i++){
        //Opening File
        file_reader_product.open(product_files[i],ios::in);

        //Checking for File Existence
        if(!file_reader_product.is_open()){
            cerr << "Error ... " << endl << "Don't Worry it's will be fixed soon" << endl;
        }    

        //Reading Algorithm
        string line;
        istringstream read_string;
            //read_string.str(line);
        while(getline(file_reader_product,line)){
            istringstream read_string(line);

            getline(read_string >> ws, IID, ',');
            getline(read_string >> ws, productID, ',');
            getline(read_string >> ws, Stock, ',');
            getline(read_string >> ws, brand, ',');
            getline(read_string >> ws, product_name, ',');
            getline(read_string >> ws, temp, ',');
            price = stoi(temp);
            //Specific Category wise attributes can be defined here
            getline(read_string >> ws, description, '\n');

            if(check_brand){
                if(search_product_name == product_name && search_brand_name == brand){
                    product_found_check = true;
                    displayed_products.push_back(line);

                    //count_Number_of_searched_products++;
                    //cout << "Inventory ID: " << IID;
                    //cout << endl << "Product ID: " <<     PID;
                    //cout << "Stock: " << Stock;
                    // cout << "Product No. : " << count_Number_of_searched_products;
                    // cout << endl << "Brand: " << brand  << endl << "Name: " << product_name << endl  << "Price: $" << price << endl << "Description : " << description << endl;
                    
                    //break;
                }
            }
            else{
                if(search_product_name == product_name){
                    product_found_check = true;
                    displayed_products.push_back(line);

                    //count_Number_of_searched_products++;
                    //cout << "Inventory ID: " << IID;
                    //cout << endl << "Product ID: " << PID;
                    //cout << "Stock: " << Stock;

                    //Will Use it with the Found Searched Product
                    // cout << "Product No. : " << count_Number_of_searched_products;
                    // cout << endl << "Brand: " << brand << endl << "Name: " << product_name << endl << "Price: $" << price << endl << "Description : " << description << endl;

                    //break;
                }
            }
        }

        file_reader_product.close();

        // if(product_found_check){
        //     search->setProductID(productID);
        //     search->setBrand(brand);
        //     search->setName(product_name);
        //     search->setPrice(price);
        //     search->setDescription(description);

        //     found_searchs[count_found_products] = search;
        //     count_found_products++;
        // }
        // product_found_check = false;
    }

    // cout << "Found Following Products ..." << endl;
    // for(int i = 0; i < count_found_products ; i++){
    //     cout << "Product No. : " << count_Number_of_searched_products;
    //     cout << endl << "Brand: " << found_searchs[i]->brand << endl << "Name: " << found_searchs[i]->product_name << endl << "Price: $" << found_searchs[i]->price << endl << "Description : " << found_searchs[i]->description << endl;
    // }
    
    if(!product_found_check){
        cout << endl << "Sorry, We couldn't find your product" << endl << "Checkout Influx next week when new stock arrives," << endl << "You might find what you are looking for" << endl << "Ciao..." << endl << endl;
    }

    for(int i = 0 ; i < displayed_products.size() ; i++){
        cout << i+1 << ". " << displayed_products[i] << endl;
    }

    //Testing Code
    // cout << "Calling by the Search Ptr : " << endl;
    // cout << endl << "Product ID : " << search->getProductID() << endl << "Brand : " << search->getBrand()<< endl << "Name : " << search->getName()<< endl << "Price : " << search->getPrice();

    // update_Collected_Products(displayed_products,gather_cart,product_info);

    vector<Data> indexes;
    vector<Product> Products = extract_Product_INFO(displayed_products);

    cout << "Products Found Are... " << endl << endl;
    cout << "Do you Want to put Searched Products in Your Cart?"<< endl;
    cout << "Awainting Response =>  ";

    char choice;
    cin >> choice;
    if(choice == 'Y' || choice == 'y'){
        for(int i = 0 ; i < Products.size() ; i++){
            cout << i+1 << ". " << Products[i] << endl;
        }

        cout << endl << endl;

        cout << "Enter -1 TO EXIT PUT TO CART MODE." << endl;
        for(int i = 0 ; i < Products.size() ; i++){
            cout << "Enter the Serial Number of the Products : ";
            cin >> indexes[i].index;
            if(indexes[i].index == -1){
                cout << "Exiting Search Mode." << endl;

                break;
            }
            if(indexes[i].index  > Products.size() || indexes[i].index <= 0){
                cout << "Please Check Again...\n The Provided input was wrong..." << endl;

                continue;
            }
            cout << "Enter the Quantity : ";
            cin >> indexes[i].quantity;
            if(indexes[i].quantity  > Products.size() || indexes[i].quantity <= 0){
                cout << "Please Check Again...\n The Provided input was wrong..." << endl;

                continue;
            }
        }
        
        Cart temp;
        for(int i = 0; i < Products.size(); i++){
            temp.quantity = indexes[i].quantity;
            temp.product = Products[i];

            cart.push_back(temp);
        }
    }
    if(choice == 'N' || choice == 'n'){
        return;
    }

    return;
    //delete the search object where its called, after the use of search object,.
}


//Chat Bro Work
/*
Product* searchProduct() {
    cout << "Searching for products..." << endl << "Provide Information about products" << endl;

    string search_brand_name, search_product_name;

    cout << "Brand => ";
    getline(cin, search_brand_name);
    if (search_brand_name.empty()) {
        search_brand_name = "";
    }

    cout << "Name => ";
    getline(cin, search_product_name);

    cout << endl << "Let the Magic Search Begin ... " << endl << endl;

    cout << "Searching the Product : " << search_product_name << endl;

    const int MAX_FOUND_PRODUCTS = 100;
    Product* found_products[MAX_FOUND_PRODUCTS];
    int count_found_products = 0;

    for (int i = 0; i < 8; i++) {
        fstream file_reader_product(product_files[i], ios::in);

        if (!file_reader_product.is_open()) {
            cerr << "Error ... " << endl << "Don't Worry it's will be fixed soon" << endl;
            continue;
        }

        string line;
        while (getline(file_reader_product, line)) {
            istringstream read_string(line);

            string IID, productID, Stock, brand, product_name, temp, description;
            int price;

            getline(read_string >> ws, IID, ',');
            getline(read_string >> ws, productID, ',');
            getline(read_string >> ws, Stock, ',');
            getline(read_string >> ws, brand, ',');
            getline(read_string >> ws, product_name, ',');
            getline(read_string >> ws, temp, ',');
            price = stoi(temp);
            getline(read_string >> ws, description, '\n');

            if (search_brand_name.empty() || search_brand_name == brand) {
                if (search_product_name == product_name) {
                    Product* search = new Product();
                    search->setProductID(productID);
                    search->setBrand(brand);
                    search->setName(product_name);
                    search->setPrice(price);
                    search->setDescription(description);

                    found_products[count_found_products] = search;
                    count_found_products++;
                }
            }
        }

        file_reader_product.close();
    }

    if (count_found_products == 0) {
        cout << "Sorry, no products found matching your search criteria." << endl;
        return nullptr;
    }
    else {
        cout << "Number of products found : " << count_found_products << endl;

        Product* chosen_products[MAX_FOUND_PRODUCTS];
        int count_chosen_products = 0;

        while (true) {
            cout << endl << "Do you want to add any of the above products to your cart? (y/n): ";
            char response;
            cin >> response;

            if (response == 'n' || response == 'N') {
                break;
            }
            else if (response == 'y' || response == 'Y') {
                int product_choice;
                cout << endl << "Enter the number of the product you would like to add to your cart: ";
                cin >> product_choice;
                if (product_choice <= 0 || product_choice > count_found_products) {
                    cout << "Invalid product choice. Please try again." << endl;
                    continue;
                }
                else {
                    chosen_products[count_chosen_products] = found_products[product_choice - 1];
                    count_chosen_products++;
                    cout << "Product added to cart." << endl;
                }
            }
            else {
                cout << "Invalid response. Please try again." << endl;
            }
        }

        if (count_chosen_products == 0) {
            cout << "No products added to cart." << endl;
            return nullptr;
        }
        else {
            cout << "Number of products added to cart: " << count_chosen_products << endl;

            // create cart object
            Cart* cart = new Cart();

            // add chosen products to cart
            for (int i = 0; i < count_chosen_products; i++) {
                cart->addProduct(chosen_products[i]);
            }

            return cart;
        }
    }
}
*/
/*
Product** Product::search_Product(){
    int count_Number_of_searched_products = 0;
    Product* search;
    Product** found_searchs = new Product*[20];
    int count_found_products = 0;
    string search_product_name, search_brand_name;
    string IID, Stock, temp;
    bool product_found_check = false;
    bool check_brand = true;

    cout << "Searching for products..." << endl << "Provide Information about products" << endl;

    do {
        cin.ignore();
        cout << "Brand => ";
        getline(cin, search_brand_name);
    } while (search_brand_name.empty() || std::all_of(search_brand_name.begin(), search_brand_name.end(), ::isspace));

    do {
        cout << "Name => ";
        getline(cin, search_product_name);
    } while (search_product_name.empty() || std::all_of(search_product_name.begin(), search_product_name.end(), ::isspace));

    cout << endl << "Let the Magic Search Begin ... " << endl << endl;


    cout << "Searching the Product : " << search_product_name << endl;

    //Algorithm to Open Multiple Files and check in each one of them
    for (int i = 0; i < 8; i++) {
        //Opening File
        fstream file_reader_product(product_files[i], ios::in);

        //Checking for File Existence
        if (!file_reader_product.is_open()) {
            cerr << "Error: Could not open file: " << product_files[i] << endl;
            continue;
        }

        //Reading Algorithm
        string line;
        while (getline(file_reader_product, line)) {
            istringstream read_string(line);

            getline(read_string >> ws, IID, ',');
            getline(read_string >> ws, productID, ',');
            getline(read_string >> ws, Stock, ',');
            getline(read_string >> ws, brand, ',');
            getline(read_string >> ws, product_name, ',');
            getline(read_string >> ws, temp, ',');
            price = stoi(temp);
            //Specific Category wise attributes
            //Prompting user to select products
            vector<Product*> searches_choosen;
            char user_choice = ' ';
            while (user_choice != 'N') {
                cout << "Do you want to select any of these products? (Y/           N): ";
                cin >> user_choice;
                if (user_choice == 'Y') {
                    int product_number;
                    cout << "Enter the product number you want to           select: ";
                    cin >> product_number;
                    if (product_number > 0 && product_number <= count_found_products) {
                        searches_choosen.push_back(found_searchs            [product_number - 1]);
                    }
                    else {
                        cout << "Invalid product number, please try             again." << endl;
                    }
                }
            }

            //Displaying the selected products
            cout << "Selected products: " << endl;
            for (int i = 0; i < searches_choosen.size(); i++) {
                cout << "Product No. : " << i + 1;
                cout << endl << "Brand: " << searches_choosen[i]->brand             << endl << "Name: " << searches_choosen[i]->product_name            << endl;
            }
        }
            //Returning the selected products
    }
    return searches_choosen;
}
    //use of fstream to read and display the product
    //go through all the product files and print them all
    //Empty not printing anything for now
*/
    //one implementation of this function is build in the Electronics Class

//string Product::getProduct();

//From Inventory, Product Manipulation
//Check Person First, for Admin ONLY
//checkPerosn_Call() can be utilized here too

//before calling this call getter for seller id and pass it as a parameter to this function

//Trying to Paste the Data here


void Product::setProduct(){
    
    cout << "Select from the Following Categories," << endl << "1. Electronics" << endl << "2. Fashion" << endl << "3. Beauty and Personal Care" << endl << "4. Sports and Outdoors" << endl << "5. Medicine" << endl << "7. Toys and Games" << endl << "8. Automative" << endl << endl << "Awaiting Response => ";
    
    int input;
    while(1){
        cin >> input;
        if(input <= 0 || input > 8){
            cout << endl << "Invalid Input ... " << endl << "Please Choose Correctly from above mentioned Categories" << endl << endl;
        }
        if(input > 0 || input < 8){
            break;
        }
    }

    if(input == 1){
        Electronics products;
        cin >> products;
        products.write();
    }
    if(input == 2){
        Fashion products;
        cin >> products;
        products.write();
    }
    if(input == 3){
        BeautyAndPersonalCare products;
        cin >> products;
        products.write();
    }
    if(input == 4){
        SportsAndOutdoors products;
        cin >> products;
        products.write();
    }
    if(input == 5){
        MedsAndHerbs products;
        cin >> products;
        products.write();
    }
    if(input == 6){
        ToysAndGames products;
        cin >> products;
        products.write();
    }
    if(input == 7){
        PetSupplies products;
        cin >> products;
        products.write();
    }
    if(input == 8){
        Automotive products;
        cin >> products;
        products.write();
    }
    
    //product->setProduct();

    cout << endl << endl << "Product Has Been Successfully listed in Influx Database, Thank You for being a Part of Influx and Keep Influx Going for greater Good..." << endl << "Ciao..." << endl;

    return;
    //delete product;
}
/*
void Electronics::setProduct(){
    int stock;
    //inherited
    //string brand, name, description;
    //int price;
    //Will set with string array
    //PID, IID
    //Class Owned
    //string model;
    //int screen_size, RAM, storage_capacity;

    //cout << "Right Now inside the Electoronics Working";

    //string categories[8] = { "ELC101", "FSH102", "BPC103", "SPO104", "HLW105", "TNG106", "PET107", "AUT108"};

    cout << "Select The Location of the Available Stock" << endl << "1. Karachi" << endl << "2. Lahore" << endl << "3. Islamabad" << endl << "4. Peshawar" << endl << "5. Quetta" << endl << "6. New York" << endl<< "8. Dubai" << endl << "Waiting for Response => ";

    int input_inventory;
    cin >> input_inventory;

    //To Open the Specific Inventory File, matching the location user provided
    fstream File_Inventory(inventory_files[input_inventory-1],ios::app);

    //This is fix, as we are working for the Electronic class
    fstream File_Category("Products/Categories/ELC101.txt",ios::app);

    //All Product List Update
    fstream All_Product("Products/All_Product.txt");

    cout << "Please provide Following Information Regarding Your Product" << endl;
    
    //cout << "Waiting for Input => " ;

    //Will need to declare and pass the varaibles as a parameter
    cout << "How much Stock are you selling? ";
    cin >> stock;

    cin.ignore();
    cout << "Brand of the Product => ";
    getline(cin,brand);

    cout << "Name of the Product => ";
    getline(cin,product_name);

    cout << "Price of the Product => ";
    cin >> price;

    cin.ignore();
    cout << "Model Name => ";
    getline(cin,model);

    cout << "Screen Size (if product doesn't have it, type 0) =>  ";
    cin >> screen_size;

    cout << "How much RAM is it (if product doesn't have it, type 0) =>  ";
    cin >> RAM;
    
    cout << "Storage Capacity of Product (if product doesn't have it, type 0) =>  ";
    cin >> storage_capacity;

    cin.ignore();
    cout << "A Short Description(Highlighting features) =>  ";
    getline(cin,description);

    //Category have all information
    File_Category << inventories[input_inventory-1] << ",ELC101," << stock << "," << brand << "," << product_name << "," << price << "," << model << "," << screen_size << "," << RAM << "," << storage_capacity << "," << description;
    //Inventory and All Product list has all except description
    File_Inventory << inventories[input_inventory-1] << ",ELC101," << stock << "," << brand << "," << product_name << "," << price << "," << model << "," << screen_size << "," << RAM << "," << storage_capacity;

    All_Product << inventories[input_inventory-1] << ",ELC101," << stock << "," << brand << "," << product_name << "," << price << "," << model << "," << screen_size << "," << RAM << "," << storage_capacity;

    File_Category.close();
    File_Inventory.close();
    All_Product.close();
}

void Fashion::setProduct(){
    int stock;
    //inherited
    //string brand, name, description;
    //int price;
    //Will set with string array
    //PID, IID
    //Class Owned
    //string model;
    //int screen_size, RAM, storage_capacity;

    //cout << "Right Now inside the Electoronics Working";

    //string categories[8] = { "ELC101", "FSH102", "BPC103", "SPO104", "HLW105", "TNG106", "PET107", "AUT108"};

    cout << "Select The Location of the Available Stock" << endl << "1. Karachi" << endl << "2. Lahore" << endl << "3. Islamabad" << endl << "4. Peshawar" << endl << "5. Quetta" << endl << "6. New York" << endl<< "8. Dubai" << endl << "Waiting for Response => ";

    int input_inventory;
    cin >> input_inventory;

    //To Open the Specific Inventory File, matching the location user provided
    fstream File_Inventory(inventory_files[input_inventory-1],ios::app);

    //This is fix, as we are working for the Electronic class
    fstream File_Category("Products/Categories/FSH102.txt",ios::app);
    //All Product List Update
    fstream All_Product("Products/All_Product.txt");

    cout << "Please provide Following Information Regarding Your Product" << endl;
    
    //cout << "Waiting for Input => " ;

    //Will need to declare and pass the varaibles as a parameter
    cout << "How much Stock are you selling? ";
    cin >> stock;

    cin.ignore();
    cout << "Brand of the Product => ";
    getline(cin,brand);

    cout << "Name of the Product => ";
    getline(cin,product_name);

    cout << "Price of the Product => ";
    cin >> price;

    cin.ignore();
    cout << "Size => ";
    getline(cin,size);

    cout << "Color =>  ";
    getline(cin,color);

    cout << "Material =>  ";
    getline(cin,material);
    
    cout << "Style =>  ";
    getline(cin,style);

    cout << "A Short Description(Highlighting features) =>  ";
    getline(cin,description);

    //Category have all information
    File_Category<< inventories[input_inventory-1] << ",FSH102," << stock << "," << brand << "," << product_name << "," << price << "," << size << "," << color << "," << material << "," << style << "," << description;
    //Inventory and All Product list has all except description
    File_Inventory << inventories[input_inventory-1] << ",FSH102," << stock << "," << brand << "," << product_name << "," << price << "," << size << "," << color << "," << material << "," << style;

    All_Product << inventories[input_inventory-1] << ",FSH102," << stock << "," << brand << "," << product_name << "," << price << "," << size << "," << color << "," << material << "," << style;

    File_Category.close();
    File_Inventory.close();
    All_Product.close();
}

void BeautyAndPersonalCare::setProduct(){
    int stock;
    //inherited
    //string brand, name, description;
    //int price;
    //Will set with string array
    //PID, IID
    //Class Owned
    //string model;
    //int screen_size, RAM, storage_capacity;

    //cout << "Right Now inside the Electoronics Working";

    //string categories[8] = { "ELC101", "FSH102", "BPC103", "SPO104", "HLW105", "TNG106", "PET107", "AUT108"};

    cout << "Select The Location of the Available Stock" << endl << "1. Karachi" << endl << "2. Lahore" << endl << "3. Islamabad" << endl << "4. Peshawar" << endl << "5. Quetta" << endl << "6. New York" << endl<< "8. Dubai" << endl << "Waiting for Response => ";

    int input_inventory;
    cin >> input_inventory;

    //To Open the Specific Inventory File, matching the location user provided
    fstream File_Inventory(inventory_files[input_inventory-1],ios::app);

    //This is fix, as we are working for the Electronic class
    fstream File_Category("Products/Categories/BPC103.txt",ios::app);

    //All Product List Update
    fstream All_Product("Products/All_Product.txt");

    cout << "Please provide Following Information Regarding Your Product" << endl;
    
    //cout << "Waiting for Input => " ;

    //Will need to declare and pass the varaibles as a parameter
    cout << "How much Stock are you selling? ";
    cin >> stock;

    cin.ignore();
    cout << "Brand of the Product => ";
    getline(cin,brand);

    cout << "Name of the Product => ";
    getline(cin,product_name);

    cout << "Price of the Product => ";
    cin >> price;

    cin.ignore();
    cout << "Type of Product => ";
    getline(cin,type_of_product);

    cout << "Ingredients =>  ";
    getline(cin,ingredients);

    cout << "Skin Hair Type =>  ";
    getline(cin,skin_hair_type);
    
    cout << "Scent =>  ";
    getline(cin,scent);

    cout << "A Short Description(Highlighting features) =>  ";
    getline(cin,description);

    //Category have all information
    File_Category<< inventories[input_inventory-1] << ",BPC103," << stock << "," << brand << "," << product_name << "," << price << "," << type_of_product << "," << ingredients << "," << skin_hair_type << "," << scent << "," << description;
    //Inventory and All Product list has all except description
    File_Inventory << inventories[input_inventory-1] << ",BPC103," << stock << "," << brand << "," << product_name << "," << price << "," << type_of_product << "," << ingredients << "," << skin_hair_type << "," << scent;

    All_Product << inventories[input_inventory-1] << ",BPC103," << stock << "," << brand << "," << product_name << "," << price << "," << type_of_product << "," << ingredients << "," << skin_hair_type << "," << scent;

    File_Category.close();
    File_Inventory.close();
    All_Product.close();
}

void SportsAndOutdoors::setProduct(){
    int stock;
    //inherited
    //string brand, name, description;
    //int price;
    //Will set with string array
    //PID, IID
    //Class Owned
    //string model;
    //int screen_size, RAM, storage_capacity;

    //cout << "Right Now inside the Electoronics Working";

    //string categories[8] = { "ELC101", "FSH102", "BPC103", "SPO104", "HLW105", "TNG106", "PET107", "AUT108"};

    cout << "Select The Location of the Available Stock" << endl << "1. Karachi" << endl << "2. Lahore" << endl << "3. Islamabad" << endl << "4. Peshawar" << endl << "5. Quetta" << endl << "6. New York" << endl<< "8. Dubai" << endl << "Waiting for Response => ";

    int input_inventory;
    cin >> input_inventory;

    //To Open the Specific Inventory File, matching the location user provided
    fstream File_Inventory(inventory_files[input_inventory-1],ios::app);

    //This is fix, as we are working for the Electronic class
    fstream File_Category("Products/Categories/SPO104.txt",ios::app);

    //All Product List Update
    fstream All_Product("Products/All_Product.txt");

    cout << "Please provide Following Information Regarding Your Product" << endl;
    
    //cout << "Waiting for Input => " ;

    //Will need to declare and pass the varaibles as a parameter
    cout << "How much Stock are you selling? ";
    cin >> stock;

    cin.ignore();
    cout << "Brand of the Product => ";
    getline(cin,brand);

    cout << "Name of the Product => ";
    getline(cin,product_name);

    cout << "Price of the Product => ";
    cin >> price;

    cin.ignore();
    cout << "Size => ";
    getline(cin,size);

    cout << "Color =>  ";
    getline(cin,color);

    cout << "Material =>  ";
    getline(cin,material);
    
    cout << "Sports Activity Type =>  ";
    getline(cin,sport_activity_type);

    cout << "A Short Description(Highlighting features) =>  ";
    getline(cin,description);

    //Category have all information
    File_Category << inventories[input_inventory-1] << ",SPO104," << stock << "," << brand << "," << product_name << "," << price << "," << size << "," << color << "," << material << "," << sport_activity_type << "," << description;
    //Inventory and All Product list has all except description
    File_Inventory << inventories[input_inventory-1] << ",SPO104," << stock << "," << brand << "," << product_name << "," << price << "," << size << "," << color << "," << material << "," << sport_activity_type;

    All_Product << inventories[input_inventory-1] << ",SPO104," << stock << "," << brand << "," << product_name << "," << price << "," << size << "," << color << "," << material << "," << sport_activity_type;

    File_Category.close();
    File_Inventory.close();
    All_Product.close();
}

void MedsAndHerbs::setProduct(){
    int stock;
    //inherited
    //string brand, name, description;
    //int price;
    //Will set with string array
    //PID, IID
    //Class Owned
    //string model;
    //int screen_size, RAM, storage_capacity;

    //cout << "Right Now inside the Electoronics Working";

    //string categories[8] = { "ELC101", "FSH102", "BPC103", "SPO104", "HLW105", "TNG106", "PET107", "AUT108"};

    cout << "Select The Location of the Available Stock" << endl << "1. Karachi" << endl << "2. Lahore" << endl << "3. Islamabad" << endl << "4. Peshawar" << endl << "5. Quetta" << endl << "6. New York" << endl<< "8. Dubai" << endl << "Waiting for Response => ";

    int input_inventory;
    cin >> input_inventory;

    //To Open the Specific Inventory File, matching the location user provided
    fstream File_Inventory(inventory_files[input_inventory-1],ios::app);

    //This is fix, as we are working for the Electronic class
    fstream File_Category("Products/Categories/MED105.txt",ios::app);

    //All Product List Update
    fstream All_Product("Products/All_Product.txt");

    cout << "Please provide Following Information Regarding Your Product" << endl;
    
    //cout << "Waiting for Input => " ;

    //Will need to declare and pass the varaibles as a parameter
    cout << "How much Stock are you selling? ";
    cin >> stock;

    cin.ignore();
    cout << "Brand of the Product => ";
    getline(cin,brand);

    cout << "Name of the Product => ";
    getline(cin,product_name);

    cout << "Price of the Product => ";
    cin >> price;

    cin.ignore();
    cout << "Type => ";
    getline(cin,type);

    cout << "Dosage =>  ";
    getline(cin,dosage);

    cout << "Expiry (MM/YY this format is recommended) =>  ";
    getline(cin,expiry);

    cout << "A Short Description(Highlighting features) =>  ";
    getline(cin,description);

    //Category have all information
    File_Category << inventories[input_inventory-1] << ",MED105," << stock << "," << brand << "," << product_name << "," << price << "," << type << "," << dosage << "," << expiry << "," << description;
    //Inventory and All Product list has all except description
    File_Inventory<< inventories[input_inventory-1] << ",MED105," << stock << "," << brand << "," << product_name << "," << price << "," << type << "," << dosage << "," << expiry;

    All_Product << inventories[input_inventory-1] << ",MED105," << stock << "," << brand << "," << product_name << "," << price << "," << type << "," << dosage << "," << expiry;

    File_Category.close();
    File_Inventory.close();
    All_Product.close();
}

void ToysAndGames::setProduct(){
    int stock;
    //inherited
    //string brand, name, description;
    //int price;
    //Will set with string array
    //PID, IID
    //Class Owned
    //string model;
    //int screen_size, RAM, storage_capacity;

    //cout << "Right Now inside the Electoronics Working";

    //string categories[8] = { "ELC101", "FSH102", "BPC103", "SPO104", "HLW105", "TNG106", "PET107", "AUT108"};

    cout << "Select The Location of the Available Stock" << endl << "1. Karachi" << endl << "2. Lahore" << endl << "3. Islamabad" << endl << "4. Peshawar" << endl << "5. Quetta" << endl << "6. New York" << endl<< "8. Dubai" << endl << "Waiting for Response => ";

    int input_inventory;
    cin >> input_inventory;

    //To Open the Specific Inventory File, matching the location user provided
    fstream File_Inventory(inventory_files[input_inventory-1],ios::app);

    //This is fix, as we are working for the Electronic class
    fstream File_Category("Products/Categories/TNG106.txt",ios::app);

    //All Product List Update
    fstream All_Product("Products/All_Product.txt");

    cout << "Please provide Following Information Regarding Your Product" << endl;
    
    //cout << "Waiting for Input => " ;

    //Will need to declare and pass the varaibles as a parameter
    cout << "How much Stock are you selling? ";
    cin >> stock;

    cin.ignore();
    cout << "Brand of the Product => ";
    getline(cin,brand);

    cout << "Name of the Product => ";
    getline(cin,product_name);

    cout << "Price of the Product => ";
    cin >> price;

    cin.ignore();
    cout << "Size => ";
    getline(cin,age_range);

    cout << "Number of Players =>  ";
    getline(cin,number_of_players);

    cout << "Type of Game (Toy, Arts, Digital) =>  ";
    getline(cin,type_of_game);

    cout << "A Short Description(Highlighting features) =>  ";
    getline(cin,description);

    //Category have all information
    File_Category<< inventories[input_inventory-1] << ",TNG106," << stock << "," << brand << "," << product_name << "," << price << "," << age_range << "," << number_of_players << "," << type_of_game << "," << description;
    //Inventory and All Product list has all except description
    File_Inventory << inventories[input_inventory-1] << ",TNG106," << stock << "," << brand << "," << product_name << "," << price << "," << age_range << "," << number_of_players << "," << type_of_game;

    All_Product << inventories[input_inventory-1] << ",TNG106," << stock << "," << brand << "," << product_name << "," << price << "," << age_range << "," << number_of_players << "," << type_of_game;

    File_Category.close();
    File_Inventory.close();
    All_Product.close();
}

void PetSupplies::setProduct(){
    int stock;
    //inherited
    //string brand, name, description;
    //int price;
    //Will set with string array
    //PID, IID
    //Class Owned
    //string model;
    //int screen_size, RAM, storage_capacity;

    //cout << "Right Now inside the Electoronics Working";

    //string categories[8] = { "ELC101", "FSH102", "BPC103", "SPO104", "HLW105", "TNG106", "PET107", "AUT108"};

    cout << "Select The Location of the Available Stock" << endl << "1. Karachi" << endl << "2. Lahore" << endl << "3. Islamabad" << endl << "4. Peshawar" << endl << "5. Quetta" << endl << "6. New York" << endl<< "8. Dubai" << endl << "Waiting for Response => ";

    int input_inventory;
    cin >> input_inventory;

    //To Open the Specific Inventory File, matching the location user provided
    fstream File_Inventory(inventory_files[input_inventory-1],ios::app);

    //This is fix, as we are working for the Electronic class
    fstream File_Category("Products/Categories/PET107.txt",ios::app);

    //All Product List Update
    fstream All_Product("Products/All_Product.txt");

    cout << "Please provide Following Information Regarding Your Product" << endl;
    
    //cout << "Waiting for Input => " ;

    //Will need to declare and pass the varaibles as a parameter
    cout << "How much Stock are you selling? ";
    cin >> stock;

    cin.ignore();
    cout << "Brand of the Product => ";
    getline(cin,brand);

    cout << "Name of the Product => ";
    getline(cin,product_name);

    cout << "Price of the Product => ";
    cin >> price;

    cin.ignore();
    cout << "Type of Product => ";
    getline(cin,type_of_product);
    
    cout << "Animal Type =>  ";
    getline(cin,animal_type);
    
    cout << "Age Range =>  ";
    getline(cin,age_range);

    cout << "A Short Description(Highlighting features) =>  ";
    getline(cin,description);

    //Category have all information
    File_Category << inventories[input_inventory-1] << ",PET107," << stock << "," << brand << "," << product_name << "," << price << "," << type_of_product << "," << animal_type << "," << age_range << "," << description;
    //Inventory and All Product list has all except description
    File_Inventory << inventories[input_inventory-1] << ",PET107," << stock << "," << brand << "," << product_name << "," << price << "," << type_of_product << "," << animal_type << "," << age_range;

    All_Product << inventories[input_inventory-1] << ",PET107," << stock << "," << brand << "," << product_name << "," << price << "," << type_of_product << "," << animal_type << "," << age_range;

    File_Category.close();
    File_Inventory.close();
    All_Product.close();
}

void Automotive::setProduct(){
    int stock;
    //inherited
    //string brand, name, description;
    //int price;
    //Will set with string array
    //PID, IID
    //Class Owned
    //string model;
    //int screen_size, RAM, storage_capacity;

    //cout << "Right Now inside the Electoronics Working";

    //string categories[8] = { "ELC101", "FSH102", "BPC103", "SPO104", "HLW105", "TNG106", "PET107", "AUT108"};

    cout << "Select The Location of the Available Stock" << endl << "1. Karachi" << endl << "2. Lahore" << endl << "3. Islamabad" << endl << "4. Peshawar" << endl << "5. Quetta" << endl << "6. New York" << endl<< "8. Dubai" << endl << "Waiting for Response => ";

    int input_inventory;
    cin >> input_inventory;

    //To Open the Specific Inventory File, matching the location user provided
    fstream File_Inventory(inventory_files[input_inventory-1],ios::app);

    //This is fix, as we are working for the Electronic class
    fstream File_Category("Products/Categories/AUT108.txt",ios::app);

    //All Product List Update
    fstream All_Product("Products/All_Product.txt");

    cout << "Please provide Following Information Regarding Your Product" << endl;
    
    //cout << "Waiting for Input => " ;

    //Will need to declare and pass the varaibles as a parameter
    cout << "How much Stock are you selling? ";
    cin >> stock;

    cin.ignore();
    cout << "Brand of the Product => ";
    getline(cin,brand);

    cout << "Name of the Product => ";
    getline(cin,product_name);

    cout << "Price of the Product => ";
    cin >> price;

    cin.ignore();
    cout << "Model => ";
    getline(cin,model);

    cout << "Vehicle Type =>  ";
    getline(cin,vehicleType);

    cout << "Year =>  ";
    cin >> year;
    
    cout << "Engine Size =>  ";
    cin >> engineSize;

    cout << "A Short Description(Highlighting features) =>  ";
    getline(cin,description);

    //Category have all information
    File_Category << inventories[input_inventory-1] << ",AUT108," << stock << "," << brand << "," << product_name << "," << price << "," << model << "," << vehicleType << "," << year << "," << engineSize << "," << description;
    //Inventory and All Product list has all except description
    File_Inventory << inventories[input_inventory-1] << ",AUT108," << stock << "," << brand << "," << product_name << "," << price << "," << model << "," << vehicleType << "," << year << "," << engineSize;

    All_Product << inventories[input_inventory-1] << ",AUT108," << stock << "," << brand << "," << product_name << "," << price << "," << model << "," << vehicleType << "," << year << "," << engineSize;

    File_Category.close();
    File_Inventory.close();
    All_Product.close();
}
*/

//Function Requirement not implemented
//MAY DROP THIS IDEA TOO
// void Product::print_Seller_products(int sellerID){
//     //matching items to that seller id will get printed out

// }

// vector<string> split( string& str, char stoppingVantage) {
//     vector<string> FullLine;
//     string partOfLine;
//     istringstream file_reader(str);
//     //Reads Part of the Line till the Stopping Vantage point which in our case is Comma Separator ,
//     while (getline(file_reader, partOfLine, stoppingVantage)) {
//         FullLine.push_back(partOfLine);
//     }
//     return FullLine;
// }

bool sortByIndex(const Data &a, const Data &b) {
    return a.index < b.index;
}

//This View Product Have the Filter Effect too for inventories.
void Product::update_Collected_Products(vector<string>& displayed_products, vector<string>& gather_cart, vector<Data>& product_info){

    //vector<int> store_index;
    //vector<Data> product_info;
    Data take_input;

    char choice;

    cout << endl << endl << "[Y] Add Products To Cart\t[N] Go Back\nAwating Response => ";
    cin >> choice;
    if(choice == 'Y' || choice == 'y'){
        cout << endl;
        cout << "You See Something You Like, Naughty Are Yah ..." << endl << "Amigo, Just Tell us It's Serial Number" << endl << "It will be added to your Cart" << endl << endl;
        cout << "WHEN YOU ARE DONE SELECTING THE PRODUCTS, YOU MUST ENTER -1 TO CONTINUE." << endl << endl;

        while(true) {
            cout << "Add to my Cart, item of Serial Number => ";
            cin >> take_input.index;
            if (take_input.index == -1) {
                cout << endl;
                cout << "Done with the Selection of Products, I see" << endl << "Visit Other Product Categories" << endl << "There Might be Something for a Man of Culture Like You ..." << endl << endl;

                break;  // Exit the loop if user enters -1
            }
            if(take_input.index > displayed_products.size() || take_input.index <= 0){
                cout << endl;
                cout << "Oh Dear, You Accidently Enter Wrong Serial Number" << endl << "Please Check and try again ..." << endl << endl;

                continue;
            }
            
            cout << "Enter the Quantity of Product =>  ";
            cin >> take_input.quantity;
            if(take_input.quantity <= 0){
                cout << "Oh Dear, You Accidently Enter Undefined Quantity" << endl << "Please Check and try again ..." << endl << endl;
                continue;
            }
            else{
                  // Add the input to    the vector
                product_info.push_back(take_input);

                cout << "\tProduct Successfully Added to your Cart" << endl << endl;
            }
        }  


        cout << "Cart Has Been Updated" << endl ;
        
        
        sort(product_info.begin(), product_info.end(), sortByIndex);

        // for(int i = 0; i < product_info.size() ; i++){
        //     cout << i+1 << ". " << product_info[i].index << " | " << product_info[i].quantity << endl;
        // } 

        vector<string> filtered_products;
        for (int i = 0; i < product_info.size(); i++) {
            int index = product_info[i].index - 1;
            if (index >= 0 && index < displayed_products.size()) {
                filtered_products.push_back(displayed_products[index]);
            }
        }

        // Replace the displayed_products vector with the filtered vector
        displayed_products = filtered_products;

        // for(int i = 0; i < displayed_products.size() ; i++){
        //     cout << i+1 << ". " << displayed_products[i] << endl;
        // } 
        
        //Clearing and Releasing the Memory Occupied by the FilterVector
        filtered_products.clear();
        vector<string>().swap(filtered_products);

        gather_cart.insert(gather_cart.end(), displayed_products.begin(), displayed_products.end());

        //release the memory occupied by this vector
        displayed_products.clear();        vector<string>().swap(displayed_products);

        // cout << "Products in gether_cart are" << endl;

        // for(int i = 0; i < gather_cart.size() ; i++){
        //     cout << i+1 << ". " << gather_cart[i] << endl;
        // } 

        return;
    }
    if(choice == 'N' || choice == 'n'){
        //To clear the vector and free the memory
        displayed_products.clear();
        vector<string>().swap(displayed_products);
        return;
    }
}

void Product::theCart(vector<Product>& Products,vector<Data>& product_info, vector<Cart>& cart){
    //Data/product_info is going to provide quantity
    //Product/Products is going to provide product itself
    //Cart/cart is going to store these two info in itself

    Cart store_cart;
    for(int i = 0 ; i < Products.size() ; i++){
        //i will be used iterate over product
        store_cart.product = Products[i];
        store_cart.quantity = product_info[i].quantity;

        cart.push_back(store_cart);
    }
    
    return;
}

void Product::view_Product(vector<Cart>& cart){
    // string product_files[8] = {"Products/Categories/ELC101.txt","Products/Categories/FSH102.txt","Products/Categories/BPC103.txt","Products/Categories/SPO104.txt","Products/Categories/MED105.txt","Products/Categories/TNG106.txt","Products/Categories/PET107.txt","Products/Categories/AUT108.txt"};

    // //for entry in Inventories Specific Files
    // string inventory_files[7] = {"Products/Inventories/KAR101.txt", "Products/Inventories/LAH102.txt", "Products/Inventories/ISB103.txt", "Products/Inventories/PEW104.txt", "Products/Inventories/QET105.txt", "Products/Inventories/NYC106.txt", "Products/Inventories/DXB108.txt"};

    vector<string> choosen_products;
    vector<Data> product_info;
    
    int input;
    while(1){
        product_info.clear();

        cout << endl;
        cout << "Select from the Following Categories," << endl << "1. Electronics" << endl << "2. Fashion" << endl << "3. Beauty and Personal Care" << endl << "4. Sports and Outdoors" << endl << "5. Medicine" << endl << "6. Toys and Games"<< endl << "7. Pet Supplies" << endl << "8. Automative" << endl << endl << "9. View Cart" << endl << "10. Search Product " << endl << "11. Exit View Products" << endl << endl << "Awaiting Response => ";
        cin >> input;
        if(input <= 0 || input > 11){
            cout << endl << "Invalid Input ... " << endl << "Please Choose Correctly from provided Categories" << endl << endl;

            continue;
        }
        else{
            if(input == 1){
                Electronics products;
                products.view_Product_Electronic(choosen_products,product_info);
            }
            if(input == 2){
                Fashion products; 
                products.view_Product_Fashion(choosen_products,product_info);
            }
            if(input == 3){
                BeautyAndPersonalCare products; 
                products.view_Product_BeautyAndPersonalCare(choosen_products,product_info);
            }
            if(input == 4){
                SportsAndOutdoors products; 
                products.view_Product_SportsAndOutdoors(choosen_products,product_info);
            }
            if(input == 5){
                MedsAndHerbs products; 
                products.view_Product_MedsAndHerbs(choosen_products,product_info);
            }
            if(input == 6){
                ToysAndGames products; 
                products.view_Product_ToysAndGames(choosen_products,product_info);
            }
            if(input == 7){
                PetSupplies products; 
                products.view_Product_PetSupplies(choosen_products,product_info);
            }
            if(input == 8){
                Automotive products; 
                products.view_Product_Automotive(choosen_products,product_info);
            }

            if(input == 9){
                if(choosen_products.empty()){
                    cout << endl << "Cart is Empty for Now" << endl << "Better Fill the Stomach of Cart ..." << endl << endl;
                }
                else{
                    cout << "Products Currently in Cart " << endl << endl;

                    // for(int i = 0 ; i < choosen_products.size(); i++){
                    //     cout << i+1 << ". " << choosen_products[i] << endl;
                    // }

                    Cart temp;
                    temp.displayProducts(cart);

                    cout << "[A] Remove Item from Cart\n[B] Go Back" << endl << endl << "Awating Response =>  ";
                    char choice;
                    cin >> choice;

                    if(choice == 'A' || choice == 'a'){
                        temp.remove_Cart(cart);

                        continue;
                    }
                    if(choice == 'B' || choice == 'b'){
                        continue;
                    }
                }
            }
            if(input == 10){
                search_Product(cart);
            }
            if(input == 11){
                cout << "Going Out of Product Gallery " << endl;
                return;
            }

            //Need to create an Extractor here
            vector<Product> Products = extract_Product_INFO(choosen_products);

            theCart(Products,product_info, cart);
        }
    }
}

void Electronics::view_Product_Electronic(vector<string>& gather_cart, vector<Data>& product_info){
    // if(!checkPerson_Call("admin")){
    //     cout << "Sorry, You can't Access this part of Influx." << endl <<  "This is Restricted Area (ONLY ADMIN)" << endl;
    //     //exit the function
    //     return;
    // }

    // list<Product> products_list;
    // Product listed_in_list_product;
    //

    int count = 0;
    vector<string> displayed_products;

    cout << endl << "IF you want to Apply Location Filter Then Choose From the Options Below ... " << endl << "1. Karachi" << endl << "2. Lahore" << endl << "3. Islamabad" << endl << "4. Peshawar" << endl << "5. Quetta" << endl << "6. New York" << endl << "7. Dubai" << endl << endl << "8. View All Products" << endl << endl << "Awaiting Response => ";
    int input;
    cin >> input;
        
    //Reading Algorithm
    string line;
    istringstream read_string;
    string IID, Stock, temp;
    fstream file_reader_inventory;    
    //read_string.str(line);
    if(input == 8){
            file_reader_inventory.open("Products/Categories/ELC101.txt",ios::in);

            if(!file_reader_inventory.is_open()){
                cerr << "Error ... " << endl << "Don't Worry it's will be fixed soon" << endl;
            }

            while(getline(file_reader_inventory,line)){
                istringstream read_string(line);
                displayed_products.push_back(line);

                getline(read_string >> ws, IID, ',');
                getline(read_string >> ws, productID, ',');
                getline(read_string >> ws, Stock, ',');
                getline(read_string >> ws, brand, ',');
                getline(read_string >> ws, product_name, ',');
                getline(read_string >> ws, temp, ',');
                price = stoi(temp);
                getline(read_string >> ws, model, ',');
                getline(read_string >> ws, temp, ',');
                screen_size = stod(temp);
                getline(read_string >> ws, temp, ',');
                RAM = stoi(temp);
                getline(read_string >> ws, temp, ',');
                storage_capacity = stoi(temp);
            
                count++;
                cout << "_______________________________________________________________________________" << endl << "| " << count << " | " 
                << "Inventory ID: " << setw(8) << IID << " | " << "Product ID: " << setw(8)  << productID << " | " << "Stock: " << setw(6) << Stock << " | " << "Brand: " << setw(8) << brand << " | " << "Name: " << setw(10) << product_name << " | " << "Price: $" << setw(10) << price << " | " << "Model : " << setw(12) << model << " | " << "Screen Size : " << setw(5) << screen_size << " | " << "RAM : " << setw(5) << RAM << " | "  "Storage : " << setw(5) << storage_capacity << " | " <<  endl;
            }
            file_reader_inventory.close();
        
    }
    else{
        file_reader_inventory.open(inventory_files[input-1],ios::in);

        if(!file_reader_inventory.is_open()){
            cerr << "Error ... " << endl << "Don't Worry it's will be fixed soon" << endl;
        }
        while(getline(file_reader_inventory,line)){
            istringstream read_string(line);
            displayed_products.push_back(line);

            getline(read_string >> ws, IID, ',');
            getline(read_string >> ws, productID, ',');
            if(IID == inventories[input-1] && productID == "ELC101"){
                getline(read_string >> ws, Stock, ',');
                getline(read_string >> ws, brand, ',');
                getline(read_string >> ws, product_name, ',');
                getline(read_string >> ws, temp, ',');
                price = stoi(temp);
                getline(read_string >> ws, model, ',');
                getline(read_string >> ws, temp, ',');
                screen_size = stod(temp);
                getline(read_string >> ws, temp, ',');
                RAM = stoi(temp);
                getline(read_string >> ws, temp, ',');
                storage_capacity = stoi(temp);
            }
            else{
                continue;
            }

            if(IID == inventories[input-1] && productID == "ELC101"){
                count++;
                cout << "_______________________________________________________________________________" << endl << "| " << count << " | " 
                << "Inventory ID: " << setw(7) << IID << " | " << "Product ID: " << setw(7)  << productID << " | " << "Stock: " << setw(4) << Stock << " | " << "Brand: " << setw(7) << brand << " | " << "Name: " << setw(10) << product_name << " | " << "Price: $" << setw(8) << price << " | " << "Model : " << setw(12) << model << " | " << "Screen Size : " << setw(3) << screen_size << " | " << "RAM : " << setw(3) << RAM << " | "  "Storage : " << setw(3) << storage_capacity << " | " <<  endl;
            }   
        }
        file_reader_inventory.close(); 
    }


    update_Collected_Products(displayed_products, gather_cart, product_info);

    return;

    // cout << endl << "Products Stored in Vector are : " << endl;
    // for (int i = 0 ; i < displayed_products.size() ; i++){
    //     cout << i+1 << ". " << displayed_products[i] << endl;
    // }

    //cout << endl << endl;
    //cout << "Done Printing the Vector Elements" << endl;
    
    // char choice;
    // int input_serial_product;
    // cout << endl << endl << "[Y] Add Products To Cart\t[N] Go Back\nAwating Response => ";
    // cin >> choice;
    // if(choice == 'Y' || choice == 'y'){
    //     cout << endl;
    //     cout << "You See Something You Like, Naughty Are Yah ..." << endl << "Amigo, Just Tell us It's Serial Number" << endl << "It will be added to your Cart" << endl << endl;
    //     cout << "WHEN YOU ARE DONE SELECTING THE PRODUCTS, YOU MUST ENTER -1 TO CONTINUE." << endl << endl;

    //     while(true) {
    //         cout << "Add to my Cart, item of Serial Number => ";
    //         cin >> input_serial_product;

    //         if (input_serial_product == -1) {
    //             cout << endl;
    //             cout << "Done with the Selection of Products, I see" << endl << "Visit Other Product Categories" << endl << "There Might be Something for a Man of Culture Like You ..." << endl << endl;
    //             break;  // Exit the loop if user enters -1
    //         }

    //         if(input_serial_product > displayed_products.size() || input_serial_product <= 0){
    //             cout << endl;
    //             cout << "Oh Dear, You Accidently Enter Wrong Serial Number" << endl << "Please Check and try again ..." << endl << endl;

    //             continue;
    //         }
    //         else{
    //             store_index.push_back(input_serial_product);  // Add the input to    the vector

    //             cout << "\tProduct Successfully Added to your Cart" << endl << endl;
    //         }
    //     }   

    //     cout << "Cart Has Been Updated" << endl ;
        
    //     //cout << endl << "[-1] Done Adding/Go Back\n" ;

    //     // cout << "Index of the Cart Stored Before Sorting" << endl << endl;
    //     // for(int i = 0; i < store_index.size(); i++) {
    //     //     cout << i+1 << ". " << store_index[i] << endl;
    //     // }
    //     //Necessary Step as user Can Enter Index of Product in mix Order
    //     sort(store_index.begin(), store_index.end());

    //     // cout << endl;
    //     // cout << "Index of the Cart Stored After Sorting" << endl << endl;
    //     // for(int i = 0; i < store_index.size(); i++) {
    //     //     cout << i+1 << ". " << store_index[i] << endl;
    //     // }

    //     // for(int i = 0; i < displayed_products.size() ; i++){
    //     //     int serial_number;
    //     //     istringstream read_string(line);
    //     //     getline(read_string >> ws, temp, '|');
    //     //     serial_number = stoi(temp);

    //     //     for(int j = 0; j < store_index.size(); j++){
    //     //         if(serial_number == store_index[i]){
    //     //             continue;
    //     //         }
    //     //         else{
    //     //             displayed_products.erase(displayed_products.begin() + (i-1));
    //     //         }
    //     //     }
    //     // }

    //     // for(int i = 0; i < store_index.size() ; i++){
    //     //     for(int j = 0; j < displayed_products.size(); j++){
    //     //         int serial_number;
    //     //         istringstream read_string(line);
    //     //         getline(read_string >> ws, temp, '|');
    //     //         serial_number = stoi(temp);
    //     //         cout << serial_number << endl;

    //     //         if(serial_number == store_index[i]){
    //     //             continue;
    //     //         }
    //     //         else{
    //     //             displayed_products.erase(displayed_products.begin() + j);
    //     //         }
    //     //     }
    //     // }

    //     vector<string> filtered_products;
    //     for (int i = 0; i < store_index.size(); i++) {
    //         int index = store_index[i] - 1;
    //         if (index >= 0 && index < displayed_products.size()) {
    //             filtered_products.push_back(displayed_products[index]);
    //         }
    //     }

    //     // Replace the displayed_products vector with the filtered vector
    //     displayed_products = filtered_products;
    //     //Clearing and Releasing the Memory Occupied by the FilterVector
    //     filtered_products.clear();
    //     vector<string>().swap(filtered_products);


    //     //Test Code for Checking the Contents
    //     //cout << endl << "Products Stored in Vector are : " << endl;
    //     // for (int i = 0 ; i < displayed_products.size() ; i++){
    //     //     cout << i+1 << ". " << displayed_products[i] << endl;
    //     // }

    //     gather_cart.insert(gather_cart.end(), displayed_products.begin(), displayed_products.end());

    //     //release the memory occupied by this vector
    //     displayed_products.clear();        vector<string>().swap(displayed_products);

    //     return gather_cart;
    // }
    // if(choice == 'N' || choice == 'n'){
    //     //To clear the vector and free the memory
    //     displayed_products.clear();
    //     vector<string>().swap(displayed_products);
    //     return gather_cart;
    // }

//     What the best approach for this scenario,
// i want to have one cart vector inside the Product class , this class then calls the view_Product function of different Categories like Electronic and Fashion etc, in their view_Product two vectors are created 
}

/*
void Electronics::view_Product(){
    cout << endl << endl << "Displaying the Electronics Product" << endl;

    string line;
    istringstream read_string;
    string IID, Stock, temp;
    fstream file_reader_inventory;    

    int count = 0;
    //read_string.str(line);

    file_reader_inventory.open("Products/Categories/ELC101.txt",ios::in);

    if(!file_reader_inventory.is_open()){
                cerr << "Error ... " << endl << "Don't Worry it's will be fixed soon" << endl;
            }

    while(getline(file_reader_inventory,line)){
        istringstream read_string(line);

        getline(read_string >> ws, IID, ',');
        getline(read_string >> ws, productID, ',');
        getline(read_string >> ws, Stock, ',');
        getline(read_string >> ws, brand, ',');
        getline(read_string >> ws, product_name, ',');
        getline(read_string >> ws, temp, ',');
                price = stoi(temp);
        getline(read_string >> ws, model, ',');
        getline(read_string >> ws, temp, ',');
                screen_size = stod(temp);
        getline(read_string >> ws, temp, ',');
                RAM = stoi(temp);
        getline(read_string >> ws, temp, ',');
                storage_capacity = stoi(temp);
            
        count++;
        cout << "________________________________________________________________" << endl;
        cout << "| " << count << " | " << "Inventory ID: " << setw(8) << IID << " | " << "Product ID: " << setw(8)  << productID << " | " << "Stock: " << setw(6) << Stock << " | " << "Brand: " << setw(8) << brand << " | " << "Name: " << setw(10) << product_name << " | " << "Price: $" << setw(10) << price << " | " << "Model : " << setw(12) << model << " | " << "Screen Size : " << setw(5) << screen_size << " | " << "RAM : " << setw(5) << RAM << " | "  "Storage : " << setw(5) << storage_capacity << " | " <<  endl;
    }
    
    file_reader_inventory.close();

    cout << "Wanna Filter for to find the PRoducts Near Your Location ... " << endl;
    char choice;
    cout << "[Y] Yes\t[N] No" << endl;
    cout << "Awaiting Response => ";
    cin >> choice;

    if(choice == 'y' || choice == 'Y'){
        cout << "";
    }
    if(choice == 'n' || choice == 'N'){
        cout << "";
    }

}
*/

void Fashion::view_Product_Fashion(vector<string>& gather_cart, vector<Data>& product_info){
    // if(!checkPerson_Call("admin")){
    //     cout << "Sorry, You can't Access this part of Influx." << endl <<  "This is Restricted Area (ONLY ADMIN)" << endl;
    //     //exit the function
    //     return;
    // }

    int count = 0;
    vector<string> displayed_products;

    // list<Product> products_list;
    // Product listed_in_list_product;
    //

    cout << endl << "IF you want to Apply Location Filter Then Choose From the Options Below ... " << endl << "1. Karachi" << endl << "2. Lahore" << endl << "3. Islamabad" << endl << "4. Peshawar" << endl << "5. Quetta" << endl << "6. New York" << endl << "7. Dubai" << endl << endl << "8. View All Products" << endl << endl << "Awaiting Response => ";
    int input;
    cin >> input;
        
    //Reading Algorithm
    string line;
    istringstream read_string;
    string IID, Stock, temp;
    fstream file_reader_inventory;    
    //read_string.str(line);
    if(input == 8){
            file_reader_inventory.open("Products/Categories/FSH102.txt",ios::in);

            if(!file_reader_inventory.is_open()){
                cerr << "Error ... " << endl << "Don't Worry it's will be fixed soon" << endl;
            }

            while(getline(file_reader_inventory,line)){
                istringstream read_string(line);
                displayed_products.push_back(line);

                getline(read_string >> ws, IID, ',');
                getline(read_string >> ws, productID, ',');
                getline(read_string >> ws, Stock, ',');
                getline(read_string >> ws, brand, ',');
                getline(read_string >> ws, product_name, ',');
                getline(read_string >> ws, temp, ',');
                price = stoi(temp);

                getline(read_string >> ws, size, ',');
                getline(read_string >> ws, color, ',');
                getline(read_string >> ws, material, ',');
                getline(read_string >> ws, style, ',');
            
                count++;
                cout << "_______________________________________________________________________________" << endl << "| " << count << "| " << "Inventory ID: " << setw(8) << IID << " | " << "Product ID: " << setw(8) << productID << " | " << "Stock: " << setw(6) << Stock << " | " << "Brand: " << setw(8) << brand << " | " << "Name: " << setw(10) << product_name << " | " << "Price: $" << setw(10) << price << " | " << "Size : " << setw(12) << size << " | " << "Color : " << setw(10) << color << " | " << "Material : " << setw(10) << material << " | " << "Style : " << setw(10) << style << " | " << endl;

            }
            file_reader_inventory.close();
        
    }
    else{
        file_reader_inventory.open(inventory_files[input-1],ios::in);

        if(!file_reader_inventory.is_open()){
            cerr << "Error ... " << endl << "Don't Worry it's will be fixed soon" << endl;
        }
        while(getline(file_reader_inventory,line)){
            istringstream read_string(line);
            displayed_products.push_back(line);

            getline(read_string >> ws, IID, ',');
            getline(read_string >> ws, productID, ',');
            if(IID == inventories[input-1] && productID == "FSH102"){
                getline(read_string >> ws, Stock, ',');
                getline(read_string >> ws, brand, ',');
                getline(read_string >> ws, product_name, ',');
                getline(read_string >> ws, temp, ',');
                price = stoi(temp);
                getline(read_string >> ws, size, ',');
                getline(read_string >> ws, color, ',');
                getline(read_string >> ws, material, ',');
                getline(read_string >> ws, style, ',');
            }
            else{
                continue;
            }

            if(IID == inventories[input-1] && productID == "FSH102"){
                count++;
                cout << "_______________________________________________________________________________" << endl << "| " << count << "| " << "Inventory ID: " << setw(8) << IID << " | " << "Product ID: " << setw(8) << productID << " | " << "Stock: " << setw(6) << Stock << " | " << "Brand: " << setw(8) << brand << " | " << "Name: " << setw(10) << product_name << " | " << "Price: $" << setw(10) << price << " | " << "Size : " << setw(12) << size << " | " << "Color : " << setw(10) << color << " | " << "Material : " << setw(10) << material << " | " << "Style : " << setw(10) << style << " | " << endl;
            }   
        }
        file_reader_inventory.close(); 
    }

    update_Collected_Products(displayed_products, gather_cart, product_info);

    return;
}

void BeautyAndPersonalCare::view_Product_BeautyAndPersonalCare(vector<string>& gather_cart, vector<Data>& product_info){
    // if(!checkPerson_Call("admin")){
    //     cout << "Sorry, You can't Access this part of Influx." << endl <<  "This is Restricted Area (ONLY ADMIN)" << endl;
    //     //exit the function
    //     return;
    // }

    int count = 0;
    vector<string> displayed_products;


    // list<Product> products_list;
    // Product listed_in_list_product;
    //

    cout << endl << "IF you want to Apply Location Filter Then Choose From the Options Below ... " << endl << "1. Karachi" << endl << "2. Lahore" << endl << "3. Islamabad" << endl << "4. Peshawar" << endl << "5. Quetta" << endl << "6. New York" << endl << "7. Dubai" << endl << endl << "8. View All Products" << endl << endl << "Awaiting Response => ";
    int input;
    cin >> input;
        
    //Reading Algorithm
    string line;
    istringstream read_string;
    string IID, Stock, temp;
    fstream file_reader_inventory;    
    //read_string.str(line);
    if(input == 8){
            file_reader_inventory.open("Products/Categories/BPC103.txt",ios::in);

            if(!file_reader_inventory.is_open()){
                cerr << "Error ... " << endl << "Don't Worry it's will be fixed soon" << endl;
            }

            while(getline(file_reader_inventory,line)){
                istringstream read_string(line);
                displayed_products.push_back(line);

                getline(read_string >> ws, IID, ',');
                getline(read_string >> ws, productID, ',');
                getline(read_string >> ws, Stock, ',');
                getline(read_string >> ws, brand, ',');
                getline(read_string >> ws, product_name, ',');
                getline(read_string >> ws, temp, ',');
                price = stoi(temp);
                getline(read_string >> ws, type_of_product, ',');
                getline(read_string >> ws, ingredients, ',');
                getline(read_string >> ws, skin_hair_type, ',');
                getline(read_string >> ws, scent, ',');
            
                count++;
                cout << "_______________________________________________________________________________" << "| " << count << "| " << "Inventory ID: " << setw(8) << IID << " | "  << "Product ID: " << setw(8)  << productID << " | "  << "Stock: " << setw(6) << Stock << " | "  << "Brand: " << setw(8) << brand << " | "  << "Name: " << setw(10) << product_name << " | "  << "Price: $" << setw(10) << price << " | "  << "Type of Product : " << setw(15) << type_of_product << " | "  << "Ingredients : " << setw(20) << ingredients << " | "  << "Skin/Hair Type: " << setw(12) << skin_hair_type << " | "  << "Scent: " << setw(10) << scent << " | " << endl;
            }
            file_reader_inventory.close();
        
    }
    else{
        file_reader_inventory.open(inventory_files[input-1],ios::in);

        if(!file_reader_inventory.is_open()){
            cerr << "Error ... " << endl << "Don't Worry it's will be fixed soon" << endl;
        }
        while(getline(file_reader_inventory,line)){
            istringstream read_string(line);
            displayed_products.push_back(line);

            getline(read_string >> ws, IID, ',');
            getline(read_string >> ws, productID, ',');
            if(IID == inventories[input-1] && productID == "BPC103"){
                getline(read_string >> ws, Stock, ',');
                getline(read_string >> ws, brand, ',');
                getline(read_string >> ws, product_name, ',');
                getline(read_string >> ws, temp, ',');
                price = stoi(temp);
                getline(read_string >> ws, type_of_product, ',');
                getline(read_string >> ws, ingredients, ',');
                getline(read_string >> ws, skin_hair_type, ',');
                getline(read_string >> ws, scent, ',');
            }
            else{
                continue;
            }

            if(IID == inventories[input-1] && productID == "BPC103"){
                count++;
                cout << "_______________________________________________________________________________" << "| " << count << "| " << "Inventory ID: " << setw(8) << IID << " | "  << "Product ID: " << setw(8)  << productID << " | "  << "Stock: " << setw(6) << Stock << " | "  << "Brand: " << setw(8) << brand << " | "  << "Name: " << setw(10) << product_name << " | "  << "Price: $" << setw(10) << price << " | "  << "Type of Product : " << setw(15) << type_of_product << " | "  << "Ingredients : " << setw(20) << ingredients << " | "  << "Skin/Hair Type: " << setw(12) << skin_hair_type << " | "  << "Scent: " << setw(10) << scent << " | " << endl;
            }   
        }
        file_reader_inventory.close(); 
    }

    update_Collected_Products(displayed_products, gather_cart, product_info);

    return;
}

void SportsAndOutdoors::view_Product_SportsAndOutdoors(vector<string>& gather_cart, vector<Data>& product_info){
    // if(!checkPerson_Call("admin")){
    //     cout << "Sorry, You can't Access this part of Influx." << endl <<  "This is Restricted Area (ONLY ADMIN)" << endl;
    //     //exit the function
    //     return;
    // }

    int count = 0;
    vector<string> displayed_products;


    // list<Product> products_list;
    // Product listed_in_list_product;
    //

    cout << endl << "IF you want to Apply Location Filter Then Choose From the Options Below ... " << endl << "1. Karachi" << endl << "2. Lahore" << endl << "3. Islamabad" << endl << "4. Peshawar" << endl << "5. Quetta" << endl << "6. New York" << endl << "7. Dubai" << endl << endl << "8. View All Products" << endl << endl << "Awaiting Response => ";
    int input;
    cin >> input;
        
    //Reading Algorithm
    string line;
    istringstream read_string;
    string IID, Stock, temp;
    fstream file_reader_inventory;    
    //read_string.str(line);
    if(input == 8){
            file_reader_inventory.open("Products/Categories/SPO104.txt",ios::in);

            if(!file_reader_inventory.is_open()){
                cerr << "Error ... " << endl << "Don't Worry it's will be fixed soon" << endl;
            }

            while(getline(file_reader_inventory,line)){
                istringstream read_string(line);
                displayed_products.push_back(line);

                getline(read_string >> ws, IID, ',');
                getline(read_string >> ws, productID, ',');
                getline(read_string >> ws, Stock, ',');
                getline(read_string >> ws, brand, ',');
                getline(read_string >> ws, product_name, ',');
                getline(read_string >> ws, temp, ',');
                price = stoi(temp);
                getline(read_string >> ws, size, ',');
                getline(read_string >> ws, color, ',');
                getline(read_string >> ws, material, ',');
                getline(read_string >> ws, sport_activity_type, ',');

                count++;
                cout << "_______________________________________________________________________________"<< endl << "| " << count << "| " << "Inventory ID: " << setw(8) << IID << " | " << "Product ID: " << setw(8) << productID << " | " << "Stock: " << setw(6) << Stock << " | " << "Brand: " << setw(8) << brand << " | " << "Name: " << setw(10) << product_name << " | " << "Price: $" << setw(10) << price << " | " << "Size: " << setw(10) << size << " | " << "Color: " << setw(10) << color << " | " << "Material: " << setw(10) << material << " | " << "Sports Activity Type: " << setw(10) << sport_activity_type << " | " << endl;
            }
            file_reader_inventory.close();
        
    }
    else{
        file_reader_inventory.open(inventory_files[input-1],ios::in);

        if(!file_reader_inventory.is_open()){
            cerr << "Error ... " << endl << "Don't Worry it's will be fixed soon" << endl;
        }
        while(getline(file_reader_inventory,line)){
            istringstream read_string(line);
            displayed_products.push_back(line);

            getline(read_string >> ws, IID, ',');
            getline(read_string >> ws, productID, ',');
            if(IID == inventories[input-1] && productID == "SPO104"){
                getline(read_string >> ws, Stock, ',');
                getline(read_string >> ws, brand, ',');
                getline(read_string >> ws, product_name, ',');
                getline(read_string >> ws, temp, ',');
                price = stoi(temp);
                getline(read_string >> ws, size, ',');
                getline(read_string >> ws, color, ',');
                getline(read_string >> ws, material, ',');
                getline(read_string >> ws, sport_activity_type, ',');
            }
            else{
                continue;
            }


            if(IID == inventories[input-1] && productID == "SPO104"){
                count++;
                cout << "_______________________________________________________________________________"<< endl << "| " << count << "| " << "Inventory ID: " << setw(8) << IID << " | " << "Product ID: " << setw(8) << productID << " | " << "Stock: " << setw(6) << Stock << " | " << "Brand: " << setw(8) << brand << " | " << "Name: " << setw(10) << product_name << " | " << "Price: $" << setw(10) << price << " | " << "Size: " << setw(10) << size << " | " << "Color: " << setw(10) << color << " | " << "Material: " << setw(10) << material << " | " << "Sports Activity Type: " << setw(10) << sport_activity_type << " | " << endl;
            }   
        }
        file_reader_inventory.close(); 
    }

    update_Collected_Products(displayed_products, gather_cart, product_info);

    return;
}

void MedsAndHerbs::view_Product_MedsAndHerbs(vector<string>& gather_cart, vector<Data>& product_info){
    // if(!checkPerson_Call("admin")){
    //     cout << "Sorry, You can't Access this part of Influx." << endl <<  "This is Restricted Area (ONLY ADMIN)" << endl;
    //     //exit the function
    //     return;
    // }

    int count = 0;
    vector<string> displayed_products;


    // list<Product> products_list;
    // Product listed_in_list_product;
    //

    cout << endl << "IF you want to Apply Location Filter Then Choose From the Options Below ... " << endl << "1. Karachi" << endl << "2. Lahore" << endl << "3. Islamabad" << endl << "4. Peshawar" << endl << "5. Quetta" << endl << "6. New York" << endl << "7. Dubai" << endl << endl << "8. View All Products" << endl << endl << "Awaiting Response => ";
    int input;
    cin >> input;
        
    //Reading Algorithm
    string line;
    istringstream read_string;
    string IID, Stock, temp;
    fstream file_reader_inventory;    
    //read_string.str(line);
    if(input == 8){
            file_reader_inventory.open("Products/Categories/MED105.txt",ios::in);

            if(!file_reader_inventory.is_open()){
                cerr << "Error ... " << endl << "Don't Worry it's will be fixed soon" << endl;
            }

            while(getline(file_reader_inventory,line)){
                istringstream read_string(line);
                displayed_products.push_back(line);

                getline(read_string >> ws, IID, ',');
                getline(read_string >> ws, product_name, ',');
                getline(read_string >> ws, Stock, ',');
                getline(read_string >> ws, brand, ',');
                getline(read_string >> ws, product_name, ',');
                getline(read_string >> ws, temp, ',');
                price = stoi(temp);
                getline(read_string >> ws, type, ',');
                getline(read_string >> ws, dosage, ',');
                getline(read_string >> ws, expiry, ',');
            
                count++;
                cout << "_______________________________________________________________________________" << endl << setw(2) << count << " | "  << "Inventory ID: " << setw(8) << IID << " | "  << "Product ID: " << setw(8)  << productID << " | "  << "Stock: " << setw(6) << Stock << " | "  << "Brand: " << setw(8) << brand << " | "  << "Name: " << setw(10) << product_name << " | "  << "Price: $" << setw(10) << price << " | "  << "Medicine Type : " << setw(12) << type << " | "  << "Dosage : " << setw(5) << dosage << " | "   << "Expiry : " << setw(12) << expiry << " | " << endl;
            }
            file_reader_inventory.close();
        
    }
    else{
        file_reader_inventory.open(inventory_files[input-1],ios::in);

        if(!file_reader_inventory.is_open()){
            cerr << "Error ... " << endl << "Don't Worry it's will be fixed soon" << endl;
        }
        while(getline(file_reader_inventory,line)){
            istringstream read_string(line);
            displayed_products.push_back(line);

            getline(read_string >> ws, IID, ',');
            getline(read_string >> ws, product_name, ',');
            getline(read_string >> ws, Stock, ',');
            getline(read_string >> ws, brand, ',');
            getline(read_string >> ws, product_name, ',');
            getline(read_string >> ws, temp, ',');
            price = stoi(temp);
            getline(read_string >> ws, type, ',');
            getline(read_string >> ws, dosage, ',');
            getline(read_string >> ws, expiry, ',');

            if(IID == inventories[input-1] && productID == "MED105"){
                count++;
                cout << "_______________________________________________________________________________" << endl << setw(2) << count << " | "  << "Inventory ID: " << setw(8) << IID << " | "  << "Product ID: " << setw(8)  << productID << " | "  << "Stock: " << setw(6) << Stock << " | "  << "Brand: " << setw(8) << brand << " | "  << "Name: " << setw(10) << product_name << " | "  << "Price: $" << setw(10) << price << " | "  << "Medicine Type : " << setw(12) << type << " | "  << "Dosage : " << setw(5) << dosage << " | "   << "Expiry : " << setw(12) << expiry << " | " << endl;
            
            }   
        }
        file_reader_inventory.close(); 
    }

    update_Collected_Products(displayed_products, gather_cart, product_info);

    return;
}

void ToysAndGames::view_Product_ToysAndGames(vector<string>& gather_cart, vector<Data>& product_info){
    // if(!checkPerson_Call("admin")){
    //     cout << "Sorry, You can't Access this part of Influx." << endl <<  "This is Restricted Area (ONLY ADMIN)" << endl;
    //     //exit the function
    //     return;
    // }

    int count = 0;
    vector<string> displayed_products;


    // list<Product> products_list;
    // Product listed_in_list_product;
    //

    cout << endl << "IF you want to Apply Location Filter Then Choose From the Options Below ... " << endl << "1. Karachi" << endl << "2. Lahore" << endl << "3. Islamabad" << endl << "4. Peshawar" << endl << "5. Quetta" << endl << "6. New York" << endl << "7. Dubai" << endl << endl << "8. View All Products" << endl << endl << "Awaiting Response => ";
    int input;
    cin >> input;
        
    //Reading Algorithm
    string line;
    istringstream read_string;
    string IID, Stock, temp;
    fstream file_reader_inventory;    
    //read_string.str(line);
    if(input == 8){
            file_reader_inventory.open("Products/Categories/TNG106.txt",ios::in);

            if(!file_reader_inventory.is_open()){
                cerr << "Error ... " << endl << "Don't Worry it's will be fixed soon" << endl;
            }

            while(getline(file_reader_inventory,line)){
                istringstream read_string(line);
                displayed_products.push_back(line);

                getline(read_string >> ws, IID, ',');
                getline(read_string >> ws, productID, ',');
                getline(read_string >> ws, Stock, ',');
                getline(read_string >> ws, brand, ',');
                getline(read_string >> ws, product_name, ',');
                getline(read_string >> ws, temp, ',');
                price = stoi(temp);
                getline(read_string >> ws, age_range, ',');
                getline(read_string >> ws, number_of_players, ',');
                getline(read_string >> ws, type_of_game, ',');
            
                count++;
                cout << "_______________________________________________________________________________" << endl << "| " << count << "| " << "Inventory ID: " << setw(8) << IID << " | " << "Product ID: " << setw(8) << productID << " | " << "Stock: " << setw(6) << Stock << " | " << "Brand: " << setw(8) << brand << " | " << "Name: " << setw(10) << product_name << " | " << "Price: $" << setw(10) << price << " | " << "Age Range : " << setw(12) << age_range << " | " << "Number of Players : " << setw(5) << number_of_players << " | " << "Type of Game : " << setw(10) << type_of_game << " |" << endl;
            }
            file_reader_inventory.close();
        
    }
    else{
        file_reader_inventory.open(inventory_files[input-1],ios::in);

        if(!file_reader_inventory.is_open()){
            cerr << "Error ... " << endl << "Don't Worry it's will be fixed soon" << endl;
        }
        while(getline(file_reader_inventory,line)){
            istringstream read_string(line);
            displayed_products.push_back(line);

            getline(read_string >> ws, IID, ',');
            getline(read_string >> ws, productID, ',');
            getline(read_string >> ws, Stock, ',');
            getline(read_string >> ws, brand, ',');
            getline(read_string >> ws, product_name, ',');
            getline(read_string >> ws, temp, ',');
            price = stoi(temp);
            getline(read_string >> ws, age_range, ',');
            getline(read_string >> ws, number_of_players, ',');
            getline(read_string >> ws, type_of_game, ',');

            if(IID == inventories[input-1] && productID == "TNG106"){
                count++;
                cout << "_______________________________________________________________________________" << endl << "| " << count << "| " << "Inventory ID: " << setw(8) << IID << " | " << "Product ID: " << setw(8) << productID << " | " << "Stock: " << setw(6) << Stock << " | " << "Brand: " << setw(8) << brand << " | " << "Name: " << setw(10) << product_name << " | " << "Price: $" << setw(10) << price << " | " << "Age Range : " << setw(12) << age_range << " | " << "Number of Players : " << setw(5) << number_of_players << " | " << "Type of Game : " << setw(10) << type_of_game << " |" << endl;
            }   
        }
        file_reader_inventory.close(); 
    }

    update_Collected_Products(displayed_products, gather_cart, product_info);

    return;
}

void PetSupplies::view_Product_PetSupplies(vector<string>& gather_cart, vector<Data>& product_info){
    // if(!checkPerson_Call("admin")){
    //     cout << "Sorry, You can't Access this part of Influx." << endl <<  "This is Restricted Area (ONLY ADMIN)" << endl;
    //     //exit the function
    //     return;
    // }

    int count = 0;
    vector<string> displayed_products;


    // list<Product> products_list;
    // Product listed_in_list_product;
    //

    cout << endl << "IF you want to Apply Location Filter Then Choose From the Options Below ... " << endl << "1. Karachi" << endl << "2. Lahore" << endl << "3. Islamabad" << endl << "4. Peshawar" << endl << "5. Quetta" << endl << "6. New York" << endl << "7. Dubai" << endl << endl << "8. View All Products" << endl << endl << "Awaiting Response => ";
    int input;
    cin >> input;
        
    //Reading Algorithm
    string line;
    istringstream read_string;
    string IID, Stock, temp;
    fstream file_reader_inventory;    
    //read_string.str(line);
    if(input == 8){
            file_reader_inventory.open("Products/Categories/PET107.txt",ios::in);

            if(!file_reader_inventory.is_open()){
                cerr << "Error ... " << endl << "Don't Worry it's will be fixed soon" << endl;
            }

            while(getline(file_reader_inventory,line)){
                istringstream read_string(line);
                displayed_products.push_back(line);

                getline(read_string >> ws, IID, ',');
                getline(read_string >> ws, productID, ',');
                getline(read_string >> ws, Stock, ',');
                getline(read_string >> ws, brand, ',');
                getline(read_string >> ws, product_name, ',');
                getline(read_string >> ws, temp, ',');
                price = stoi(temp);
                getline(read_string >> ws, type_of_product, ',');
                getline(read_string >> ws, animal_type, ',');
                getline(read_string >> ws, age_range, ',');
            
                count++;
                cout << "_______________________________________________________________________________" << endl << "| " << count << "| " << "Inventory ID: " << setw(8) << IID << " | "<< "Product ID: " << setw(8) << productID << " | "<< "Stock: " << setw(6) << Stock << " | "<< "Brand: " << setw(8) << brand << " | "<< "Name: " << setw(10) << product_name << " | "<< "Price: $" << setw(10) << price << " | "<< "Type of Product : " << setw(12) << type_of_product << " | "<< "Animal Type : " << setw(12) << animal_type << " | "<< "Age Range : " << setw(12) << age_range << " | " << endl;
            }
            file_reader_inventory.close();
        
    }
    else{
        file_reader_inventory.open(inventory_files[input-1],ios::in);

        if(!file_reader_inventory.is_open()){
            cerr << "Error ... " << endl << "Don't Worry it's will be fixed soon" << endl;
        }
        while(getline(file_reader_inventory,line)){
            istringstream read_string(line);
            displayed_products.push_back(line);

            getline(read_string >> ws, IID, ',');
            getline(read_string >> ws, productID, ',');
            getline(read_string >> ws, Stock, ',');
            getline(read_string >> ws, brand, ',');
            getline(read_string >> ws, product_name, ',');
            getline(read_string >> ws, temp, ',');
            price = stoi(temp);
            getline(read_string >> ws, type_of_product, ',');
            getline(read_string >> ws, animal_type, ',');
            getline(read_string >> ws, age_range, ',');

            if(IID == inventories[input-1] && productID == "PET107"){
                count++;
                cout << "_______________________________________________________________________________" << endl << "| " << count << "| " << "Inventory ID: " << setw(8) << IID << " | "<< "Product ID: " << setw(8) << productID << " | "<< "Stock: " << setw(6) << Stock << " | "<< "Brand: " << setw(8) << brand << " | "<< "Name: " << setw(10) << product_name << " | "<< "Price: $" << setw(10) << price << " | "<< "Type of Product : " << setw(12) << type_of_product << " | "<< "Animal Type : " << setw(12) << animal_type << " | "<< "Age Range : " << setw(12) << age_range << " | " << endl;
            }   
        }
        file_reader_inventory.close(); 
    }

    update_Collected_Products(displayed_products, gather_cart, product_info);

    return;
}

void Automotive::view_Product_Automotive(vector<string>& gather_cart, vector<Data>& product_info){
    // if(!checkPerson_Call("admin")){
    //     cout << "Sorry, You can't Access this part of Influx." << endl <<  "This is Restricted Area (ONLY ADMIN)" << endl;
    //     //exit the function
    //     return;
    // }

    int count = 0;
    vector<string> displayed_products;


    // list<Product> products_list;
    // Product listed_in_list_product;
    //

    cout << endl << "IF you want to Apply Location Filter Then Choose From the Options Below ... " << endl << "1. Karachi" << endl << "2. Lahore" << endl << "3. Islamabad" << endl << "4. Peshawar" << endl << "5. Quetta" << endl << "6. New York" << endl << "7. Dubai" << endl << endl << "8. View All Products" << endl << endl << "Awaiting Response => ";
    int input;
    cin >> input;
        
    //Reading Algorithm
    string line;
    istringstream read_string;
    //temp for the ones that are in integer value, read all then convert to int logic is used
    string IID, Stock, temp;
    fstream file_reader_inventory;    
    //read_string.str(line);
    if(input == 8){
            file_reader_inventory.open("Products/Categories/AUT108.txt",ios::in);

            if(!file_reader_inventory.is_open()){
                cerr << "Error ... " << endl << "Don't Worry it's will be fixed soon" << endl;
            }

            while(getline(file_reader_inventory,line)){
                istringstream read_string(line);
                displayed_products.push_back(line);

                getline(read_string >> ws, IID, ',');
                getline(read_string >> ws, productID, ',');
                getline(read_string >> ws, Stock, ',');
                getline(read_string >> ws, brand, ',');
                getline(read_string >> ws, product_name, ',');
                getline(read_string >> ws, temp, ',');
                price = stoi(temp);
                getline(read_string >> ws, model, ',');
                getline(read_string >> ws, vehicleType, ',');
                getline(read_string >> ws, temp, ',');
                engineSize = stoi(temp);
                getline(read_string >> ws, temp, ',');
                year = stoi(temp);

                count++;
                cout << "_______________________________________________________________________________" << endl << "| " << count << "| " << "Inventory ID: " << setw(8) << IID << " | " << "Product ID: " << setw(8)  << productID << " | " << "Stock: " << setw(6) << Stock << " | " << "Brand: " << setw(8) << brand << " | " << "Name: " << setw(10) << product_name << " | " << "Price: $" << setw(10) << price << " | " << "Model : " << setw(12) << model << " | " << "Vehicle Type : " << setw(12) << vehicleType << " | " << "Year : " << setw(5) << year << " | " << "Engine Size : " << setw(5) << engineSize << " | " << endl;
            }
            file_reader_inventory.close();
        
    }
    else{
        file_reader_inventory.open(inventory_files[input-1],ios::in);

        if(!file_reader_inventory.is_open()){
            cerr << "Error ... " << endl << "Don't Worry it's will be fixed soon" << endl;
        }
        while(getline(file_reader_inventory,line)){
            istringstream read_string(line);
            displayed_products.push_back(line);

            getline(read_string >> ws, IID, ',');
            getline(read_string >> ws, productID, ',');
            getline(read_string >> ws, Stock, ',');
            getline(read_string >> ws, brand, ',');
            getline(read_string >> ws, product_name, ',');
            getline(read_string >> ws, temp, ',');
            price = stoi(temp);
            getline(read_string >> ws, model, ',');
            getline(read_string >> ws, vehicleType, ',');
            getline(read_string >> ws, temp, ',');
            engineSize = stoi(temp);
            getline(read_string >> ws, temp, ',');
            year = stoi(temp);

            if(IID == inventories[input-1] && productID == "AUT108"){
                count++;
                cout << "_______________________________________________________________________________" << endl << "| " << count << "| " << "Inventory ID: " << setw(8) << IID << " | " << "Product ID: " << setw(8)  << productID << " | " << "Stock: " << setw(6) << Stock << " | " << "Brand: " << setw(8) << brand << " | " << "Name: " << setw(10) << product_name << " | " << "Price: $" << setw(10) << price << " | " << "Model : " << setw(12) << model << " | " << "Vehicle Type : " << setw(12) << vehicleType << " | " << "Year : " << setw(5) << year << " | " << "Engine Size : " << setw(5) << engineSize << " | " << endl;
            }   
        }
        file_reader_inventory.close(); 
    }

    update_Collected_Products(displayed_products, gather_cart, product_info);

    return;
}



//PROGRESS DONE TILL HERE
//A vector Function that is used in the editProduct() below it.

void Product::editProduct(){

    //Check Person Call
    //checkPerosn_Call(string);

    cout << "This is Edit Panel of Product..." << endl << endl;
    while(true){
        cout << endl << endl << "[A] Change Information" << endl << "[B] Delete Product" << endl << "[C] Exit/Return " << endl << endl;
        cout << "Awating Response =>  ";
        char choose_action;
        cin >> choose_action;
        if(choose_action == 'C' || choose_action == 'c'){
            break;
        }
        if(choose_action != 'A' && choose_action != 'a' && choose_action != 'B' && choose_action != 'b'){
            cout << endl << "Invalid Input Provided ..." << endl << "Please Check and Try Again " << endl << endl << "Awating Response =>  ";

            continue;
        }

        int choose_file;
        cout << "Select from the Following Categories," << endl << "1. Electronics" << endl << "2. Fashion" << endl << "3. Beauty and Personal Care" << endl << "4. Sports and Outdoors" << endl << "5. Medicine" << endl << "7. Toys and Games" << endl << "8. Automative" << endl << "9. Go Back ..." << endl << endl << "Awaiting Response => ";
        cin >> choose_file;

        //conditions for choose files

        if(choose_file == 9){
            continue;
        }

        //fstream file_reader(product_files(input-1), ios::in);

        ifstream file_reader(product_files[choose_file-1]);
        vector<string> file_lines;

        string single_line;

        while (getline(file_reader, single_line)) {
            file_lines.push_back(single_line);
        }
            
        file_reader.close();

        //Test Code for Current Content
        cout << "Current contents of file:\n";
        int count = 0;
        for (auto& single_line : file_lines) {
            cout << "___________________________________________________________________________";
            cout << count+1 << ". " << single_line << '\n';
            count++;
        }
        

        if(choose_action == 'A' || choose_action == 'a'){
            //Change Logic
            
            // Get the line number and field number of the entry to be modified
            int lineNumber = 0;
            int fieldNumber = 0;
            cout << endl << endl << "Enter the line number (starting from 1) of the entry to be modified: ";
            cin >> lineNumber;
            cout << "Enter the field number (starting from 1) of the value to be modified: ";
            cin >> fieldNumber;

            // Modify the required field
            string& entry = file_lines[lineNumber - 1];
            
            //Reading String Till Comma
            vector<string> FullLines = split(entry, ',');
            cout << "Current value of field " << fieldNumber << " is: " << FullLines[fieldNumber - 1] << '\n';

            cin.ignore();
            cout << "Enter the new value for field " << fieldNumber << ": ";
            string newValue;
            getline(cin, newValue);

            FullLines[fieldNumber - 1] = newValue;
            entry = FullLines[0];
            for (int i = 1; i < FullLines.size(); i++) {
                entry += ',' + FullLines[i];
            }
        }
        if(choose_action == 'B' || choose_action == 'b'){
            //Delete Logic

            int lineToDelete;
            cout << endl << endl << "Enter the Index of Line You Want to Delete" << endl << "ENTER -1 to EXIT DELETE MODE" << endl << "Awating Response =>  ";
            cin >> lineToDelete;

            if(lineToDelete == -1){
                continue;
            }

            // while(true){
            //     char final_choice;
            //     cout << "Are You Sure You Want to Delete This Product" << endl << endl << "[Y] YES\t[N] NO";
            //     cout << "Awaiting Response =>  ";

            //     if(final_choice == 'N' || final_choice == 'n'){
            //         break;
            //     }
            //     if(choose_action != 'Y' && choose_action != 'y' && choose_action != 'N' && choose_action != 'n'){
            //         cout << endl << "Invalid Input Provided ..." << endl << "Please Check and Try Again " << endl << endl << "Awating Response =>  ";
            //     }

            // }

            if (lineToDelete >= 1 && lineToDelete <= file_lines.size()) {
                file_lines.erase(file_lines.begin() + lineToDelete - 1);
            } else {
                cerr << "Error: Line number is out of range\n";
            }
        //     for (auto& single_line : file_lines) {
        //     cout << "___________________________________________________________________________";
        //     cout << count+1 << ". " << single_line << '\n';
        //     count++;
        // }
        }

        ofstream file_writer(product_files[choose_file-1]);

        // Write the updated contents back to the file
        for (auto& line : file_lines) {
            file_writer << line << '\n';
        }
        file_writer.close();

        cout << "Updated contents of file:\n";

    }

    cout << endl << endl << "Product List Has Been Updated in Influx Database ..." << endl << "Ciao..." << endl;

    return;
    //delete product;
}

//When the User is done with the Cart or he's near the execution of Order of the Products this function will be called to extract the info of the Products
vector<Product> Product::extract_Product_INFO(vector<string>& gather_cart){
    //Sample Info 
    //ISB103,ELC101,15,Xiaomi,Mi 11X,29999,M2011K2G,6.67,6,128,A high-performing smartphone with a large 6.67 inch screen, 6GB RAM and 128GB storage.

    //Need To Extract Brand, Name, Price, and Description
    //Stock will be subtracted from Quantity for Change in File

    //Algorithm to Open Multiple Files and check in each one of them
    //for(int i = 0; i < gather_cart.size() ; i++){ 
        // //Reading Algorithm
        // string line;
        // line = gather_cart[i];
        // istringstream read_string(line);
            
        // getline(read_string >> ws, temp, ',');
        // count++;
        // if(count == 1){
        //     continue;
        // }
        // if(count >= 2 || count <= 6){
        //     line += (temp + ",");
        //     temp.push_back(line);
        // } 

    // vector<Product> products;
    // string temp;
    // int count = 0;
    // for (auto& line : gather_cart) {
    //     stringstream ss(line);
    //     string temp;
    //     getline(ss, temp, ',');//IID
    //     getline(ss, temp, ',');//PID
    //     products[count].setProductID(temp);
    //     getline(ss, temp, ',');//STOCK
    //     getline(ss, temp, ',');//BRAND
    //     products[count].setBrand(temp);
    //     getline(ss, temp, ',');//NAME
    //     products[count].setName(temp);
    //     getline(ss, temp, ',');//PRICE
    //     products[count].setPrice(stoi(temp));
    //     //I dont need line i want each Element of vector that is Product to hold its data member
    // }

    vector<Product> products(gather_cart.size());
    int count = 0;
    for (auto& line : gather_cart) {
        stringstream ss(line);
        string temp;
        getline(ss, temp, ',');//IID
        getline(ss, temp, ',');//PID
        products[count].setProductID(temp);
        getline(ss, temp, ',');//STOCK
        getline(ss, temp, ',');//BRAND
        products[count].setBrand(temp);
        getline(ss, temp, ',');//NAME
        products[count].setName(temp);
        getline(ss, temp, ',');//PRICE
        products[count].setPrice(stoi(temp));
        count++;
    }    
        //Reading Algorithm
        // string line;
        // istringstream read_string;
        //     //read_string.str(line);
        // while(getline(file_reader_product,line)){
        //     istringstream read_string(line);

        //     getline(read_string >> ws, IID, ',');
        //     getline(read_string >> ws, productID, ',');
        //     getline(read_string >> ws, Stock, ',');
        //     getline(read_string >> ws, brand, ',');
        //     getline(read_string >> ws, product_name, ',');
        //     getline(read_string >> ws, temp, ',');
        //     price = stoi(temp);
        //     //Specific Category wise attributes can be defined here
        //     getline(read_string >> ws, description, '\n');
        // }

    //}
    cout << "DONE EXTRACTING ... " << endl;

    // for(int i = 0; i < products.size() ; i++){
    //     cout << i+1 << " |" << products[i] << endl;
    // }
    return products;
}

