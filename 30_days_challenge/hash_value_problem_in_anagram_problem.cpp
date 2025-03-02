#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <functional> // For std::hash

// Custom Hash Function for std::map<char, int>
struct MapHash
{
    size_t operator()(const std::map<char, int> &m) const
    {
        size_t hashValue = 0;
        std::hash<char> charHasher;
        std::hash<int> intHasher;

        for (const auto &pair : m)
        {
            hashValue ^= (charHasher(pair.first) ^ intHasher(pair.second));
        }
        return hashValue;
    }
};

// Custom Equality Function (Optional)
struct MapEqual
{
    bool operator()(const std::map<char, int> &a, const std::map<char, int> &b) const
    {
        return a == b; // Directly compare maps
    }
};

int main()
{
    std::unordered_map<std::map<char, int>, std::vector<std::string>, MapHash, MapEqual> ump;

    std::map<char, int> key1 = {{'a', 1}, {'b', 2}};
    std::vector<std::string> value1 = {"apple", "banana"};

    std::map<char, int> key2 = {{'x', 3}, {'y', 4}};
    std::vector<std::string> value2 = {"xray", "yellow"};

    ump[key1] = value1;
    ump[key2] = value2;

    for (const auto &[key, value] : ump)
    {
        std::cout << "Key: { ";
        for (const auto &[ch, num] : key)
        {
            std::cout << ch << ":" << num << " ";
        }
        std::cout << "} -> Values: ";
        for (const auto &str : value)
        {
            std::cout << str << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
