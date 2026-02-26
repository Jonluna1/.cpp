#include <iostream>
using namespace std;

int main() {
    int data[] = {1, 3, 6, 3, 9, 3, 5, 7, 2, 11};
    int size = sizeof(data) / sizeof(data[0]);

    int maxHugs = data[0];
    int floor = 0;

    for (int i = 1; i < size; i++) {
        if (data[i] > maxHugs) {
            maxHugs = data[i];
            floor = i;
        }
    }

    cout << "Most hugs available on floor: " << floor + 1 << endl;
    cout << "Number of hugs: " << maxHugs << endl;

    return 0;
}