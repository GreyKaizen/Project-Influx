
#include <iostream>
#include <string>

using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

int main()
{
    cout << "\033[35m";
    cout << "||======================================================||" << endl;
    cout << "||                 WELCOME TO OUR INFLUX                ||" << endl;
    cout << "||------------------------------------------------------||" << endl;
    cout << "||                PRODUCT LIST AND PRICING              ||" << endl << "\033[35m";
    cout << "||======================================================||" << endl << "\033[31m";
    cout << "||  Product Id   |  Product Name  |   Price   |  Stock  ||" << endl;
    cout << "||    MD1001     |                |           |         ||" << endl;
    cout << "||    EC1001     |                |           |         ||" << endl;
    cout << "||    TY1001     |                |           |         ||" << endl;
    cout << "||    AP1001     |                |           |         ||" << endl;
    cout << "||    UT1001     |                |           |         ||" << endl;
    cout << "||    GR1001     |                |           |         ||" << endl;
    cout << "||    IS1001     |                |           |         ||" << endl << "\033[35m";
    cout << "||------------------------------------------------------||" << endl;
    cout << "||======================================================||" << endl;
    cout << "\033[37m";
    return 0;
}