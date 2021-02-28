#include <customer.hpp>

class Customer
{
    public:
        int id;
        string name;
        int orderQuantity = 0;
        vector<Invoice> invoices;

        void addInvoice(Invoice invoice) const
        {
            this->invoices.push_back(invoice);
            cout << "INVOICE ADDED!" << "\n";
        }

        void printInvoice() const
        {
            cout << "INVOICE PRINTED!" << "\n";
        }


        Customer(int id, string name)
        {
            this->id = id;
            this->name = name;
        }
};
