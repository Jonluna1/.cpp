#include <iostream>
using namespace std;

//Base Class (Pokemon)
class Pokemon {
    protected: 
    int level;

    public:
    Pokemon(int lvl) : level(lvl) {}

    // Polymorphism
    virtual void attack() const = 0;
    virtual void defend() const = 0;
    virtual void evolve() = 0;
    virtual void speak() const = 0;

    virtual ~Pokemon() {}
};

// Intermediate Class (Class Type)
class ElectricPokemon : public Pokemon {
    public:
    ElectricPokemon(int lvl) : Pokemon(lvl) {}

    void displayType() const {
        cout << "Type: Electric" << endl;
    }
};

// Derived Class (Specific Pokemon)
class Pikachu : public ElectricPokemon {
    public:
    Pikachu(int lvl) : ElectricPokemon(lvl) {}

    void attack() const override {
        cout << "Pikachu uses Thunderbolt!" << endl;
    }

    void defend() const override {
        cout << "Pikachu dodges quickly!" << endl;
    }

    void evolve() override {
        cout << "Pikachu evolves into Raichu!" << endl;
    }

    void speak() const override {
        cout << "Pika Pika!" << endl;
    }
};

// Another Type Class
class FirePokemon : public Pokemon {
    public:
    FirePokemon(int lvl) : Pokemon(lvl) {}

    void displayType() const {
        cout << "Type: Fire" << endl;
    }
};

// Another Derived Pokemon
class Charmander : public FirePokemon {
    public:
    Charmander(int lvl) : FirePokemon(lvl) {}

    void attack() const override{
        cout << "Charmander uses Flamethrower!" << endl;
    }

    void defend() const override {
        cout << "Charmander shields with fire!" << endl;
    }

    void evolve() override {
        cout << "Charmander evolves into Charmeleon!" << endl;
    }

    void speak() const override {
        cout << "Char Char!" << endl;
    }
};

// Main Function
int main() {
    // Pikachu
    Pikachu pikachu(10);
    pikachu.displayType();
    pikachu.attack();
    pikachu.defend();
    pikachu.evolve();
    pikachu.speak();

    cout << endl;

    // Charmander
    Charmander charmander(8);
    charmander.displayType();
    charmander.attack();
    charmander.defend();
    charmander.evolve();
    charmander.speak();

    return 0;
}