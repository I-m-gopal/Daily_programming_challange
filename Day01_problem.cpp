// sort the array contain 0 1 2. Time complexity must be O(n) and space complexity mus be O(1)
// Approach Dutch National Flag Algorithm 

//Solution --
#include<iostream>
#include<vector>
using namespace std;
void dutch_flag_algo(vector<int>& arr){
    int low=0,mid=0;
    int high = arr.size()-1;
    while(mid<=high){
        if(arr[mid]==0){
            int temp = arr[mid];
            arr[mid] = arr[low];
            arr[low] = temp;
            low++;
            mid++;
        }
        else if(arr[mid]==2){
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
        else{
            mid++;
        }
    }
}

int main(){
    vector<int> arr = {0, 1, 2, 1, 0, 2, 1, 0};
    if(arr.empty()) cout<<"Array is empty";
    dutch_flag_algo(arr);
    for(int i:arr){
        cout<<i;
    }
  return 0;
}
