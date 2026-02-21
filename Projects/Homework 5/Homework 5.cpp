#include <iostream>
using namespace std;

int main()
{
    // Character array input
    char message[] = {
        'I',' ','l','i','k','e',' ','i','c','e','c','r','e','a','m'
    };

    int vowel_count = 0;

    // Calculate size of array
    int size = sizeof(message) / sizeof(message[0]);

    // Loop through each character
    for (int i = 0; i < size; i++)
    {
        switch (message[i])
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            vowel_count++;
            break;
        }
    }

    // Output result
    cout << "Number of vowels: " << vowel_count << endl;

    return 0;
}