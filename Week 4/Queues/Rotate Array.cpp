#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if(size == 0) return;
        queue<int> elements;
        
        for(int i = 0; i < size+k; i++) {
            if(i < nums.size()) elements.push(nums[i]);
            if(i >= k) {
                nums[i%size] = elements.front();
                elements.pop();
            }
        }
    }
};
