#include <iostream>
#include "nameType.h"

using namespace std;

nameType::nameType(string first_name, string last_name){
    this->first_name = first_name;
    this->last_name = last_name;
}

void nameType::setFirstName(string first_name){
    this->first_name = first_name;
}
string nameType::getFirstName() const {
    return first_name;
}

void nameType::setLastName(string last_name){
    this->last_name = last_name;
}
string nameType::getLastName() const {
    return last_name;
}

void nameType::print_name() const {
    cout << "Name : " << getFirstName() << 
    " " << getLastName();
}