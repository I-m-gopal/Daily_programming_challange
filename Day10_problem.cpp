//Group Anagrams
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagram_map;
    
    for (string s : strs) {
        string sorted_s = s;
        sort(sorted_s.begin(), sorted_s.end());
        anagram_map[sorted_s].push_back(s);
    }
    
    vector<vector<string>> result;
    for (auto& entry : anagram_map) {
        result.push_back(entry.second);
    }
    
    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> grouped_anagrams = groupAnagrams(strs);
    for (auto group : grouped_anagrams) {
        cout << "[";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}
