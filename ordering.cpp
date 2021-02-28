#include <ordering.hpp>

int main(int argc, char **argv)
{
    validateArguments(argc, argv);
    vector<string> lines = readInput(argc, argv);
    vector<Customer> customers;
    vector<Order> orders;
    int invoiceNumber = 1000;

    for (vector<string>::const_iterator i = lines.begin(); i != lines.end(); ++i)
    {
        string line = *i;
        switch(line.front()) 
        {
            // New customer
            case 'C':
                addCustomer(line, customers);
                break;
            // New order
            case 'S':
                addOrder(line, orders);
                if (orders.back().type == 'X')
                    sendOrder(orders.back().customerID, orders, customers, invoiceNumber);
                break;
            // End-of-day
            case 'E':
                endDay(line, customers, orders, invoiceNumber);
                break;
        }
        cout << "-------------------------------------------------------------------\n";
    }
    return 0;
}

void addCustomer(string line, vector<Customer> & customers)
{
    int id = stoi(line.substr(1, 4));
    string name = line.substr(5, 39);
    customers.push_back(Customer(id, name));

    cout << "OP: customer " << setfill('0') << setw(4) << customers.back().id << " added\n";
}

void addOrder(string line, vector<Order> & orders)
{
    int date = stoi(line.substr(1, 8));
    char type = line.at(9);
    int customerID = stoi(line.substr(10, 4));
    int quantity = stoi(line.substr(14, 3));
    orders.push_back(Order(date, type, customerID, quantity));

    string typeString = (type == 'N' ? ": normal order: quantity " : ": EXPRESS order: quantity ");
    cout << "OP: customer " << setfill('0') << setw(4) << orders.back().customerID << typeString << orders.back().quantity << "\n";
}

void sendOrder(int customerID, vector<Order> & orders, vector<Customer> & customers, int & invoiceNumber)
{
    int totalQuantity = 0;
    int size = orders.size();
    int date;

    for (int i = 0; i < size; ++i)
    {
        if (orders[i].customerID == customerID)
        {
            totalQuantity += orders[i].quantity;
            date = orders[i].date;
            orders.erase(orders.begin() + i);
        }
        if (size != (int)orders.size())
        {
            --i;
            size = orders.size();
        }
    }

    for (auto & customer: customers)
    {
        if (customer.id == customerID && totalQuantity > 0)
        {
            cout << "OP: customer " << setfill('0') << setw(4) << customerID << ": shipped quantity " << totalQuantity << "\n";
            customer.addInvoice(Invoice(invoiceNumber, customer.id, date, totalQuantity));
            customer.printInvoice();
            invoiceNumber++;
            break;
        }
    }
}

void endDay(string line, vector<Customer> & customers, vector<Order> & orders, int & invoiceNumber)
{
    int date = stoi(line.substr(1, 8));
    cout << "OP: end of day " << date << "\n";
    for (auto & customer: customers)
    {
        sendOrder(customer.id, orders, customers, invoiceNumber);
    }
}
