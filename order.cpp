#include <order.hpp>

class Order {
    public:
        int date;
        char type;
        int customerNumber;
        int quantity;
        Customer customer;

        void ship() {
            cout << "Ship Orders!\n";
        }

        Order(int date, char type, int customerNumber, int quantity) {
            this->date = date;
            this->type = type;
            this->customerNumber = customerNumber;
            this->quantity = quantity;
        }
};

/*
class Express: public Order {
    public:
        void ship() {
            cout << "Ship Orders\n";
        }
};
*/
