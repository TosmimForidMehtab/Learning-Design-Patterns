#include <iostream>
#include <memory>
using namespace std;

// Product class
class House {
  public:
	void setWalls(const string& w) { walls = w; }
	void setRoof(const string& r) { roof = r; }
	void setGarage(const string& g) { garage = g; }

	void show() const {
		cout << "House with " << walls << ", " << roof << ", and " << garage << endl;
	}
  private:
	string walls, roof, garage;
};

// Abstract Builder class
class HouseBuilder {
  public:
	virtual void buildWalls() = 0;
	virtual void buildRoof() = 0;
	virtual void buildGarage() = 0;
	virtual unique_ptr<House> getHouse() = 0;
	virtual ~HouseBuilder() = default;
};

// Concrete Builder class
class LuxuryHouseBuilder : public HouseBuilder {
	unique_ptr<House> house;
  public:
	LuxuryHouseBuilder() : house(make_unique<House>()) {}

	void buildWalls() override { house->setWalls("Marble Walls"); }
	void buildRoof() override { house->setRoof("Glass Roof"); }
	void buildGarage() override { house->setGarage("2-Car Garage"); }

	unique_ptr<House> getHouse() override { return move(house); }
};

// Director class
class Engineer {
	HouseBuilder& builder;
  public:
	explicit Engineer(HouseBuilder& b) : builder(b) {}
	unique_ptr<House> construct() {
		builder.buildWalls();
		builder.buildRoof();
		builder.buildGarage();
		return builder.getHouse();
	}
};

int main() {
	LuxuryHouseBuilder builder;
	Engineer engineer(builder);
	auto house = engineer.construct();
	house->show(); // House with Marble Walls, Glass Roof, and 2-Car Garage
	return 0;
}
