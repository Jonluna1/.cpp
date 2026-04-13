#include <iostream>
#include <string>
using namespace std;

//Base Class (Pokemon)
class Pokemon {
    protected: 
    string name;
    int level;

    public:
    Pokemon(string n, int lvl) : name(n), level(lvl) {}

    // Polymorphism
    virtual void attack() const = 0;
    virtual void defend() const = 0;
    virtual void evolve() = 0;

    void display() const {
        cout << "Name: " << name << ", Level: " << level << endl;
    }

    virtual ~Pokemon() {}
};

// Type Class (Electric)
class ElectricPokemon : public Pokemon {
    public:
    ElectricPokemon(string n, int lvl) : Pokemon(n, lvl) {}

    void displayType() const {
        cout << "Type: Electric" << endl;
    }
};

// Type Class (Fire)
class FirePokemon : public Pokemon {
    public:
    FirePokemon(string n, int lvl) : Pokemon(n, lvl) {}

    void displayType() const {
        cout << "Type: Fire" << endl;
    }
};

// Pikachu
class Pikachu : public ElectricPokemon {
    public:
    Pikachu(int lvl) : ElectricPokemon("Pikachu", lvl) {}

    void attack() const override {
        cout << name << " uses Thunderbolt!" << endl;
    }

    void defend() const override {
        cout << name << " dodges quickly!" << endl;
    }

    void evolve() override {
        cout << name << " evolves into Raichu!" << endl;
    }
};

// Charmander
class Charmander : public FirePokemon {
    public:
    Charmander(int lvl) : FirePokemon("Charmander", lvl) {}

    void attack() const override{
        cout << name << " uses Flamethrower!" << endl;
    }

    void defend() const override {
        cout << name << " shields with fire!" << endl;
    }

    void evolve() override {
        cout << name << " evolves into Charmeleon!" << endl;
    }
};

// Main Function
int main() {
    // Pikachu
    Pikachu pikachu(10);
    Charmander charmander(8);
    
    // Polymorphism
    Pokemon* pokemons[] = { &pikachu, &charmander };
    
    for (Pokemon* p : pokemons) {
        p->display();
        p->attack();
        p->defend();
        p->evolve();
        cout << endl;
    }

    return 0;
}