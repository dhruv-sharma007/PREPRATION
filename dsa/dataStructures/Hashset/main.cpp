#include <iostream>
#include <unordered_set>
#include <string>

int main()
{
    // Implmentation of HashSet 

    // HashSet stores unique values
    std::unordered_set<int> myHashSet;

    // Adding Elements in hashSet
    myHashSet.insert(10);
    myHashSet.insert(10); // Ignored
    myHashSet.insert(30);

    myHashSet.erase(30); //Removing an element
    myHashSet.size(); // Returns the size of hashSet
    myHashSet.count(30);
}