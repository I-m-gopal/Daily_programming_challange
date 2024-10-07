//You are given an array arr containing n+1 integers, where each integer is in the range [1, n] inclusive. There is exactly one duplicate number in the array,
//but it may appear more than once. Your task is to find the duplicate number without modifying the array and using constant extra space.
//Approach: Floyd's tortoise and hare
#include<iostream>
#include<vector>
using namespace std;
int f_t_h(vector<int>arr){
    int slow = arr[0];
    int fast = arr[0];
    
    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }
    while(slow!=fast);
    
    slow = arr[0];
    while(slow!=fast){
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}


int main(){
    vector<int> arr = {3,1,3,4,2};
    cout<<"Duplicate number is: "<<f_t_h(arr);
    return 0;
}
