#include <invoice.hpp>

class Invoice {
    public:
        static int invoiceID;
        int customerID;
        int date;
        int quantity;

        Invoice(int customerID, int date, int quantity) {
            this->invoiceID = 1000;
            this->customerID = customerID;
            this->date = date;
            this->quantity = quantity;
        }
};
