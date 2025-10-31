#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{

    // #########################--- for descending ordered data ---
    std::vector<int> vec = {9, 7, 5, 4, 4, 2, 1}; // sorted in descending order

    // Use greater<int>() to indicate descending order
    auto lb = std::lower_bound(vec.begin(), vec.end(), 4, std::greater<int>());
    auto ub = std::upper_bound(vec.begin(), vec.end(), 4, std::greater<int>());

    std::cout << "Lower bound of 4 is at index: " << (lb - vec.begin()) << "\n";
    std::cout << "Upper bound of 4 is at index: " << (ub - vec.begin()) << "\n";

    return 0;
}
