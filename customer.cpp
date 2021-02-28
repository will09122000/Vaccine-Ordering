#include <customer.hpp>

class Customer
{
    public:
        int id;
        string name;
        int orderQuantity = 0;
        vector<Invoice> invoices;

        void printInvoice const()
        {
            cout << "INVOICE PRINTED!" << "\n";
        }


        Customer(int id, string name)
        {
            this->id = id;
            this->name = name;
        }
};
