#include <iostream>
#include "Admin.h"

using namespace std;

void Admin::deleteUser(){
    //Utilize File Handling Here
}

void Admin::editUser(){
    //Utilize File Handling Here
}

void Admin::changeINFO(){
    //Utilize File Handling Here
}

void Admin::check_Person(){
    return "admin";
}

void Admin::print_info(){
    cout << "Admin Name : " << getName() << endl << "username : " << getUsername() << endl << "password : " << getPassword() << endl << "Phone Number : " << getPhoneNumber() << endl;
}