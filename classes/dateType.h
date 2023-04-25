#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

using namespace std;

class dateType{
    int DD, MM, YY;

    public:
        dateType(int,int,int);//DONE

        void setDD(int);//DONE
        int getDD() const;//DONE

        void setMM(int);//DONE
        int getMM() const;//DONE
        
        void setYY(int);//DONE
        int getYY() const;//DONE

        void print_date() const;//DONE
};