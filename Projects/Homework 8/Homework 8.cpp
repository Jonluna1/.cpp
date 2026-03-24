#include <iostream>
#include <string>
using namespace std;

class Character {
    public:
    // 1. Basic attack (no parameters)
    void attack(){
        cout << "You attack the rock with a basic strike!" << endl;
    }

    // 2. Attack with damage value
    void attack(int damage) {
        cout << "You attack the rock and deal " << damage << " damage!" << endl;
    }

    // 3. Magical attack with spell name and damage
    void attack(string spell, int damage) {
        cout << "You cast " << spell << " and deal " << damage << " damage to the rock!" << endl;
    }
};

int main() {
    Character player;

    // Testing all overloaded functions
    player.attack();                  // Basic attack
    player.attack(50);                // Attack with damage
    player.attack("Fireball", 100);   // Magical attack

    return 0;
}