#include "order.hpp"

Order::Order(int id) : id(id), status("Order Placed") {}

int Order::getId() {
	return id;
}

std::string Order::getStatus() {
	return status;
}

void Order::setStatus(std::string newStatus) {
	status = newStatus;
	notifyObservers();
}

void Order::attach(Observer* observer) {
	observers.push_back(observer);
}

void Order::detach(Observer* observer) {
	for (auto it = observers.begin(); it != observers.end(); ++it) {
		if (*it == observer) {
			observers.erase(it);
			break; // Assuming each observer can be attached only once
		}
	}
}

void Order::notifyObservers() {
	for (Observer* observer : observers) {
		observer->update(this);
	}
}
