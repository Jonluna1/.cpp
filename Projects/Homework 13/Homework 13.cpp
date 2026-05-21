#include <iostream>
#include <map>

int main() {
    // Initialize the two maps
    std::map<int, int> numbers1{
        {1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7},{8,8},{9,9}
    };

    std::map<int, int> numbers2{
        {1,10},{2,20},{3,30},{4,40},{5,50},{6,60},{7,70},{8,80},{9,90}
    };

    // Interlace maps into a new map
    std::map<int, std::pair<int,int>> interlaced;

    // Iterator traversal
    auto it1 = numbers1.begin();
    auto it2 = numbers2.begin();

    while (it1 != numbers1.end() || it2 != numbers2.end()) {
        int key;

        if (it1 != numbers1.end()) {
            key = it1->first;
            interlaced[key].first = it1->second;
            ++it1;
        }

        if (it2 != numbers2.end()) {
            key = it2->first;
            interlaced[key].second = it2->second;
            ++it2;
        }
    }

    // Print result
    std::cout << "Interlaced map (numbers1): ";
    for (const auto& pair : interlaced) {
        std::cout << pair.first << ": " << pair.second.first << ", " << pair.second.second << " ";
    }
    std::cout << std::endl;

    return 0;
}