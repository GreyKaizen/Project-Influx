#include <iostream>
#include "Cart.h"

using namespace std;

//(index,Product,quantity)
// void Cart::Add_to_Cart();
// void Cart::remove_from_cart();
void Cart::print_Cart_Products() {
    //After the Products are printed or viewed by the user.
    //Then he will have two choices to either Checkout with Current Cart or Edit the Cart.
    //Checkout executes the Order Class Methods
    //Edit executes the edit_cart method
}
void Cart::edit_Cart(){
    //This method will ask for the index of the Cart Product, then it can remove, change the Quantity if required.
    int list_index;

    cout << "Enter the index of the Cart Product You want to edit : " << endl;
    cin >> list_index;

    //Similar Logic as we once did in lab task we try to remove a product, we will have to create an Cart with items and quantity array less size than original

}
//void Cart::editProduct_Attributes();