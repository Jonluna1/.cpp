#include <iostream>
#include <cmath>

using namespace std;

// Compile-time constant (constexpr)
constexpr double PI = 3.141592653589793;

int main()
{
    int choice;

    cout << "Calculate the area of:\n";
    cout << "1. Square\n";
    cout << "2. Rectangle\n";
    cout << "3. Circle\n";
    cout << "4. Cylinder\n";
    cout << "Please enter your choice (1-4): ";
    cin >> choice;

    if (choice == 1)
    {
        double side;
        cout << "Enter side length: ";
        cin >> side;

        double area = side * side;
        cout << "Total area: " << area << endl;
    }
    else if (choice == 2)
    {
        double length, width;
        cout << "Enter length ";
        cin >> length;
        cout << "Enter width: ";
        cin >> width;

        double area = length * width;
        cout << "Total area: " << area << endl;
    }
    else if (choice == 3)
    {
        double radius;
        cout << "Enter radius ";
        cin >> radius;

        double area = PI * radius * radius;
        cout << "Total area: " << area << endl;
    }
    else if (choice == 4)
    {
        double radius, height;
        cout << "Enter radius: ";
        cin >> radius;
        cout << "Enter height: ";
        cin >> height;

        // Surface area of a cylinder
        double area = (2 * PI * radius * radius) + (2 * PI * radius * height);
        cout << "Total area: " << area << endl;
    }
    else
    {
        cout << "Invalid choice." << endl;
    }

    return 0;
}