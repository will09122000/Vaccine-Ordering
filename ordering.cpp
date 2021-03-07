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

/*
    Function: addCustomer
    ---------------------------------------------------------------------------
    Adds a new customer object to the vector 'customers'.

    line:      input line that is adding a new customer
    customers: vector of customers

    returns:   null
*/
void addCustomer(string line, vector<Customer> & customers)
{
    int id = stoi(line.substr(1, 4));
    string name = line.substr(5, 39);
    customers.push_back(Customer(id, name));

    cout << "OP: customer " << setfill('0') << setw(4)
         << customers.back().getId() << " added\n";
}

/*
    Function: addOrder
    ---------------------------------------------------------------------------
    Adds a new order object to the vector 'orders' and increments the
    customer's total order quantity.

    line:      input line that is adding a new order
    orders:    vector of orders
    customers: vector of customers

    returns:   null
*/
void addOrder(string line, vector<Order> & orders, vector<Customer> & customers)
{
    int date = stoi(line.substr(1, 8));
    char type = line.at(9);
    int customerID = stoi(line.substr(10, 4));
    int quantity = stoi(line.substr(14, 3));
    orders.push_back(Order(date, type, customerID, quantity));

    // Find customer and increment their total order quantity
    for (auto & customer: customers)
    {
        if (customer.getId() == customerID)
        {
            int currentQuantity = customer.getQuantity();
            customer.setQuantity(currentQuantity + quantity);
        }
    }

    string typeString = (type == 'N' ? ": normal order: quantity " :
                        ": EXPRESS order: quantity ");

    cout << "OP: customer " << setfill('0') << setw(4)
         << orders.back().getCustomerID() << typeString
         << orders.back().getQuantity() << "\n";
}

/*
    Function: sendOrder
    ---------------------------------------------------------------------------
    Sends a customer order, triggered either by an express order or the
    end-of-day input line.

    customerID:    customer ID of the orders that are being sent
    orders:        vector of orders
    customers:     vector of customers
    invoiceNumber: invoice number that needs to be assigned to the genterated
                   invoice

    returns:   null
*/
void sendOrder(int customerID, vector<Order> & orders,
               vector<Customer> & customers, int & invoiceNumber)
{
    int size = orders.size();
    int date;

    // Finds the date of orders and removes the orders from the vector
    for (int i = 0; i < size; i++)
    {
        if (orders[i].getCustomerID() == customerID)
        {
            date = orders[i].getDate();
            orders.erase(orders.begin() + i);
        }
        if (size != (int)orders.size())
        {
            --i;
            size = orders.size();
        }
    }

    // Ships the order, adding a new invoice to the customer's invoices and
    // resets their order quantity to 0.
    for (auto & customer: customers)
    {
        if (customer.getId() == customerID && customer.getQuantity() > 0)
        {
            cout << "OP: customer " << setfill('0') << setw(4) << customerID
                 << ": shipped quantity " << customer.getQuantity() << "\n";
            customer.addInvoice(Invoice(invoiceNumber, customer.getId(),
                                        date, customer.getQuantity()));
            
            customer.setQuantity(0);
            customer.printInvoice();
            invoiceNumber++;
            break;
        }
    }
}

/*
    Function: endDay
    ---------------------------------------------------------------------------
    Sends out all orders to customers with orders.

    line:          input line that has stated it is the end of the day
    customers:     vector of customers
    orders:        vector of orders
    invoiceNumber: invoice number that needs to be assigned to the genterated
                   invoice

    returns:   null
*/
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
