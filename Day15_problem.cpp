//Find the Longest Substring Without Repeating Characters
#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;

    int n = s.length();
    int start = 0;
    int maxLength = 0;
    unordered_set<char> charSet;

    for (int end = 0; end < n; ++end) {
        while (charSet.find(s[end]) != charSet.end()) {
            charSet.erase(s[start]);
            start++;
        }

        charSet.insert(s[end]);
        maxLength = std::max(maxLength, end - start + 1);
    }

    cout << maxLength << endl;

    return 0;
}
