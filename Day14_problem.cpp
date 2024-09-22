//Count substring with k distinct character


#include <iostream>
#include <unordered_map>
using namespace std;

int atMostKDistinct(string s, int k) {
    int n = s.length();
    unordered_map<char, int> charCount;
    int left = 0, right = 0, count = 0;
    while (right < n) {
        charCount[s[right]]++;
        while (charCount.size() > k) {
            charCount[s[left]]--;
            if (charCount[s[left]] == 0) {
                charCount.erase(s[left]);
            }
            left++;
        }

        count += right - left + 1;
        right++;
    }

    return count;
}

int substrCountWithKDistinct(string s, int k) {
    return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
}

int main() {
    string s;
    cin>>s;
    int k = 2;
    cout << "Output: " << substrCountWithKDistinct(s, k) << endl;
    return 0;
}
