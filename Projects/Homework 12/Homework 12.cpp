#include <iostream>
#include <vector>

int main() {
    // Initialize the two vectors
    std::vector<int> numbers1 = {1,2,3,4,5,6,7,8,9};
    std::vector<int> numbers2 = {10,20,30,40,50,60,70,80,90};

    // Resize numbers1 to hold interlaced result
    numbers1.resize(numbers1.size() + numbers2.size());

    // Iterators
    std::vector<int>::iterator it1 = numbers1.begin();
    std::vector<int>::iterator it2 = numbers2.begin();

    // Temporary vector to build result
    std::vector<int> result;

    // Interlace using iterators
    while (it1 != numbers1.begin() + numbers1.size()/2 || it2 != numbers2.end()) {
        if (it1 != numbers1.begin() + numbers1.size()/2) {
            result.insert(result.end(), *it1);
            ++it1;
        }
        if (it2 != numbers1.end()) {
            result.insert(result.end(), *it2);
            ++it2;
        }
    }

    // Copy result back into numbers1
    numbers1 = result;

    // Print the interlaced vector
    std::cout << "Interlaced vector (numbers1): ";
    for (int num : numbers1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}