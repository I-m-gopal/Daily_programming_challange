//Longest Common Prfix

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<string> str1 = {"string","wop"};
    
    sort(str1.begin(),str1.end());
    vector<char> arr1,arr2;
    for(char i : str1[0]){
        arr1.push_back(i);
    }
    for(char i:str1[str1.size()-1]){
        arr2.push_back(i);
    };
    vector<char> result;
    for(int i=0;i<arr1.size();i++){
        if(arr1[i]!=arr2[i]) break;
        else result.push_back(arr1[i]);
    }
    for(char i:result) cout<<i;
    return 0;
}
