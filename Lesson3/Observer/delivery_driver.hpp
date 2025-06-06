#pragma once
#include "observer.hpp"
#include <string>

class DeliveryDriver : public Observer {
  private:
	std::string driverName;

  public:
	explicit DeliveryDriver(std::string name);
	void update(Order* order) override;
};