//You are given two sorted arrays arr1 of size m and arr2 of size n. Your task is to merge these two arrays into a single sorted array without using any extra space 
//(i.e., in-place merging). The elements in arr1 should be merged first, followed by the elements of arr2, resulting in both arrays being sorted after the merge.

//Solution 1 with sc O(min(n.m)+O(nlogn)+O(mlogm)
#include<bits/stdc++.h>
using namespace std;
void merge_the_sortarray(vector<int>&arr1,vector<int>&arr2){
    int n = arr1.size()-1;
    int m = arr1.size()-1;
    int left=n,right=0;
    while(left>=0 && right<m){
        if(arr1[left]>arr2[right]){
            swap(arr1[left],arr2[right]);
            left--;
            right++;
        }
        else{
            break;
        }
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    
    for(int i:arr1) cout<<i<<" ";
    cout<<endl;
    for(int j:arr2) cout<<j<<" ";
    
}



int main(){
    vector<int> arr1 = {1,3,5};
    vector<int> arr2 = {2,4,6};
    merge_the_sortarray(arr1,arr2);
    return 0;
}


//Solution 2 using gap method
#include<bits/stdc++.h>
using namespace std;
void merge_the_sortarray(vector<int>&arr1,vector<int>&arr2){
    int n = arr1.size();
    int m = arr2.size();
    int len1 = m+n;
    int gap = (len1/2)+(len1%2);
    //The gap should be grater than zero
    while(gap>0){
        int left = 0;
        int right = gap;
        while(right<len1){
            //arr1
            if(left<n && right<n){
                 if (arr2[left] > arr2[right]) {
                    swap(arr2[left], arr2[right]);
                }
            }
            //arr2
            else if(left >=n){
                if(arr2[left - n] > arr2[right - n]) {
                    swap(arr2[left - n], arr2[right - n]);
                }
            }
            //arr1 and arr2
            else{
                if (arr1[left] > arr2[right - n]) {
                    swap(arr1[left], arr2[right - n]);
                }
            }
            left++;
            right++;
        }
        if(gap==1) break;
        gap  = (gap/2)+(gap%2);
    }

    for(int i:arr1) cout<<i<<" ";
    cout<<endl;
    for(int j:arr2) cout<<j<<" ";
    
}



int main(){
    vector<int> arr1 = {1,3,5};
    vector<int> arr2 = {2,4,6};
    merge_the_sortarray(arr1,arr2);
    return 0;
}
