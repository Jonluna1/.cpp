#include <iostream>
#include <bitset>
#include <string>

using namespace std;

// Function to convert text to binary
void textToBinary(const string& text)
{
    cout << "Binary output: ";

    for (char c : text)
    {
        bitset<8> binary(c);
        cout << binary << " ";
    }

    cout << endl;
}

int main()
{
    string input;

    cout << "Eneter a word or sentence: ";
    getline(cin, input);  // allows space

    textToBinary(input);

    return 0;
}