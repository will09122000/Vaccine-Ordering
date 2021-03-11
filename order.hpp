#include <iostream>

/*
    This class represents a single order in the system.
*/
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

        // Constructors
        Order(int date, char type, int customerID, int quantity);
};
