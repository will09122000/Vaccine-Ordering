#include <customer.hpp>

class Customer
{
    public:
        int id;
        string name;
        int orderQuantity = 0;
        vector<Invoice> invoices;

        void addInvoice(Invoice invoice)
        {
            this->invoices.push_back(invoice);
            cout << this->invoices.back().id << "\n";
        }

        void printInvoice()
        {
            //Invoice invoice = this->invoices.back();
            //cout << this->id << "\n";
        }


        Customer(int id, string name)
        {
            this->id = id;
            this->name = name;
        }
};
