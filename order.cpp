#include <order.hpp>

class Order
{
        int date;
        char type;
        int customerID;
        int quantity;

    public:
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
