#pragma once
#include "observer.hpp"
#include <string>

class Restaurant : public Observer {
  private:
	std::string restaurantName;

  public:
	explicit Restaurant(std::string name);
	void update(Order* order) override;
};