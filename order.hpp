#include <iostream>
#include <string>

using namespace std;

class Order
{
    int date;
    char type;
    int customerID;
    int quantity;

    public:
        // Getters
        int getDate();
        char getType();
        int getCustomerID();
        int getQuantity();

        // Constructor
        Order(int date, char type, int customerID, int quantity);
};
