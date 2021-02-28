#include <customer.hpp>

class Customer
{
    public:
        int id;
        string name;
        int orderQuantity = 0;
        //vector<Invoice> invoices;

        void printInvoice()
        {

        }


        Customer(int id, string name)
        {
            this->id = id;
            this->name = name;
        }
};
