#include <fileIO.cpp>
#include <order.cpp>

typedef unordered_map<int, Customer> customerMap;

void addCustomer(string line, customerMap & customers);