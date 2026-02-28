#include <iostream>
#include <algorithm>

void findMatches(const int arr1[], size_t size1, const int arr2[], size_t size2) {

    std::cout << "\nMatching values: ";

    for (size_t i = 0; i < size1; ++i) {
        for (size_t j = 0; j < size2; ++j) {
            if (arr1[1] == arr2[j]) {
                std::cout << arr1[i] << " ";
                break;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    int data[] {1, 3, 6, 7, 9};
    int data1[] {5, 3, 3, 11};

    size_t minSize = std::min(std::size(data), std::size(data1));

    for (size_t i = 0; i < minSize; ++i) {
        int temp = data[i];
        data[i] = data1[i];
        data1[i] = temp;
    }

    std::cout << "After swapping:\n";

    std::cout << "data:  ";
    for (int x : data) std::cout << x << " ";
    std::cout << std::endl;

    std::cout << "data1: ";
    for (int x : data1) std::cout << x << " ";
    std::cout << std::endl;

    findMatches(data, std::size(data), data1, std::size(data1));

    return 0;
}