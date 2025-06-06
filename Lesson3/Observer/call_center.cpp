#include "call_center.hpp"
#include "order.hpp"
#include <iostream>

void CallCenter::update(Order* order) {
	std::cout << "Call center: Order #" << order->getId() << " is now " << order->getStatus() << std::endl;
}
