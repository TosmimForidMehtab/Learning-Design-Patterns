#include <iostream>
#include <memory>
using namespace std;

class Pizza {
  public:
	virtual void prepare() = 0;
	virtual ~Pizza() {}
};

class CheesePizza : public Pizza {
  public:
	void prepare() override {
		cout << "Preparing Cheese Pizza" << endl;
	}
};

class VeggiePizza : public Pizza {
  public:
	void prepare() override {
		cout << "Preparing Veggie Pizza" << endl;
	}
};

// Simple Factory
class PizzaFactory {
  public:
	static unique_ptr<Pizza> createPizza(const string& type) {
		if (type == "cheese")
			return make_unique<CheesePizza>();
		else if (type == "veggie")
			return make_unique<VeggiePizza>();
		else
			throw runtime_error("Unknown pizza type");
	}
};

int main() {
	auto pizza = PizzaFactory::createPizza("veggie");
	pizza->prepare(); // Preparing Veggie Pizza
	return 0;
}
