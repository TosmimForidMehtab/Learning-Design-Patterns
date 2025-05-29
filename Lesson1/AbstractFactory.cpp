#include <iostream>
#include <memory>
using namespace std;

// Abstract Products
class Button {
  public:
	virtual void render() = 0;
	virtual ~Button() {}
};

class Checkbox {
  public:
	virtual void render() = 0;
	virtual ~Checkbox() {}
};

// Concrete Products for Windows
class WindowsButton : public Button {
  public:
	void render() override {
		cout << "Rendering Windows Button" << endl;
	}
};

class WindowsCheckbox : public Checkbox {
  public:
	void render() override {
		cout << "Rendering Windows Checkbox" << endl;
	}
};

// Concrete Products for Mac
class MacButton : public Button {
  public:
	void render() override {
		cout << "Rendering Mac Button" << endl;
	}
};

class MacCheckbox : public Checkbox {
  public:
	void render() override {
		cout << "Rendering Mac Checkbox" << endl;
	}
};

// Abstract Factory
class GUIFactory {
  public:
	virtual unique_ptr<Button> createButton() = 0;
	virtual unique_ptr<Checkbox> createCheckbox() = 0;
	virtual ~GUIFactory() {}
};

// Concrete Factories
class WindowsFactory : public GUIFactory {
  public:
	unique_ptr<Button> createButton() override {
		return make_unique<WindowsButton>();
	}
	unique_ptr<Checkbox> createCheckbox() override {
		return make_unique<WindowsCheckbox>();
	}
};

class MacFactory : public GUIFactory {
  public:
	unique_ptr<Button> createButton() override {
		return make_unique<MacButton>();
	}
	unique_ptr<Checkbox> createCheckbox() override {
		return make_unique<MacCheckbox>();
	}
};

// Client
void renderUI(GUIFactory& factory) {
	auto button = factory.createButton();
	auto checkbox = factory.createCheckbox();
	button->render();
	checkbox->render();
}

int main() {
	WindowsFactory windowsFactory;
	MacFactory macFactory;

	renderUI(windowsFactory);
	// Rendering Windows Button
	// Rendering Windows Checkbox
	renderUI(macFactory);
	// Rendering Mac Button
	// Rendering Mac Checkbox

	return 0;
}
