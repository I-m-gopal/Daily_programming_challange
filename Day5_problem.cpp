//You are given an integer array arr of size n. An element is considered a leader if it is greater than all the elements to its right. Your task is to find all such leader elements in the array.




#include<bits/stdc++.h>
using namespace std;
void leader_element(vector<int>&arr){
    vector<int> ans;
    int i = arr.size()-1;
    int heigh = -1;
    while(i>=0){
        if(arr[i]>heigh){
            ans.push_back(arr[i]);
            heigh = arr[i];
        }
        i--;
    }
    reverse(ans.begin(),ans.end());
    for(int i:ans) cout<<i<<" ";
}

int main(){
    // vector<int> arr={16,17,4,3,5,2};
    vector<int> arr={1,2,3,4,5};
    leader_element(arr);
    return 0;
}
