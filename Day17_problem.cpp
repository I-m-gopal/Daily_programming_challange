//Prime factor of a number
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> prime_factors(int N) {
    vector<int> factors;
    while (N % 2 == 0) {
        factors.push_back(2);
        N /= 2;
    }
    for (int i = 3; i <= sqrt(N); i += 2) {
        while (N % i == 0) {
            factors.push_back(i);
            N /= i;
        }
    }
    if (N > 2) {
        factors.push_back(N);
    }
    return factors;
}

int main() {
    int n;
    cin >> n;
    vector<int> result = prime_factors(n);
    for (int factor : result) {
        cout << factor << " ";
    }
    cout << endl;
    return 0;
}
