#include <iostream>
#include <memory>
#include <stack>
#include <vector>
using namespace std;

// Receiver
class Light {
  public:
	void turnOn() {
		cout << "Light is ON\n";
	}

	void turnOff() {
		cout << "Light is OFF\n";
	}
};

// Command Interface
class Command {
  public:
	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual ~Command() = default;
};

// Concrete Command: Turn On
class TurnOnCommand : public Command {
	Light& light;

  public:
	explicit TurnOnCommand(Light& l) : light(l) {}

	void execute() override {
		light.turnOn();
	}

	void undo() override {
		light.turnOff();
	}
};

// Concrete Command: Turn Off
class TurnOffCommand : public Command {
	Light& light;

  public:
	explicit TurnOffCommand(Light& l) : light(l) {}

	void execute() override {
		light.turnOff();
	}

	void undo() override {
		light.turnOn();
	}
};

// Invoker with Undo/Redo
class RemoteControl {
	stack<unique_ptr<Command>> undoStack;
	stack<unique_ptr<Command>> redoStack;

  public:
	void executeCommand(unique_ptr<Command> cmd) {
		cmd->execute();
		undoStack.push(move(cmd));
		// Clear redo stack because new command invalidates redos
		while (!redoStack.empty())
			redoStack.pop();
	}

	void undo() {
		if (undoStack.empty()) {
			cout << "Nothing to undo.\n";
			return;
		}

		auto cmd = move(undoStack.top());
		undoStack.pop();
		cmd->undo();
		redoStack.push(move(cmd));
	}

	void redo() {
		if (redoStack.empty()) {
			cout << "Nothing to redo.\n";
			return;
		}

		auto cmd = move(redoStack.top());
		redoStack.pop();
		cmd->execute();
		undoStack.push(move(cmd));
	}
};

// main()
int main() {
	Light light;
	RemoteControl remote;

	// Execute ON
	remote.executeCommand(make_unique<TurnOnCommand>(light));
	// Execute OFF
	remote.executeCommand(make_unique<TurnOffCommand>(light));

	// Undo last (OFF → ON)
	remote.undo();
	// Undo previous (ON → OFF)
	remote.undo();

	// Redo (OFF → ON)
	remote.redo();
	remote.redo();  // Second redo: should re-execute OFF
}
