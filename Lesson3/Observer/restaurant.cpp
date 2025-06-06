#include "restaurant.hpp"
#include "order.hpp"
#include <iostream>

Restaurant::Restaurant(std::string name) : restaurantName(name) {}

void Restaurant::update(Order* order) {
	std::cout << restaurantName << ": Order #" << order->getId() << " is now " << order->getStatus() << std::endl;
}
