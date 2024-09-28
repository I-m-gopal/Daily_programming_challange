//sort the stack using recursion
#include <iostream>
#include <stack>

using namespace std;

void insertSorted(stack<int>& s, int element) {
    if (s.empty() || s.top() <= element) {
        s.push(element);
        return;
    }
    
    int topElement = s.top();
    s.pop();
    insertSorted(s, element);
    s.push(topElement);
}

void sortStack(stack<int>& s) {
    if (s.empty()) {
        return;
    }
    
    int topElement = s.top();
    s.pop();
    
    sortStack(s);
    
    insertSorted(s, topElement);
}

void printStackInAscendingOrder(stack<int>& s) {
    if (s.empty()) {
        return;
    }
    
    int topElement = s.top();
    s.pop();
    
    printStackInAscendingOrder(s);
    
    cout << topElement << " ";
    
    s.push(topElement);
}

int main() {
    stack<int> s;

    s.push(3);
    s.push(1);
    s.push(4);
    s.push(2);

    sortStack(s);
    
    cout << "Sorted stack in ascending order: ";
    printStackInAscendingOrder(s);
    cout << endl;

    return 0;
}
