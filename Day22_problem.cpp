//First Element to Repeat k Times
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int rl(vector<int>arr,int k){
    unordered_map<int,int> freq;
    for(int i:arr){
        freq[i]++;
    }
    
    for(int num:arr){
        if(freq[num]==k) return num;
    }
    return -1;
}

int main(){
    vector<int> arr= {10};
    int k = 1;
    int repeat_element = rl(arr,k);
    cout<<repeat_element;
    return 0;
}
