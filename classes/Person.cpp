#include <iostream>
#include "Person.h"

using namespace std;

Person::Person(string first_name, string last_name, string, string username, string password, int PhoneNumber, int DD, int MM, int YY) : name(first_name, last_name), date_of_joining(DD,MM,YY){
    this->username = username;
    this->password = password;
    this->PhoneNumber = PhoneNumber;
}

void Person::setName(string first_name, string last_name){
    name(first_name, last_name);
}
void Person::getName() const{
    name.print_name();
} //use print_name() of nameType.h

void Person::setUsername(string username) {
    this->username = username;
}
string Person::getUsername() const {
    return username;
}

void Person::setPassword(string password) {
    this->password = password;
}
string Person::getPassword() const{
    return password;
}

void Person::setPhoneNumber(int PhoneNumber) {
    this->PhoneNumber = PhoneNumber;
}
int Person::getPhoneNumber() const {
    return PhoneNumber;
}

void Person::setDateOfJoining(int DD,int MM,int YY) {
    date_of_joining(DD,MM,YY);
}
void Person::getDateOfJoining() const{
    date_of_joining.print_date();
}//use print_date() of dateType.h

//OVERRIDE Methods
void Person::print_info() const = 0;
void Person::check_Person() const = 0;
void Person::changeINFO() = 0;

