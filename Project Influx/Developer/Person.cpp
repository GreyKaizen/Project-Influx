#include <iostream>
#include "Person.h"
#include <chrono>
#include <ctime>

using namespace std;

// Person::Person(string first_name, string last_name, string, string username, string password, int PhoneNumber, int DD, int MM, int YY) : name(first_name, last_name), date_of_joining(DD,MM,YY){
//     this->username = username;
//     this->password = password;
//     this->PhoneNumber = PhoneNumber;
// }

//Where did you remove the nameType

void Person::setName(string name){
    this->name = name;
}

string Person::getName() const{
    return name;
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

void Person::setDateOfJoining() {
    auto now = chrono::system_clock::now();
    time_t time = chrono::system_clock::to_time_t(now);

    // Convert the time to a string
    char buffer[80];
    strftime(buffer, 80, "%d-%m-%Y", localtime(&time));
    string date(buffer);
    date_of_joining = date;
}
string Person::getDateOfJoining() const{
    return date_of_joining;
}//use print_date() of dateType.h

// //OVERRIDE Methods
// void Person::print_info() const = 0;
// void Person::check_Person() const = 0;
// void Person::changeINFO() = 0;

