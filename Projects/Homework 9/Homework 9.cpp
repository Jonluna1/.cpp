#include <iostream>
#include <stdexcept>
using namespace std;

// Custom Expection Class
class CustomException : public exception {
    public:
    const char* what() const noexcept override {
        return "Error in nestedFunction";
    }
};

// Divisionn Function
double divide(int numerator, int denominator) {
    if (denominator == 0) {
        throw runtime_error("Division by zero is not allowed.");
    }
    return static_cast<double>(numerator) / denominator;
}

// Array Access Function
int accessArray(int arr[], int size, int index){
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of bounds.");
    }
    return arr[index];
}

// Nested Exception Function
void nestedFunction() {
    throw CustomException();
}

// Outer Function
void outerFunction() {
    try {
        nestedFunction();
    }
    catch (const exception& e) {
        cout << "Caught exception in outerFunction: " << e.what() << endl;
        throw; // rethrow the same exception
    }
}

int main() {
    // Nested Exception Demo
    try {
        outerFunction();
    }
    catch (const exception& e) {
        cout << "Caught rethrown exception in main: " << e.what() << endl;
    }

    // Division Demo
    int num, denom;
    cout << "\nEnter numerator: ";
    cin >> num;
    cout << "Enter denominator: ";
    cin >> denom;

    try {
        double result = divide(num, denom);
        cout << "Result: " << result << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Array Access Demo
    int size;
    cout << "\nEnter array size: ";
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }

    int index;
    cout << "Enter index to access: ";
    cin >> index;

    try {
        int value = accessArray(arr, size, index);
        cout << "Value at index " << index << ": " << value << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    delete[] arr;
    return 0;
}