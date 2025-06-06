#include "customer.hpp"
#include "order.hpp"
#include <iostream>

Customer::Customer(std::string name) : name(name) {}

void Customer::update(Order* order) {
	std::cout << "Hello, " << name << "! Order #" << order->getId() << " is now " << order->getStatus() << std::endl;
}
