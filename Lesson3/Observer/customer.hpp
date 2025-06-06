#pragma once
#include "observer.hpp"
#include <string>

class Customer : public Observer {
  private:
	std::string name;

  public:
	explicit Customer(std::string name);
	void update(Order* order) override;
};