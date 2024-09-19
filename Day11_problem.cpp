//Permutation of a string
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<string> uniquePermutations(string s) {
    sort(s.begin(), s.end());
    set<string> unique_perms;
    
    do {
        unique_perms.insert(s);
    } while (next_permutation(s.begin(), s.end()));
    
    vector<string> result(unique_perms.begin(), unique_perms.end());
    
    return result;
}

int main() {
    string s;
    cin >> s;
    
    vector<string> permutations = uniquePermutations(s);
    
    for (const string& perm : permutations) {
        cout << perm << endl;
    }

    return 0;
}
