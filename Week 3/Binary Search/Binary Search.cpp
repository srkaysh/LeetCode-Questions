#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        size_t n = nums.size();
        if(n == 1 && nums[0] != target) return -1;
        else if(target < nums[0] || target > nums[n-1]) return -1;
        else if(target == nums[0]) return 0;
        else if(target == nums[n-1]) return n-1;
        
        size_t l=0, r=n, mid;
        
        while(l<(r-1)){
            mid = (l+r)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) r = mid;
            else l = mid;
        }
        
        return -1;
    }
};
