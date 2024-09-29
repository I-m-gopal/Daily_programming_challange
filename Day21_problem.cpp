//Reverse a stack
#include <iostream>
#include <stack>
using namespace std;

void insert_at_bottom(stack<int>& stk, int item) {
    if (stk.empty()) {
        stk.push(item);
    } else {
        int temp = stk.top();
        stk.pop();
        insert_at_bottom(stk, item);
        stk.push(temp);
    }
}


void reverse_stack(stack<int>& stk) {
    if (!stk.empty()) {
        int temp = stk.top();
        stk.pop();
        reverse_stack(stk);
        insert_at_bottom(stk, temp);
    }
}


void print_stack(stack<int> stk) {
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

int main() {
    stack<int> stk;

    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);

    reverse_stack(stk);

    cout << "Reversed Stack: ";
    print_stack(stk); 

    return 0;
}
