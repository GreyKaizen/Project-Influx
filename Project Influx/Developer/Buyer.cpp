#include <iostream>
#include <cstdlib>
#include "Buyer.h"

using namespace std;

void Buyer::setBuyerID(string BuyerID){
    this->BuyerID=BuyerID;
}

void Buyer::print_info() const {
    cout << endl << endl << "Buyer ID : " << get_buyerID() << endl << "Name of Buyer : " << getName() << endl << "Phone Number : " << getPhoneNumber() << endl << "Balance : " << getBalance() << endl << endl;
}
string Buyer::check_Person() const {
    //Empty Implementation
    return "";
}
void Buyer::write(){
    //Empty Implementation
}

//Needs Seperate File
//Overloading for Standard Buyer
istream&  operator>>(istream& is,Standard_Buyer& buyer) {
    string input;

    // input for inherited data members from Product class
    cout << "Provide Information for Buyer" << endl;
   
    cin.ignore();
    buyer.setBuyerID_std();

    cout << "Name : ";
    getline(is, input);
    buyer.setName(input);
    
    cout << "Phone ";
    getline(is, input);
    input = input.substr(0, 10);
    buyer.setPhoneNumber(stoi(input));

    //input for Buyer data members
    cout << "Balance you want to charge : ";
    getline(is, input);
    buyer.setBalance(stoi(input));

    cout << "Username : ";
    getline(is, input);
    buyer.setUsername(input);

    cout << "Password : ";
    getline(is, input);
    buyer.setPassword(input);

    //Date of Joing Auto Set
    buyer.setDateOfJoining();

    cout << "You have been Registered as a user ..." << endl << "Influx is Place of Mass Selling and Buying Services,\n Have Fun\nCiao..."<< endl;

    return is;

}
ostream&  operator<<(ostream& os, const Standard_Buyer& buyer){

    os << "Buyer Id : " << buyer.get_buyerID() << endl;
    os << "Name: " << buyer.getName() << endl;
    os << "Phone Number: " << buyer.getPhoneNumber() << endl;
    os << "Available Balance : " << buyer.getBalance() << endl;
    os << "UserName: " << buyer.getUsername() << endl;
    os << "Password: " << buyer.getPassword() << endl;
    os << "date of Joining: " << buyer.getDateOfJoining() << endl << endl;

    return os;
}
//Write to File Standard Buyer
void Standard_Buyer::write(){
    // Check if all data members are empty
    if (BuyerID.empty() && available_balance == 0) {
        cout << "Please provide all necessary information before writing." << endl << "Ciao ..." << endl << endl;
        return;
    }
    
    fstream File_Buyer("Users/Buyer.txt",ios::app);
    if (!File_Buyer.is_open()) {
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
    File_Buyer << BuyerID << "," << name << "," << PhoneNumber << "," << available_balance << "," << username << "," << password << "," << date_of_joining << endl;

    // Write data to All_Products file
    All_User << BuyerID << "," << name << "," << PhoneNumber << "," << available_balance << "," << username << "," << password << "," << date_of_joining << endl;

    // Close All_Products file
    File_Buyer.close();
    All_User.close();

    cout << "Data written to files successfully" << endl;

    return;
}

istream&  operator>>(istream& is,EliteBuyer& buyer) {
    string input;

    // input for inherited data members from Product class
    cout << "Provide Information for Buyer" << endl;
   
    cin.ignore();
    buyer.setBuyerID_elt();

    cout << "Name : ";
    getline(is, input);
    buyer.setName(input);
    
    cout << "Phone ";
    getline(is, input);
    input = input.substr(0, 10);
    buyer.setPhoneNumber(stoi(input));

    cout << "Balance you want to charge : ";
    getline(is, input);
    buyer.setBalance(stoi(input));

    cout << "Username : ";
    getline(is, input);
    buyer.setUsername(input);

    cout << "Password : ";
    getline(is, input);
    buyer.setPassword(input);

    //Auto Set the Date of Joining
    buyer.setDateOfJoining();
    
    cout << endl << "Elite Users are Charged Monthly Subscription Fee of 500" << endl << "With That You Have Full Access To All the Features of Influx" << endl << endl;
    buyer.setMonthlySubsciption(500);

    cout << "You have been Registered as a user ..." << endl << "Influx is Place of Mass Selling and Buying Services,\n Have Fun\nCiao..."<< endl;

    return is;

}
ostream&  operator<<(ostream& os, const EliteBuyer& buyer){

    os << "Buyer Id : " << buyer.get_buyerID() << endl;
    os << "Name: " << buyer.getName() << endl;
    os << "Phone Number: " << buyer.getPhoneNumber() << endl;
    os << "Available Balance : " << buyer.getBalance() << endl;
    os << "UserName: " << buyer.getUsername() << endl;
    os << "Password: " << buyer.getPassword() << endl;
    os << "date of Joining: " << buyer.getDateOfJoining() << endl;
    os << "Monthly Subscription: "<<buyer.getMonthlySubsciption()<<endl<< endl;

    return os;
}
//Write to File Standard Buyer
void EliteBuyer::write(){
     // Check if all data members are empty
    if (BuyerID.empty() && available_balance == 0 && monthly_subscription == 0) {
        cout << "Please provide all necessary information before writing." << endl << "Ciao ..." << endl << endl;
        return;
    }
    
    fstream File_Buyer("Users/Buyer.txt",ios::app);
    if (!File_Buyer.is_open()) {
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
    File_Buyer << BuyerID << "," << name << "," << PhoneNumber << "," << available_balance << "," << username << "," << password << "," << date_of_joining << "," << monthly_subscription << endl;

    // Write data to All_Products file
    All_User << BuyerID << "," << name << "," << PhoneNumber << "," << available_balance << "," << username << "," << password << "," << date_of_joining << "," << monthly_subscription << endl;

    // Close All_Products file
    File_Buyer.close();
    All_User.close();

    cout << "Data written to files successfully" << endl;

    return;
}

void Buyer::setBalance(double available_balance){
    this->available_balance = available_balance;
}
double Buyer::getBalance() const{
    return available_balance;
}

//Faizan Start Working From Here

void Buyer::editINFO(){

    cout << "This is Edit Panel of Buyer..." << endl << endl;
    while(true){
        cout << endl << endl << "[A] Change Information" << endl << "[B] Delete Buyer Account" << endl << "[C] Exit/Return " << endl << endl;
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

        //NEXT STOP HERE
        ifstream file_reader("Products/Users/Buyer.txt");
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
        }

        ofstream file_writer("Products/Users/Buyer.txt");

        // Write the updated contents back to the file
        for (auto& line : file_lines) {
            file_writer << line << '\n';
        }
        file_writer.close();

        cout << "Updated contents of file:\n";

    }

    cout << endl << endl << "Buyer Entries Has Been Updated in Influx Database ..." << endl << "Ciao..." << endl;

    return;
}
    
//Need to Implement With Product Class Usage
void Buyer::viewCart(vector<Product>& gather_cart) const {
    cout << "Cart Items ... " << endl;
    for (int i = 0; i < gather_cart.size(); i++){
        cout << "____________________________________________________"<< endl;
        cout << gather_cart[i] << endl;
    }
    
}

string Buyer::get_buyerID() const {
    return BuyerID;
}

//3 DONE //Set this for Std and Elt buyer correctly generated ID
void Standard_Buyer::setBuyerID_std(){
    //No Values taken from outside will generate automatically
    BuyerID = generate_buyerID_std();
    //delete call_generate_ID;
}
string Standard_Buyer::generate_buyerID_std(){
    //To generate unique each time it executes
    srand(time(0));
    int random_generate = rand()%1000;
    string ID = "STD" + to_string(random_generate);
    
    return ID;
}

string Standard_Buyer::check_Person() const {
    return "Std_Buyer";
}

void Standard_Buyer::print_info() const{
    cout << "Buyer ID : " << get_buyerID() << endl << "Name of Buyer : " << getName() << endl << "Phone Number : " << getPhoneNumber() << endl << "username : " << getUsername() << endl << "password : " << getPassword() << endl << "Date of Joining : " << getDateOfJoining() << endl;
}


void EliteBuyer::setBuyerID_elt(){
    //No Values taken from outside will generate automatically
    BuyerID = generate_buyerID_elt();
    //delete call_generate_ID;
}
string EliteBuyer::generate_buyerID_elt(){
    //To generate unique each time it executes
    srand(time(0));
    int random_generate = rand()%1000;
    string ID = "ELT" + to_string(random_generate);
    
    return ID;
}

void EliteBuyer::setMonthlySubsciption(double monthly_subscription) {
    this->monthly_subscription = monthly_subscription;
}

double EliteBuyer::getMonthlySubsciption() const {
    return monthly_subscription; 
}

string EliteBuyer::check_Person() const {
    return "Elt_Buyer";
}
void EliteBuyer::print_info() const{
    cout << "Buyer ID : " << get_buyerID() << endl << "Name of Buyer : " << getName() << endl << "Phone Number : " << getPhoneNumber() << endl << "username : " << getUsername() << endl << "password : " << getPassword() << endl << "Date of Joining : " << getDateOfJoining() << endl << "Monthly Subscription : " << getMonthlySubsciption() << endl;
}

// Invoice::Invoice(){
//     //Empty Implementation
// }


void Invoice :: setInvoiceID()
{
    invoice_id = generate_invoiceID();
}

void Invoice :: setInvoiceType(string in_type)
{   
    if (!in_type.empty())
    {
        Invoice_Type = in_type;
    }
    else
    {
        Invoice_Type = "On Cash";
    }
}

/* Getter Funciton For The Invoice Type */

int Invoice :: getInvoiceID()const{
    return invoice_id;
}

string Invoice::getInvoiceType() const {
    return Invoice_Type;
}


/* Main Function For THe Invoice Type */

int Invoice::generate_invoiceID(){
    //To generate unique each time it executes
    srand(time(0));
    int random_generate = rand()%100000000001;
    //return to the set function
    return random_generate;
}

void Invoice::generate_ReturnDate(){
    /* The Product Must Be returned with in the 3 days for the */
    time_t now = time(0);
    now += 7 * 24 * 60 * 60; // Add 7 days in seconds

    char* date_time = ctime(&now);
    cout << "Return Date: " << date_time << endl;
}

void Invoice :: GenerateInvoiceType()
{
    string in_type[5] = {"Standard invoice", "Proforma invoice", "Commercial invoice", "Credit invoice", "Debit invoice"};
        int option;
        cout << "Please Choose The Invoice Type: \n\t1. Standard invoice \n\t2. Proforma invoice \n\t3. Commercial invoice \n\t4. Credit invoice \n\t5. Debit invoice \n";
        cin >> option;

        if (option == 1) 
        {
            setInvoiceType(in_type[0]);
        } 
        else if (option == 2) 
        {
            setInvoiceType(in_type[1]);
        } 
        else if (option == 3) 
        {
            setInvoiceType(in_type[2]);
        } 
        else if (option == 4) 
        {
            setInvoiceType(in_type[3]);
        } 
        else if (option == 5) 
        {
            setInvoiceType(in_type[4]);
        } 
        else 
        {
            cout<<"Invalid option Selected\n By Default Standard Invoice is Selected "<<endl;
        }
}

Invoice Payment::getInvoice(){
    return invoice;
}

void Payment::setShipcharge(string BuyerType)
{
    int charges;
    
    string user_id = BuyerType;

    string check_user = user_id.substr(0, 3);

    if (check_user == "STD"){

    int bill = getTotalBill();

        if (bill >= 500 && bill < 2000 )
        {
            charges = 100;
        }
        else if ( bill > 2000 && bill < 5000)
        {
            charges = 250;
        }
        else if ( bill >= 5000 && bill < 1000)
        {
            charges = 500;
        }
        else if ( bill >= 10000 )
        {
            charges = 1000;
        }

        double t_bill = bill + charges;
        setTotalBill(t_bill);
    }
    else
    {
        return;
    }
}

void Payment::setTransactionID(){
    transaction_ID = generate_TransactionID();

}

void Payment::setTotalBill(double bil){
    if (bil >= 0)
    {
        total_bill = bil;
    }
    else
    {
        total_bill = 0.0;
    }  
}

void Payment::setPaymentMethod(string Pay_Method){
    this->Pay_Method = Pay_Method;
}

int Payment :: getShippingCharges() const
{
    return shipping_charges;
}
double Payment::getTotalBill() const{
    return total_bill;
}

void Payment :: set_check_giftcard(string g_card)
{
    bool check_g_card = check_gift_card(g_card);

    if (check_g_card == true)
    {
        cout<<"You Gift Card Applied On Your Total Bill"<<endl;
    }
    else
    {
        cout<<"Your Car Was Not Valid Your Total Bill Will Remain The Same"<<endl;
    }
}

int Payment::generate_TransactionID(){
    //To generate unique each time it executes
    srand(time(0));
    int random_generate = rand()%100000000001;
    //return to the set function
    return random_generate;
}
int Payment::getTransactionID() const
{
    return transaction_ID;
}

void Payment::select_PaymentMethod(){
    int input;
    string Methods_of_Payment[5] = {"COD", "Mobile Payment", "MasterCard/VISA", "Credit Card", "Debit Card"};
    cout<<"Please Select One of the Following Options: \n";
    cout<<"1. COD \n2. Debit Card \n3. MasterCard/VISA \n4. Credit Card \n";
    cin>>input;

    if (input == 1) 
    {
        setPaymentMethod(Methods_of_Payment[0]);
    } 
    else if (input == 2) 
    {
        setPaymentMethod(Methods_of_Payment[1]);
    } 
    else if (input == 3) 
    {
        setPaymentMethod(Methods_of_Payment[2]);
    } 
    else if (input == 4) 
    {
        setPaymentMethod(Methods_of_Payment[3]);
    } 
    else if (input == 5) 
    {
        setPaymentMethod(Methods_of_Payment[4]);
    } 
    else 
    {
        cout<< "*Invalid method selected, By default payment method COD is selected*"<<endl;
        setPaymentMethod(Methods_of_Payment[0]);
    }
    //this sets the selected method of payment to the data member
}

string Payment::getPaymentMethod() const {
    return Pay_Method;
}

bool Payment::check_Payment(){
    return !(Pay_Method.empty());
}

void Payment :: ApplyDiscount()
{
    string discount_code;
    int discount;

    int option;
    while(option != 2)
    {   
        cout<<"Do you want TO Coupen \n\t 1. Choose 1 To Apply \n\t 2. Some Other Time ..."<<endl;
        cin>>option;
        if(option == 1){
            cout << "Select One Option : \n\t 1.Apply Coupon Card \n\t 2. Apply Gift Card\n 3.I Don't Have Any Gift Card or Coupons "<<endl;
            int choose;
            cin>>choose;

            if (choose > 2 || choose <= 0){
                cout << "Invalid Input, Please Provide  Correct Input."<< endl << endl;
            }
            else if (choose == 1)
            {
                cout<<"Please Enter The Coupon Code : ";
                getline(cin,discount_code);
                discount = check_Coupon(discount_code);
            }
            else if ( choose == 2)
            {
                cout<<"Please Enter The Gift Card Code : ";
                getline(cin,discount_code);
                discount = check_gift_card(discount_code);
            }
        }
        total_bill = total_bill-(total_bill*(discount/100));
    }
}

int Payment :: check_Coupon(string C_code){  
    /*User will enter coupen if it is valid
    Set Coupen Function will cal inside the function to set the 
    Amount Of coupen discout which will be use further */

    //fstream usage to read file and match the coupon in the file
    //Will Reduce the amount of Total Bill
    //Save the coupon in the following format
    //PEHLAORDER2022.20
    //20 in the end represent amount of discount the coupon will give
    ifstream read_file;
    string temp,coupon;

    read_file.open("DiscountCodes/Coupons.txt", ios::app);

    bool flag;
    int discout;

    string price_code;

    if(read_file.is_open())
    {
        while (getline(read_file,temp))
        {
            stringstream ss(temp);
            getline(ss,coupon,';');
            getline(ss,price_code,';');

            if(C_code == coupon)
            {
                discout = stoi(price_code);
                flag = true;
                break;
            }
            else
            {
                discout = 0;
                flag = false;
            }
        }
    }
    else
    {
        cout<<"The File Does Not Existing"<<endl;
    }            
    read_file.close();
    
    return discout;
}
int Payment :: check_gift_card(string gft_card)
{
    
    bool flag = false;
    int discout;
    string price_code;

    ifstream read_f_file;
    string temp_line,gft_code;

    read_f_file.open("DiscountCodes/Gift_Card.txt", ios::app);
    
    if(read_f_file.is_open())
    {
        while (getline(read_f_file,temp_line))
        {
            stringstream ss(temp_line);
            getline(ss,gft_code,';');
            getline(ss,price_code,';');
            
            if(gft_card == gft_code)
            {
                discout = stoi(price_code);
                flag = true;
                break;
            }
            else
            {
                flag = false;
                discout = 0;
            }
        }
    }
    else
    {
        cout<<"The File Does Not Existing"<<endl;
    }            
    read_f_file.close();
    
    return discout;
}

/* Setter Function Definition */
void Order::setOrderId()
{
    OrderId = generate_OrderID();
}

Payment Order::getPayment(){
    return payment;
}

void Order::setAmount(const vector<Cart>& cart)
{
    Cart temp;
    Amount = (temp.CalculateTotalPrice(cart));
}

void Order::setShippingDetails()
{
    while (1)
    {
	    cout<<"Please Enter The Shippiong Address : ";
        getline(cin,ShippingDetails);
        
        if(!ShippingDetails.empty())
        {
            return;
        }
        else
        {
            cout<<"Please Valid Address.."<<endl;
        }
    }
}

/* Getter Function Definitions*/

string Order::getOrderId() const
{
    return OrderId;
}
double Order::getAmount(){
    return Amount;
}
string Order::getShippingDetails() const
{
    return ShippingDetails;
}

/* Definition OF Main Functions */

string Order::generate_random_word()
{
    static const char alphabets[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string word;
    for (int i = 0; i < 4; i++)
    {
        word += alphabets [rand() % (sizeof(alphabets)) - 1];       
    }
    return word;
}

string Order::generate_OrderID()
{
    srand(time(0));
    string or_id;
    string first = generate_random_word();
    
    int r_num = rand()%10000001;

    string int_to_str = to_string(r_num);
    or_id =first.append(int_to_str);

    return or_id;
}

void Order::cancelOrder()
{
    OrderId.clear();
    ShippingDetails.clear();
    Amount = 0;
    return;
}

void print_Invoice(const Buyer& buyer,const Order& order,const Payment& payment,vector <Cart>& cart, Invoice& invoice) {

    string file_name = buyer.get_buyerID();
    string File_Location = "Invoice/" +file_name+".txt";
    fstream write(File_Location, ios::app);
    /* Buyer Data */
    cout << "=============================================================="<<endl;
    cout << "\t|Buyer ID        :  \t" << buyer.get_buyerID()             <<endl;
    cout << "\t|Buyer Name      :  \t" << buyer.getName()                 <<endl;
    cout << "\t|Phone Number    :  \t" << buyer.getPhoneNumber()          <<endl;

    cout << "\t|Order ID        :  " << order.getOrderId()<<endl;
    cout<<"\tIteams\t\t\tQty\n";
        for(int i = 0 ; i < cart.size() ; i++)
        {
            cout<<i+1<<"."<<cart[i].product<<"\t"<<cart[i].quantity<<endl;
        }
    
    cout << "\t|Shipping Address:  \t" << order.getShippingDetails()<<endl;

    /* Payment Data */

    cout << "\t|Transaction ID  :  \t" << payment.getTransactionID()     <<endl;
    cout << "\t|Payment Detail  :  \t" << payment.getPaymentMethod()     <<endl; 
    cout << "\t|Shipping Charge :  \t" << payment.getShippingCharges()   <<endl;
    cout << "\t|Total Bill      :  \t" << payment.getTotalBill()         <<endl;
    

    /* Invoid Detail */
    cout << "\t|Invoice ID      :  \t" << invoice.getInvoiceID()         <<endl;
    cout << "\t|Invoice Type    :  \t" << invoice.getInvoiceType()       <<endl;
    // invoice.generate_ReturnDate();
    cout << "=============================================================="<<endl;


    write << "=========================================================="<<endl;
    write << "|Buyer ID        : " << buyer.get_buyerID() << "\t|\n";
    write << "|Buyer Name      : " << buyer.getName() << "\t|\n";
    write << "|Phone Number    : " << buyer.getPhoneNumber() <<"\t|\n" << endl;
    write << "|Order ID        : " << order.getOrderId() << "\t|\n";
    write << "|Shipping Detail : " << order.getShippingDetails() <<"\t|\n";
    write << "|Transaction ID  : " << payment.getTransactionID() <<"\t|\n";
    write << "|Payment Detail  : " << payment.getPaymentMethod() <<"\t|\n"; 
    write << "|Shipping Charge : " << payment.getShippingCharges() <<"\t|\n";
    write << "|Total Bill      : " << payment.getTotalBill() <<"\t|\n";
    write << "|Invoice ID      : " << invoice.getInvoiceID() <<"\t|\n";
    write << "|Invoice Type    : " << invoice.getInvoiceType() <<"\t|\n";
    // write <<  invoice.generate_ReturnDate() << endl;
    write << "=========================================================="<<endl;
    write.close();

}

void generate_invoice(const Buyer& buyer,const Order& order, Payment& payment, vector<Cart> cart){
//     //Calls the member Function check_Payement and check that payment is set properly
//     //check_shipping_charges function will also be used, check the header file for logic adn explanation
    payment.invoice.setInvoiceID();
    payment.invoice.GenerateInvoiceType();
    payment.invoice.generate_ReturnDate();
    print_Invoice(buyer,order,payment,cart,payment.invoice);

}

 
void Check_Out(Buyer& buyer, vector<Cart>& cart, Order& order, Payment& payment)
{
    string buyer_id = buyer.get_buyerID();
    
    payment.setTotalBill(order.getAmount());
    payment.setTransactionID();
    payment.select_PaymentMethod();
    payment.ApplyDiscount();

    payment.setShipcharge(buyer_id);
    generate_invoice(buyer,order,payment,cart);
}


void placeOrder(Buyer& buyer, vector<Cart>& cart, Order& order, Payment& payment)
{
    order.setOrderId();
    order.setShippingDetails();
    order.setAmount(cart);

    char choice;
    cout << "Do You want to Checkout ?" << endl;
    cout << "[Y] YES\t [N] NO" << endl;
    cin >> choice;

    if(choice == 'y' || choice == 'Y')
    {
        Check_Out(buyer,cart,order,payment);
    }
    else if (choice == 'n' || choice == 'N')
    {
        order.cancelOrder();
        return;
    }
}
void initiate_Order_Quick_Buy(Buyer& buyer, vector<Cart>& cart)
{
    placeOrder(buyer,cart,(buyer.order),(buyer.order.payment));
}
