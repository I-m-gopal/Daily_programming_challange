//You are given an integer array arr of size n. Your task is to find all the subarrays whose elements sum up to zero. 
//A subarray is defined as a contiguous part of the array, and you must return the starting and ending indices of each subarray.
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<pair<int, int>> findZeroSumSubarrays(vector<int>& arr) {
    unordered_map<int, vector<int>> prefixSumMap; 
    vector<pair<int, int>> result;  
    int prefixSum = 0;
    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];
        if (prefixSum == 0) {
            result.push_back({0, i});
        }
        if (prefixSumMap.find(prefixSum) != prefixSumMap.end()) {
            vector<int> indices = prefixSumMap[prefixSum];
            for (int index : indices) {
                result.push_back({index + 1, i});
            }
        }
        prefixSumMap[prefixSum].push_back(i);
    }

    return result;
}


int main() {
    vector<int> arr = {1, 2, -3, 3, -1, 2};

    vector<pair<int, int>> subarrays = findZeroSumSubarrays(arr);

    if (subarrays.empty()) {
        cout << "No subarrays found that sum to zero." << endl;
    } else {
        for (auto& p : subarrays) {
            cout << "(" << p.first << ", " << p.second << ")" << endl;
        }
    }

    return 0;
}

