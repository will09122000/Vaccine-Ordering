#include <customer.hpp>

class Customer
{
    public:
        int id;
        string name;
        int orderQuantity = 0;
        std::vector<Invoice> invoices;

        void printInvoice()
        {

        }


        Customer(int id, string name)
        {
            this->id = id;
            this->name = name;
        }
};
