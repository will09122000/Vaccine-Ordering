#include <order.hpp>

// Getters

int Order::getDate()
{
    return this->date;
}
char Order::getType()
{
    return this->type;
}
int Order::getCustomerID()
{
    return this->customerID;
}
int Order::getQuantity()
{
    return this->quantity;
}

// Constructors

Order::Order(int date, char type, int customerID, int quantity)
{
    this->date = date;
    this->type = type;
    this->customerID = customerID;
    this->quantity = quantity;
}
