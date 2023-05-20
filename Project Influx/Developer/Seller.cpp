#include <iostream>
#include "Person.h"
#include "Seller.h"
#include <cstdlib>

using namespace std;

void Seller :: setSellerID(string seller_ID){
    this->seller_ID=seller_ID;
}

void Seller::sell_Product(){

}

string Seller::check_Person() const{
    //Empty IMplementations
}

//Overloading Here
istream&  operator>>(istream& is,CommonSeller& seller) {
    string input;

    // input for inherited data members from Product class
    cout << "Provide Information for Seller" << endl;
   
    cin.ignore();
    seller.setSellerID_C_Seller();

    cout << "Name : ";
    getline(is, input);
    seller.setName(input);
    
    cout << "Phone ";
    getline(is, input);
    input = input.substr(0, 10);
    seller.setPhoneNumber(stoi(input));

    //input for Buyer data members
    cout << "Commission Rate set to 25 percentage initially" << endl;
    //getline(is, input);
    seller.setCommissionMargin(25);

    cout << "Username : ";
    getline(is, input);
    seller.setUsername(input);

    cout << "Password : ";
    getline(is, input);
    seller.setPassword(input);

    seller.setStockSold(0);

    //Date of Joing Auto Set
    seller.setDateOfJoining();
    
    //cout << "You have been Registered as a user ..." << endl << "Influx is Place of Mass Selling and Buying Services,\n Have Fun\nCiao..."<< endl;

    return is;
}
ostream&  operator<<(ostream& os, const CommonSeller& seller){

    os << "Buyer Id : " << seller.getSellerID() << endl;
    os << "Name: " << seller.getName() << endl;
    os << "Phone Number: " << seller.getPhoneNumber() << endl;
    os << "Commission Rate : " << seller.getCommissionMargin() << endl;
    os << "UserName: " << seller.getUsername() << endl;
    os << "Password: " << seller.getPassword() << endl;
    os << "date of Joining: " << seller.getDateOfJoining() << endl << endl;

    return os;
}
//Overloading Here
istream&  operator>>(istream& is,WholeSaler& seller) {
    string input;

    // input for inherited data members from Product class
    cout << "Provide Information for Seller" << endl;
   
    cin.ignore();
    seller.setSellerID_whlSaler();

    cout << "Name : ";
    getline(is, input);
    seller.setName(input);
    
    cout << "Phone ";
    getline(is, input);
    input = input.substr(0, 10);
    seller.setPhoneNumber(stoi(input));

    //input for Seller data members
    cout << "Commission Rate set to 25 percentage initially" << endl;
    //getline(is, input);
    seller.setCommissionMargin(25);

    cout << "Username : ";
    getline(is, input);
    seller.setUsername(input);

    cout << "Password : ";
    getline(is, input);
    seller.setPassword(input);

    seller.setStockSold(0);

    cout << endl;
    cout << "As a WholeSaler, you can only sell items of One Brand..." << endl << "Provide Your Supplier Brand Name : ";
    getline(is, input);
    seller.setBrand(input);

    //Date of Joing Auto Set
    seller.setDateOfJoining();

    //cout << "You have been Registered as a user ..." << endl;
    cout << endl << "Influx is Place of Mass Selling and Buying Services,\n Have Fun\nCiao..."<< endl << endl;

    return is;
}
ostream&  operator<<(ostream& os, const WholeSaler& seller){

    os << "Seller Id : " << seller.getSellerID() << endl;
    os << "Name: " << seller.getName() << endl;
    os << "Brand : " << seller.getBrand() << endl;
    os << "Phone Number: " << seller.getPhoneNumber() << endl;
    os << "Commission Rate" << seller.getCommissionMargin() << endl;
    os << "UserName: " << seller.getUsername() << endl;
    os << "Password: " << seller.getPassword() << endl;
    os << "date of Joining: " << seller.getDateOfJoining() << endl << endl;

    return os;
}

void Seller::setBrand(string brand){
    this->brand = brand;
}
string Seller::getBrand() const {
    return brand;
}

void WholeSaler::setSellerID_whlSaler(){
    seller_ID = generate_sellerID_whlSaler();
}
string WholeSaler::generate_sellerID_whlSaler(){
    //To generate unique each time it executes
    srand(time(0));
    int random_generate = rand()%1000;
    string ID = "WHL" + to_string(random_generate);
    //return to the set function
    return ID;
}
//Overridde method to check personType
string WholeSaler::check_Person() const{
    return "Whl_Seller";
}

void CommonSeller::setSellerID_C_Seller(){
    seller_ID = generate_sellerID_C_Seller();
}
string CommonSeller::generate_sellerID_C_Seller(){
    //To generate unique each time it executes
    srand(time(0));
    int random_generate = rand()%1000;
    string ID = "CMN" + to_string(random_generate);
    //return to the set function
    return ID;
}

