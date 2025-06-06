#pragma once
#include "observer.hpp"

class CallCenter : public Observer {
  public:
	void update(Order* order) override;
};