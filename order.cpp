#include <order.hpp>

class Order
{
    int date;
    char type;
    int customerID;
    int quantity;

    public:
        // getters
        int getDate()
        {
            return this->date;
        }
        char getType()
        {
            return this->type;
        }
        int getCustomerID()
        {
            return this->customerID;
        }
        int getQuantity()
        {
            return this->quantity;
        }

        void ship()
        {
            cout << "Ship Orders!\n";
        }

        Order(int date, char type, int customerID, int quantity)
        {
            this->date = date;
            this->type = type;
            this->customerID = customerID;
            this->quantity = quantity;
        }
};
