#include "order.hpp"
#include "customer.hpp"
#include "restaurant.hpp"
#include "delivery_driver.hpp"
#include "call_center.hpp"
#include <iostream>

int main() {
	// Create an order
	Order order1(123);

	// Create customers, restaurants, drivers, and a call center to track the order
	Customer customer1("Customer 1");
	Restaurant restaurant1("Rest 1");
	DeliveryDriver driver1("Driver 1");
	CallCenter callCenter;

	// Attach observers to the order
	order1.attach(&customer1);
	order1.attach(&restaurant1);
	order1.attach(&driver1);
	order1.attach(&callCenter);

	// Simulate order status updates
	order1.setStatus("Out for Delivery");

	// Detach an observer (if needed)
	order1.detach(&callCenter);

	// Simulate more order status updates
	order1.setStatus("Delivered");

	return 0;
}
