#include <iostream>
#include <memory>
using namespace std;

class Transport {
  public:
	virtual void deliver() = 0;
	virtual ~Transport() {}
};

class Truck : public Transport {
  public:
	void deliver() override {
		cout << "Delivering by Truck" << endl;
	}
};

class Ship : public Transport {
  public:
	void deliver() override {
		cout << "Delivering by Ship" << endl;
	}
};

// Abstract Creator
class Logistics {
  public:
	void planDelivery() {
		auto transport = createTransport();
		transport->deliver();
	}
	virtual unique_ptr<Transport> createTransport() = 0;
	virtual ~Logistics() {}
};

// Concrete Creators
class RoadLogistics : public Logistics {
  public:
	unique_ptr<Transport> createTransport() override {
		return make_unique<Truck>();
	}
};

class SeaLogistics : public Logistics {
  public:
	unique_ptr<Transport> createTransport() override {
		return make_unique<Ship>();
	}
};

int main() {
	unique_ptr<Logistics> logistics = make_unique<RoadLogistics>();
	logistics->planDelivery(); // Delivering by Truck
	return 0;
}
