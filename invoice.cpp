#include <invoice.hpp>

class Invoice {
    public:
        static int id;
        int date;
        int customerID;
        int quantity;

        Invoice(int date, char type, int customerID, int quantity) {
            this->date = date;
            this->type = type;
            this->customerID = customerID;
            this->quantity = quantity;
        }
};
