#include <map>
#include <iostream>

int main() {
    std::multimap<int, std::string> myMap = {{1, "one"}, {2, "two"}, {3, "three"}};

    // Get a reverse iterator to the end of the map
    auto it = myMap.rbegin();

    // Move the iterator backwards by 2 positions
    std::advance(it, 2);

    // Print the value of the element at the new iterator position
    std::cout << it->second << std::endl; // Output: "one"

    return 0;
}