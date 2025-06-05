#include <iostream>
#include <memory>
using namespace std;

class Shape {
  public:
	virtual void draw() const = 0;
	virtual unique_ptr<Shape> clone() const = 0;
	virtual ~Shape() = default;
};

class Circle : public Shape {
  public:
	void draw() const override {
		cout << "Drawing a Circle" << endl;
	}
	unique_ptr<Shape> clone() const override {
		return make_unique<Circle>(*this);
	}
};

class Square : public Shape {
  public:
	void draw() const override {
		cout << "Drawing a Square" << endl;
	}
	unique_ptr<Shape> clone() const override {
		return make_unique<Square>(*this);
	}
};

int main() {
	unique_ptr<Shape> original = make_unique<Circle>();
	unique_ptr<Shape> copy = original->clone();

	original->draw(); // Drawing a Circle
	copy->draw(); // Drawing a Circle

	return 0;
}
