#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Find
    auto it = std::find(numbers.begin(), numbers.end(), 5);
    if (it != numbers.end()) {
        std::cout << "Found 5 at index: " << std::distance(numbers.begin(), it) << std::endl;
    }

    // Binary Search
    bool found = std::binary_search(numbers.begin(), numbers.end(), 8);
    std::cout << "Number 8 " << (found ? "found" : "not found") << std::endl;

    // Lower Bound
    auto lb = std::lower_bound(numbers.begin(), numbers.end(), 6);
    std::cout << "Lower bound of 6 is at index: " << std::distance(numbers.begin(), lb) << std::endl;

    // Upper Bound
    auto ub = std::upper_bound(numbers.begin(), numbers.end(), 6);
    std::cout << "Upper bound of 6 is at index: " << std::distance(numbers.begin(), ub) << std::endl;

    // Next Permutation
    std::next_permutation(numbers.begin(), numbers.end());
    std::cout << "Next permutation: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Pair
    std::pair<int, std::string> myPair = std::make_pair(42, "Hello");
    std::cout << "Pair: " << myPair.first << ", " << myPair.second << std::endl;

    // Rotate
    std::rotate(numbers.begin(), numbers.begin() + 3, numbers.end());
    std::cout << "Rotated vector: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Reverse
    std::reverse(numbers.begin(), numbers.end());
    std::cout << "Reversed vector: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    //now implement of of these functions on array and string , as they do have a,a+n and str.begin(),str.end() functions
    return 0;
}
