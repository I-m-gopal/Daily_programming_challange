//Trapping Rain water

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trap(const vector<int>& height) {
    if (height.empty()) return 0;
    
    int n = height.size();
    if (n < 3) return 0;
    
    int left = 0, right = n - 1;
    int left_max = height[left], right_max = height[right];
    int water_trapped = 0;
    
    while (left <= right) {
        if (height[left] <= height[right]) {
            if (height[left] >= left_max) {
                left_max = height[left];
            } else {
                water_trapped += left_max - height[left];
            }
            left++;
        } else {
            if (height[right] >= right_max) {
                right_max = height[right];
            } else {
                water_trapped += right_max - height[right];
            }
            right--;
        }
    }
    
    return water_trapped;
}

int main() {
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Water trapped: " << trap(height1) ;

    return 0;
}
