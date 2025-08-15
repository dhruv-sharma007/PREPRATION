#include <iostream>
#include <unordered_map>

int main(int argc, char const *argv[])
{
    std::unordered_map<int, std::string> myMap;
    myMap[1] = "Yamdoot";
    myMap[2] = "World";
    myMap.insert({3, "Yamdoot World"});

    std::cout << myMap[1];

    myMap.erase(2);
    return 0;
}
