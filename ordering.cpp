#include <ordering.hpp>

int main(int argc, char **argv)
{
    validateArguments(argc, argv);
    vector<string> lines = readInput(argc, argv);
    vector<Customer> customers;
    vector<Order> orders;
    int invoiceNumber = 1000;
    cout << "------------------------------------------------------------\n";
    for (vector<string>::const_iterator i = lines.begin(); i != lines.end(); i++)
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
                addOrder(line, orders, customers);
                if (orders.back().getType() == 'X')
                    sendOrder(orders.back().getCustomerID(), orders, customers,
                              invoiceNumber);
                break;
            // End-of-day
            case 'E':
                endDay(line, customers, orders, invoiceNumber);
                break;
        }
        cout << "------------------------------------------------------------\n";
    }
    return 0;
}

void addCustomer(string line, vector<Customer> & customers)
{
    int id = stoi(line.substr(1, 4));
    string name = line.substr(5, 39);
    customers.push_back(Customer(id, name));

    cout << "OP: customer " << setfill('0') << setw(4)
         << customers.back().getId() << " added\n";
}

void addOrder(string line, vector<Order> & orders, vector<Customer> & customers)
{
    int date = stoi(line.substr(1, 8));
    char type = line.at(9);
    int customerID = stoi(line.substr(10, 4));
    int quantity = stoi(line.substr(14, 3));
    orders.push_back(Order(date, type, customerID, quantity));

    for (auto & customer: customers)
    {
        if (customer.getID() == customerID)
        {
            int currentQuantity = customer.getQuantity();
            customer.setOrderQuantity(currentQuantity + quantity);
        }
    }

    string typeString = (type == 'N' ? ": normal order: quantity " :
                        ": EXPRESS order: quantity ");

    cout << "OP: customer " << setfill('0') << setw(4)
         << orders.back().getCustomerID() << typeString
         << orders.back().getQuantity() << "\n";
}

void sendOrder(int customerID, vector<Order> & orders,
               vector<Customer> & customers, int & invoiceNumber)
{
    int totalQuantity = 0;
    int size = orders.size();
    int date;

    for (int i = 0; i < size; i++)
    {
        if (orders[i].getCustomerID() == customerID)
        {
            totalQuantity += orders[i].getQuantity();
            date = orders[i].getDate();
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
        if (customer.getId() == customerID && totalQuantity > 0)
        {
            cout << "OP: customer " << setfill('0') << setw(4) << customerID
                 << ": shipped quantity " << totalQuantity << "\n";
            customer.addInvoice(Invoice(invoiceNumber, customer.getId(),
                                        date, totalQuantity));
            customer.printInvoice();
            invoiceNumber++;
            break;
        }
    }
}

void endDay(string line, vector<Customer> & customers, vector<Order> & orders,
            int & invoiceNumber)
{
    int date = stoi(line.substr(1, 8));
    cout << "OP: end of day " << date << "\n";
    for (auto & customer: customers)
    {
        sendOrder(customer.getId(), orders, customers, invoiceNumber);
    }
}
