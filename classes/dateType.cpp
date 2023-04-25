#include <iostream>
#include "dateType.h"

using namespace std;

dateType::dateType(int DD, int MM, int YY)[
    this->DD = DD;
    this->MM = MM;
    this->YY = YY;
]

void dateType::setDD(int DD){
    this->DD = DD;
}
int dateType::getDD() const {
    return DD;
}

void dateType::setMM(int MM){
    this->MM = MM;
}
int dateType::getMM() const {
    return MM;
}

void dateType::setYY(int YY){
    this->YY = YY;
}
int dateType::getYY() const{
    return YY;
}

void dateType::print_date() const {
    cout << "Dated : " << getDD() << "/" << getMM() << "/" << getYY();
}