#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>

std::string wordToKey(std::string word) {
    std::set<char> letterSet;
    for(const auto e:word) letterSet.insert(e);
    std::string result;
    for(const auto e:letterSet) result += e;
    return result;
}

int main() {
    std::vector<std::string> strs {"eat","tea","tan","ate","nat","bat"};
    std::map<std::string,std::vector<std::string>> groups;

    for (const auto str : strs) groups[wordToKey(str)].push_back(str);

    std::cout << "{ ";
    for (const auto pair : groups) {
        std::cout << "{";
        for (const auto e : pair.second) {
            std::cout << e.data();
            if (e != pair.second.back()) std::cout << ", ";
        }
        std::cout << "} "; 
    }
    std::cout << "}\n";
}