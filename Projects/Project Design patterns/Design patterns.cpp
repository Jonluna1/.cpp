#include <iostream>
#include <memory>
using namespace std;

// 1. Singleton pattern
class Singleton{
    private:
    static Singleton* instance;

    // Private constructor prevents direct creation
    Singleton() {
        cout << "Singleton Created\n";
    }

    public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void showMessage() {
        cout << "Hello from Singleton\n";
    }
};

Singleton* Singleton::instance = nullptr;

// 2. Factory pattern
class Shape {
    public:
    virtual void draw() = 0;
};

class Circle : public Shape {
    public:
    void draw() override {
        cout << "Drawing Circle\n";
    }
};

class Square : public Shape {
    public:
    void draw() override {
        cout << "Drawing Square\n";
    }
};

class ShapeFactory {
    public:
    static Shape* createShape(string type) {
        if (type == "circle") return new Circle();
        if (type == "square") return new Square();
        return nullptr;
    }
};

// 3. Strategy pattern
class Strategy {
    public:
    virtual void execute() = 0;
};

class AddStrategy : public Strategy {
    public:
    void execute() override {
        cout << "Addition Strategy\n";
    }
};

class MultiplyStrategy : public Strategy {
    public:
    void execute() override {
        cout << "Multiplication Strategy\n";
    }
};

class Context {
    private:
    Strategy* strategy;

    public:
    void setStrategy(Strategy* s) {
        strategy = s;
    }

    void run() {
        if (strategy)
        strategy->execute();
    }
};

// Main Function
int main() {
    cout << "===== Singleton Pattern =====\n";

    Singleton* s1 = Singleton::getInstance();
    s1->showMessage();

    Singleton* s2 = Singleton::getInstance();
    cout << "Same instance? " << (s1 == s2) << endl;

    cout << "\n===== Factory Pattern =====\n";

    Shape* shape1 = ShapeFactory::createShape("circle");
    Shape* shape2 = ShapeFactory::createShape("square");
    
    shape1->draw();
    shape2->draw();

    cout << "\n===== Strategy Pattern =====\n";
    
    Context context;

    AddStrategy add;
    MultiplyStrategy multiply;

    context.setStrategy(&add);
    context.run();

    context.setStrategy(&multiply);
    context.run();

    cout << "\n===== End =====\n";
    return 0;
}