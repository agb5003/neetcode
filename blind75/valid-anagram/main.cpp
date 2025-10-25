#include <iostream>
#include <unordered_map>
#include <string>

// Construct a dictionary mapping letters as the key and the number of occurrence as the value. If the two dictionaries for the strings match each other they are anagrams.

bool isAnagram(std::string s, std::string t)
{
    if (s.size() != t.size()) return false;
    
    std::unordered_map<char, int> sMap;
    std::unordered_map<char, int> tMap;

    for (auto& c : s) sMap[c]++;
    for (auto& c : t) tMap[c]++;

    if (sMap.size() != tMap.size()) return false;

    for (auto& k : sMap)
    {
        if (k.second != tMap[k.first]) return false;
    }
    return true;

    // return (sMap == tMap); // Available for C++20 and newer
}

int main()
{
    std::string s1 = "hello";
    std::string s2 = "elloh";
    std::string s3 = "henlo";

    std::cout << isAnagram(s1, s2) << ", " << isAnagram(s2, s3);
}