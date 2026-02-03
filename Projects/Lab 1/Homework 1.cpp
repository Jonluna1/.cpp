#include <iostream>
#include <bitset>
#include <cstring>   // for memcpy

using namespace std;

// Function to convert char to binary (ASCII)
void charToBinary(char c)
{
    bitset<8> binary(c);
    cout << "Character '" << c << "' in binary (ASCII): " << binary << endl;
}

// Function to convert int to binary
void inToBinary(int num)
{
    bitset<32> binary(num);
    cout << "Integer " << num << " in binary: " << binary << endl;
}

// Function to convert float to binary (IEEE 754)
void floatToBinary(float num)
{
    int bits;
    memcpy(&bits, &num, sizeof(float));
    bitset<32> binary(bits);
    cout << "Float " << num << " in binary (IEEE 754): " << binary << endl;
}

int main()
{
    char ch;
    int integer;
    float decimal;

    cout << "Enter a character: ";
    cin >> ch;

    cout << "Enter an integer: ";
    cin >> integer;

    cout << "Enter a float: ";
    cin >> decimal;

    cout << endl;

    charToBinary(ch);
    inToBinary(integer);
    floatToBinary(decimal);

    return 0;
}
