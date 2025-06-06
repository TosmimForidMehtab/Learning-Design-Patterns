#include "delivery_driver.hpp"
#include "order.hpp"
#include <iostream>

DeliveryDriver::DeliveryDriver(std::string name) : driverName(name) {}

void DeliveryDriver::update(Order* order) {
	std::cout << driverName << ": Order #" << order->getId() << " is now " << order->getStatus() << std::endl;
}
