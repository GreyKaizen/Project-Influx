#include <iostream>
#include <fstream>
#include "Product.h"

using namespace std;

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
bool Product::is_empty(string name){
    if(name == ""){
        return true;
    }
    else{
        return false;
    }
}
bool Product::is_empty(string brand, string name){
    if(name == "" && brand == ""){
        return true;
    }
    else{
        return false;
    }
}
Product* Product::search_Product(){
    //This will store the searched product and if find then return it to main
    Product *search = new Product;

    //The Variables to be Searched
    string brand, product_name;

    //use of fstream to read from file and match the content for search
    fstream file_reader_product;

    //int input_search;
    // int input_searchType_brand, input_searchType_Name, input_searchType_Model;
    bool check_brand = true;
    //string search_text;

    cout << "Before we continue, We Need Following Information," << endl << "Brand, Name of Product" << endl << "If you don't know the brand name, you can leave it empty (Just Press Enter)" << endl ;

    // cin.ignore();
    // cout << "Brand => ";
    // getline(cin,brand);
    // if(brand == "" || brand == "\n" || brand == " "){
    //     check_brand = false;
    // }

    cout << "Name => ";
    getline(cin,product_name);

    cout << "Lets the Magic Search Begin ... " << endl;

    //Algorithm to Open Multiple Files and check in each one of them
    string file[8] = {"Products/Categories/ELC101.txt","Products/Categories/FSH102.txt","Products/Categories/BPC103.txt","Products/Categories/SPO104.txt","Products/Categories/MED105.txt","Products/Categories/TNG106.txt","Products/Categories/PET107.txt","Products/Categories/AUT108.txt"};

    for(int i = 0; i < 8 ; i++){
        //Opening File
        file_reader_product.open(file[i],ios::in);

        //Checking for File Existence
        if(!file_reader_product.is_open()){
            cerr << "Error ... " << endl << "Don't Worry it's will be fixed soon" << endl;
        }    

        //Reading Algorithm
        string line;
        while(getline(file_reader_product,line)){
            // above loop read new line on each iteration

            string characters = "";
            int comma_counter = 0;

            //Range Base Looping to read characters from line
            for(char read_character : line){

            //read_character != ',' ? characters += read_character : void();
            if(read_character != ','){
                characters += read_character;
            }

            if(read_character ==',' && (comma_counter == 0 || comma_counter == 2)){
                characters.clear();
                comma_counter++;
                //continue;
            }
            else if(read_character==',' && comma_counter==1){
                search->setProductID(characters);
                characters.clear();
                comma_counter++;
            }
            else if(read_character==',' && comma_counter==3){
                search->setBrand(characters);
                characters.clear();
                comma_counter++;
            }
            else if(read_character==',' && comma_counter==4){
                search->setName(characters);
                characters.clear();  
                comma_counter++;
            }
            else if(read_character==',' && comma_counter==5){
                //int price = stoi(characters);
                search->setPrice(stoi(characters));
                characters.clear();
                comma_counter++;
                //break;
            }
            else if(read_character=='\n' && comma_counter>5){
                //setBrand(characters);
                search->setDescription(characters);
                characters.clear();
                //comma_counter++;
                //break;
            }

            //resets the search object of Product decalared inside the function when the search object don't find the desired item
            if(check_brand == true){
                if(product_name.compare((search->getName())) && brand.compare(search->getBrand())){
                    search->reset();
                }
                else{ //if match then break out of loop
                    break;
                }
            }
            else{
                if(product_name.compare((search->getName()))){
                    search->reset();
                }
                else{ //if match then break out of loop
                    break;
                }
            }
        }
        //count++;
        // cout << "Brand : " << getBrand() << endl << "Product ID : " << getProductID() << endl << "Product Name : " << getName() << endl << "Product Price : " << getPrice() << endl << endl << "Line Count : " << count << endl;
        // if(file_reader.eof()){
        //     cout << "All items are printed" << endl << count << endl;
        //     break;
        // }
        }

        if(i == 8){
            if(check_brand == true){
                if(product_name.compare((search->getName())) && brand.compare(search->getBrand())){
                    cout << "Sorry, We couldn't find the Product You're Currently Looking For" << endl << "We'll notify you if it available" << endl;
                }
            }
            else{
                if(product_name.compare((search->getName()))){
                    cout << "Sorry, We couldn't find the Product You're Currently Looking For" << endl << "We'll notify you if it available" << endl;
                }
            }
        }
        //Closing File
        file_reader_product.close();
    }

    if(check_brand == false){
        if(search->is_empty(product_name)){
            search = nullptr;
            return search;
        }
    }
    else if(check_brand == true){
        if(search->is_empty(brand,product_name)){
            search = nullptr;
            return search;
        }
    }

    
    cout << "Brand : " << search->getBrand() << endl << "Product ID : " << search->getProductID() << endl << "Product Name : " << search->getName() << endl << "Product Price : " << search->getPrice() << endl << "Description : " << search->getDescription() << endl << endl;
 
    return search;
    //if found then return object
    //else return nullptr
}