string CommonSeller::check_Person() const{
    return "Com_Seller";
}


void Seller::write(){
    // Check if all data members are empty
    if (seller_ID.empty() && commission_margin == 0 && stockSold ==0) {
        cout << "Please provide all necessary information before writing." << endl << "Ciao ..." << endl << endl;
        return;
    }
    
    fstream File_Seller("Users/Seller.txt",ios::app);
    if (!File_Seller.is_open()) {
        cerr << "Error opening All_Products file for writing" << endl;
        return;
    }

    //All Product List Update
    fstream All_User("Users/All_User.txt", ios::app);
    if (!All_User.is_open()) {
        cerr << "Error opening All_Products file for writing" << endl;
        return;
    }

    //Category have all information
    File_Seller << seller_ID << "," << name << "," << PhoneNumber << "," << commission_margin << "," << username << "," << password << "," << date_of_joining << "," << brand << endl;

    // Write data to All_Products file
    All_User << seller_ID << "," << name << "," << PhoneNumber << "," << commission_margin << "," << username << "," << password << "," << date_of_joining << "," << brand << endl;

    // Close All_Products file
    File_Seller.close();
    All_User.close();

    //cout << "Data written to files successfully" << endl;

    return;    
}

string Seller::getSellerID() const {
    return seller_ID;
}

//Pure Virtual
//void Seller::access_Inventory();

void Seller::setCommissionMargin(int commission_margin){
    this->commission_margin = commission_margin;
}
int Seller::getCommissionMargin() const {
    return commission_margin;
}

void Seller::setStockSold(int stockSold){
    this->stockSold = stockSold;
}
int Seller::getStockSold() const {
    return stockSold;
}


void Seller::print_info() const {
    cout << "Seller ID : " << getSellerID () << endl << "Name of Buyer : " << getName() << endl << "Phone Number : " << getPhoneNumber() << endl << "Commission Rate : " << getCommissionMargin() << endl;
    string read_ID = getSellerID();
    // if(read_ID.substr(0,3) == "WHL"){
    //     cout << "Brand Name : " << getBrand() << endl << endl;
    // }
}

//A vector Function that is used in the editProduct() below it.
vector<string> split_string_contents( string& str, char delimiter) {
    //tokens => FullLine
    //token  => partOfLine
    //delimiter => Vantage Point

    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void Seller::editINFO(){
    
    cout << "This is Edit Panel of Seller..." << endl << endl;
    while(true){
        cout << endl << endl << "[A] Change Information" << endl << "[B] Delete Account" << endl << "[C] Exit/Return " << endl << endl;
        cout << "Awating Response =>  ";
        char choose_action;
        cin >> choose_action;
        if(choose_action == 'C' || choose_action == 'c'){
            break;
        }
        if(choose_action != 'A' || choose_action != 'a' || choose_action != 'B' || choose_action != 'b'){
            cout << endl << "Invalid Input Provided ..." << endl << "Please Check and Try Again " << endl << endl << "Awating Response =>  ";

            continue;
        }

        //NEXT STOP HERE
        ifstream file_reader("Users/Seller.txt");
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
            vector<string> FullLines = split_string_contents(entry, ',');
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
        else if(choose_action == 'B' || choose_action == 'b'){
            //Delete Logic

            int lineToDelete;
            cout << endl << endl << "Enter the Index of Line You Want to Delete" << endl << "ENTER -1 to EXIT DELETE MODE" << endl << "Awating Response =>  ";
            cin >> lineToDelete;

            if(lineToDelete == -1){
                continue;
            }

            char final_choice;
            while(true){
                cout << "Are You Sure You Want to Delete Your Account" << endl << endl << "[Y] YES\t[N] NO";
                cout << "Awaiting Response =>  ";

                if(final_choice == 'N' || final_choice == 'n'){
                    break;
                }
                if(choose_action != 'Y' && choose_action != 'y' && choose_action != 'N' && choose_action != 'n'){
                    cout << endl << "Invalid Input Provided ..." << endl << "Please Check and Try Again " << endl << endl << "Awating Response =>  ";
                }

            }

            if(final_choice == 'N' || final_choice == 'n'){
                continue;
            }
            if(final_choice == 'Y' || final_choice == 'y'){
                if (lineToDelete >= 1 && lineToDelete <= file_lines.size()) {
                    file_lines.erase(file_lines.begin() + lineToDelete - 1);
                } else {
                    cerr << "Error: Line number is out of range\n";
                }
            }
                    
            //Test Code for Printing
            //     for (auto& single_line : file_lines) {
            //     cout << "___________________________________________________________________________";
            //     cout << count+1 << ". " << single_line << '\n';
            //     count++;
            // }
        }

        ofstream file_writer("Users/Seller.txt");

        // Write the updated contents back to the file
        for (auto& line : file_lines) {
            file_writer << line << '\n';
        }
        file_writer.close();

        cout << "Updated contents of file:\n";

    }

    cout << endl << endl << "Seller Entries Has Been Updated in Influx Database ..." << endl << "Ciao..." << endl;

    return;
}

string Seller::matchAndReturnEighthToken(string match1, string match2, string match3, string filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        int count = 0;
        while (getline(ss, token, ',')) {
            count++;
            if (count == 1 && token.substr(0, 3) != match1) {
                break;
            }
            if (count == 5 && token != match2) {
                break;
            }
            if (count == 6 && token != match3) {
                break;
            }
            if (count == 8) {
                return token;
            }
        }
    }
    return ""; // Return an empty string if no matching line is found
}

