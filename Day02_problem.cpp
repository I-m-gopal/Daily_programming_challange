//You are given an array arr containing n-1 distinct integers. The array consists of integers taken from the range 1 to n, meaning one integer is missing from this sequence. Your task is to find the missing integer.

#include<iostream>
#include<vector>
using namespace std;
int ismissing(vector<int>arr){
    int size = arr.size();
    //Calculate the total sum of elements of arrat
    int sum=0;
    for(int i=0;i<size;i++) sum+=arr[i];
    
    //Calculate sum of n natural number
    int no_element = size+1;
    int n_sum = (no_element*(no_element+1))/2;
    
    return n_sum-sum;
}

int main(){
    vector<int> arr= {1,3,4,5,6,7};
    cout<<"Missing number is: "<<ismissing(arr);
    return 0;
}
