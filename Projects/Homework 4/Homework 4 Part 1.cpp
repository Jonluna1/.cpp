#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Global map boundaries
int xMin, xMax, yMin, yMax;

// Function to create random sized map
void createMap()
{
    int width = (rand() % 11) + 10;   // Random 10-20
    int height = (rand() % 11) + 10;   // Random 10-20

    xMin = -width / 2;
    xMax = width / 2;
    yMin = -height / 2;
    yMax = height / 2;

    cout << "Map Created!\n";
    cout << "Width: " << width << " Height: " << height << endl;
    cout << "Boundaries: (" << xMin << "," << yMin << ") to (" << xMax << "," << yMax << ")\n";
}

// Function to check if location is valid
bool isLocationValid(int x, int y)
{
    if (x >= xMin && x <= xMax && y >= yMin && y <= yMax)
    return true;
    else
    return false;
}

int main()
{
    srand(time(0)); // Seed random generator

    string name;
    int x, y;

    createMap();

    cout << "\nEnter your name: ";
    getline(cin, name);

    cout << "Enter your location (x y): ";
    cin >> x >> y;

    if (isLocationValid(x, y))
    cout << "\nWelcome " << name << "! You are inside the map!\n";
    else
    cout << "\nSorry " << name << ", you are outside the map!\n";

    return 0;
}