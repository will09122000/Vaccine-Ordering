#include <string>
#include <vector>
#include <invoice.cpp>

using namespace std;

class Customer
{
    int id;
    string name;
    int orderQuantity = 0;
    vector<Invoice> invoices;

    public:
        // Getters
        int getId();

        // Methods
        void addInvoice(Invoice invoice);
        void printInvoice();

        // Constructors
        Customer(int id, string name);
};