void WholeSaler::sell_Product(Seller& seller){

    string Brand_of_WholeSaler;

    Brand_of_WholeSaler = seller.matchAndReturnEighthToken("WHL",seller.getUsername(),seller.getPassword(),"Users/All_User.txt");
   
    cout << "Whole Seller can only sell Products of One Brand in Bulk(More than 50), Dozens..." << endl << endl;

    cout << "Select from the Following Categories," << endl << "1. Electronics" << endl << "2. Fashion" << endl << "3. Beauty and Personal Care" << endl << "4. Sports and Outdoors" << endl << "5. Medicine" << endl << "7. Toys and Games" << endl << "8. Automative" << endl << endl << "Awaiting Response => ";
    
    int input;
    while(1){
        cin >> input;
        if(input <= 0 || input > 8){
            cout << endl << "Invalid Input ... " << endl << "Please Choose Correctly from above mentioned Categories" << endl << endl;
        }
        if(input > 0 || input <= 8){
            break;
        }
    }


    if(input == 1){
        Electronics products;
        cin >> products;
        if((products.getBrand() == Brand_of_WholeSaler) ){
            products.write();
        }
        else{
            cout << "Aha!!" << endl << "Dear, you are as a Whole Saler, You can Sell Products of One Brand Only" << endl << endl;
            return;
        }
    }
    else if(input == 2){
        Fashion products;
        cin >> products;
        if((products.getBrand() == Brand_of_WholeSaler) ){
            products.write();
        }
        else{
            cout << "Aha!!" << endl << "Dear, you are as a Whole Saler, You can Sell Products of One Brand Only" << endl << endl;
            return;
        }
    }
    else if(input == 3){
        BeautyAndPersonalCare products;
        cin >> products;
        if((products.getBrand() == Brand_of_WholeSaler) ){
            products.write();
        }
        else{
            cout << "Aha!!" << endl << "Dear, you are as a Whole Saler, You can Sell Products of One Brand Only" << endl << endl;
            return;
        }
    }
    else if(input == 4){
        SportsAndOutdoors products;
        cin >> products;
        if((products.getBrand() == Brand_of_WholeSaler) ){
            products.write();
        }
        else{
            cout << "Aha!!" << endl << "Dear, you are as a Whole Saler, You can Sell Products of One Brand Only" << endl << endl;
            return;
        }
    }
    else if(input == 5){
        MedsAndHerbs products;
        cin >> products;
        if((products.getBrand() == Brand_of_WholeSaler) ){
            products.write();
        }
        else{
            cout << "Aha!!" << endl << "Dear, you are as a Whole Saler, You can Sell Products of One Brand Only" << endl << endl;
            return;
        }
    }
    else if(input == 6){
        ToysAndGames products;
        cin >> products;
        if((products.getBrand() == Brand_of_WholeSaler) ){
            products.write();
        }
        else{
            cout << "Aha!!" << endl << "Dear, you are as a Whole Saler, You can Sell Products of One Brand Only" << endl << endl;
            return;
        }
    }
    else if(input == 7){
        PetSupplies products;
        cin >> products;
        if((products.getBrand() == Brand_of_WholeSaler) ){
            products.write();
        }
        else{
            cout << "Aha!!" << endl << "Dear, you are as a Whole Saler, You can Sell Products of One Brand Only" << endl << endl;
            return;
        }
    }
    else if(input == 8){
        Automotive products;
        cin >> products;
        if((products.getBrand() == Brand_of_WholeSaler) ){
            products.write();
        }
        else{
            cout << "Aha!!" << endl << "Dear, you are as a Whole Saler, You can Sell Products of One Brand Only" << endl << endl;
            return;
        }
    }

    cout << endl << endl << "Product Has Been Successfully listed in Influx Database, Thank You for being a Part of Influx and Keep Influx Going for greater Good..." << endl << "Ciao..." << endl;

    return;
}

void CommonSeller::sell_Product(){
    Product product;
    product.setProduct();
}