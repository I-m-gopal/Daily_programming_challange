//Fibonacci Sequence using Dynamic Programming
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

long double fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    vector<long double> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "The " << n << "-th Fibonacci number is: " 
         << scientific << setprecision(15) << fibonacci(n) << endl;

    return 0;
}
