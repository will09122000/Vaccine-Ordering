#include <fileIO.cpp>
#include <order.cpp>
#include <customer.cpp>

void addCustomer(string line, vector<Customer> & customers);
void addOrder(string line, vector<Order> & orders,
              vector<Customer> & customers);
void sendOrder(int customerID, vector<Order> & orders,
               vector<Customer> & customers, int & invoiceNumber);
void endDay(string line, vector<Customer> & customers,
            vector<Order> & orders, int & invoiceNumber);