void Product::view_Product(){
    //use of fstream to read and display the product
    //go through all the product files and print them all
    //Empty not printing anything for now
}
        
void Product::setProduct(string, int, string){
    //We have selected types of Products (Electronics, Fashion, Beauty and Personal Care, Sports and Outdoors, Health and Wellness, Toys and Games, Pet Supplies, Automotive, Books and Stationery)

    int input;
    string Product_Categories[9] = {"Electronics","Fashion", "Beauty and Personal Care", "Sports and Outdoors", "Health and Wellness", "Toys and Games", "Pet Supplies", "Automotive", "Books and Stationery"};

    for (int i = 0 ; i < 9 ; i++){
        cout << i+1 << ". " << Product_Categories[i] << endl;
        if(i == 9){
            cout << "Choose the Category You Want to Enlist your Products in ... " << endl;
            cin >> input;
        }
    }

    string product_file = Product_Categories[input]+"txt";

    //from here file handling to write the product in the list will be used

    //STATUS :: NOT DONE
}
//string Product::getProduct();

//From Inventory, Product Manipulation
//Check Person First, for Admin ONLY
//checkPerosn_Call() can be utilized here too
void Product::editProduct(){

}
void Product::deleteProduct(){
    
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
void Product::print_Inventory_Products(string InventoryID){
    string file_name_inventory = InventoryID + ".txt";
}

//Print Cart Products
//void Product::print_Cart_Products(Product[]);
//For Seller to print his products, sellewill enter his ID to view all the products his selling on out platform

//before calling this call getter for seller id and pass it as a parameter to this function
void Product::print_Seller_products(int sellerID){
    //matching items to that seller id will get printed out
}

void Electronics::view_Product(){
    //Will read the file of Electronic Products
    fstream file_reader("Products/Categories/ELC101.txt",ios::in);
    //string line;

    if(!file_reader.is_open()){
        cerr << "Failed to open file" << endl;
        return;
    }

    int count = 0;
    // while(getline(file_reader, line)){
    //     string variable_assigning;
    //     // cout << line << endl;
    //     // cout << "Line Number : " << count <<endl;
    //     // count++;

    //     //Logic For Assigning to Varaible
    //      int comma_counter = 0;
    //      string variable;
    //     char str;
    //     string variable_assigning;

    //     //range loop don't work on fstream variable
    //     // for(charwhile(getline(file_reader, line)){
    //     // cout << line << endl;
    //     // cout << "Line Number : " << count <<endl;
    //     // count++;

    //     //Logic For Assigning to Varaible
    //     int comma_counter = 0;
    //     string variable;
    //        char str;

    //     while(file_reader.get(str)){
    //         //cout << "inside Loop " << endl;
    //         // if(str!=','){
    //         //     variable += str;
    //         // }
    //         // else{
    //         //     //don't do anything
    //         // }
    //         str != ',' ? variable += str : void();

    //         //cout << variable << endl;
    //         if(str=='\n' || count == 27){
    //             break;
    //             //This can tell us how many products are currently listed
    //             //count++;
    //         }
    //         else if(str==',' && comma_counter==0){
    //             // //productID = variable;
    //             // cout << "Inside ID: " << variable << endl;
    //             // setProductID(variable);
    //             variable.clear();
    //             comma_counter++;
    //         }
    //         else if(str==',' && comma_counter==1){
    //             //productID = variable;
    //             cout << "Inside ID: " << variable << endl;
    //             setProductID(variable);
    //             variable.clear();
    //             comma_counter++;
    //         }
    //         else if(str==',' && comma_counter==2){
    //             // //productID = variable;
    //             // cout << "Inside ID: " << variable << endl;
    //             // setProductID(variable);
    //             variable.clear();  
    //             comma_counter++;
    //         }
    //         else if(str==',' && comma_counter==3){
    //             //product_name = variable;
    //             cout << "Inside Name: " << variable << endl;
    //             setName(variable);
    //             variable.clear();
    //             comma_counter++;
    //         }
    //         else if(str==',' && comma_counter==4){
    //             // //productID = variable;
    //             // cout << "Inside ID: " << variable << endl;
    //             // setProductID(variable);
    //             variable.clear();  
    //             comma_counter++;
    //         }
    //         else if(str==',' && comma_counter==5){
    //             //price = stoi(variable);
    //             cout << "Inside Price : " << variable << endl;
    //             setPrice(stoi(variable));
    //             variable.clear();
    //             comma_counter++;
    //         }
    //         // if(comma_counter == 0 || comma_counter == 2){
    //         //     comma_counter++;
    //         // }

    //         //Testing Logic
    //         // else if(count==1){
    //         //     break;
    //         // }
    //         // cout << str;
    //         // if(str=='\n'){
    //         //     comma_counter++;
    //         //     continue;
    //         // }
    //         // if(comma_counter==2){
    //         //     return;
    //         // }
    //     }   

    //     //range loop don't work on fstream variable
    //     // for(char str : variable_assigning){
    //     //     variable += str;
    //     //     // if(str != '\n' && str != ' ' && str != '\t' && str != '\r'){
    //     //     //     key_identifier += str;
    //     //     // }
    //     // }
    // //} str : variable_assigning){
    //     //     variable += str;
    //     //     // if(str != '\n' && str != ' ' && str != '\t' && str != '\r'){
    //     //     //     key_identifier += str;
    //     //     // }
    //     // }
    // }
    // //cout << "Entering Loop " << endl;

    //     cout << "Count :" << count << endl;
    //     cout  << "Product Name: " << getName() << endl << "Product ID: " << getProductID() << endl << "Product Price : " << getPrice() << endl;

    string line;
    while(getline(file_reader,line)){
        string characters = "";
        int comma_counter = 0;
        for(char read_character : line){

            if(read_character == '\n'){
                //breaks the inner loop and next line start for execution
                break;
            }

            //read_character != ',' ? characters += read_character : void();
            if(read_character != ','){
                characters += read_character;
            }

            if(read_character=='\n' || count == 27){
                break;
                //This can tell us how many products are currently listed
                //count++;
            }

            if(read_character ==',' && (comma_counter == 0 || comma_counter == 2)){
                characters.clear();
                comma_counter++;
                continue;
            }
            else if(read_character==',' && comma_counter==1){
                setProductID(characters);
                characters.clear();
                comma_counter++;
            }
            // else if(read_character ==',' && comma_counter == 2){
            //     characters.clear();
            //     comma_counter++;
            //     //continue;
            // }
            else if(read_character==',' && comma_counter==3){
                setBrand(characters);
                characters.clear();
                comma_counter++;
            }
            else if(read_character==',' && comma_counter==4){
                setName(characters);
                characters.clear();  
                comma_counter++;
            }
            else if(read_character==',' && comma_counter==5){
                //int price = stoi(characters);
                setPrice(stoi(characters));
                characters.clear();
                comma_counter++;
            }
        }
        count++;
        
        cout << "Brand : " << getBrand() << endl << "Product ID : " << getProductID() << endl << "Product Name : " << getName() << endl << "Product Price : " << getPrice() << endl << endl << "Line Count : " << count << endl;
        if(file_reader.eof()){
            cout << "All items are printed" << endl << count << endl;
            break;
        }
    }
    file_reader.close();

}