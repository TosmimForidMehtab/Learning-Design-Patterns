#include <iostream>
#include <memory>
#include <mutex>
using namespace std;

class Singleton {
  private:
	Singleton() {
		cout << "Singleton Created" << endl;
	}

	static shared_ptr<Singleton> instance;
	static mutex mtx;

  public:
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static shared_ptr<Singleton> getInstance() {
		lock_guard<mutex> lock(mtx);
		if (!instance) {
			instance = shared_ptr<Singleton>(new Singleton());
		}
		return instance;
	}

	void showMessage() const {
		cout << "Hello from Singleton!" << endl;
	}
};

// Initialize static members
shared_ptr<Singleton> Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
	auto s1 = Singleton::getInstance();
	auto s2 = Singleton::getInstance();

	s1->showMessage(); // Hello from Singleton!

	if (s1 == s2) {
		cout << "Only one instance exists." << endl; // This is displayed
	}
	return 0;
}
