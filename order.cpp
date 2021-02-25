#include <order.hpp>

class Order {
    public:
        int date;
        char type;
        int customerNumber;
        int quantity;

        Order(int date, char type, int customerNumber, int quantity) {
            this->date = date;
            this->type = type;
            this->customerNumber = customerNumber;
            this-> quantity = quantity;
        }
};