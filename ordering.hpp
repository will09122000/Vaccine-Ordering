#include <fileIO.cpp>
#include <order.cpp>

typedef unordered_map<int, Customer> customerMap;

void addCustomer(string line, vector<Customer> & customers);
void addOrder(string line, vector<Order> & orders);
void endDay(string line, vector<Customer> & customers, vector<Order> & orders, int & invoiceNumber);