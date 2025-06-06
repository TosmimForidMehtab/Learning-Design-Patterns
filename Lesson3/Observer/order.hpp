#pragma once
#include "observer.hpp"
#include <vector>
#include <string>

class Order {
  private:
	int id;
	std::string status;
	std::vector<Observer*> observers;

  public:
	explicit Order(int id);
	int getId();
	std::string getStatus();
	void setStatus(std::string newStatus);
	void attach(Observer* observer);
	void detach(Observer* observer);
	void notifyObservers();
};