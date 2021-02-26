#include <fileIO.cpp>
#include <order.cpp>

typedef unordered_map<int, Customer> customerMap;

void addCustomer(string line, customerMap & customers);
void addOrder(string line, vector<Order> & orders);
void endDay(string line, customerMap & customers, vector<Order> & orders);