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
        int getDate();

        char getType();

        int getCustomerID();

        int getQuantity();

        Order(int date, char type, int customerID, int quantity);
};
