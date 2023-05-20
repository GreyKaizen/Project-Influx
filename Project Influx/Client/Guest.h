#ifndef GUEST_H
#define GUEST_H
#include <iostream>
#include "Person.h"


class Guest : public Person{
    public:
        //register the user to system
        //and log out.
       void register_user();
       //void log_out();
       void print_Register_toBuy() const;//DONE

       string check_Person() const;
       void print_info() const;
       void editINFO();
};
#endif 