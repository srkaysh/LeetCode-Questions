#include <vector>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int max2, ind_max;
        if(nums[1] <= nums[0]){
            max2 = nums[1];
            ind_max = 0;
        } else {
            max2 = nums[0];
            ind_max = 1;
        } 
        
        for(int i=2; i<nums.size(); i++){
            if(nums[i] >= nums[ind_max]){
                max2 = nums[ind_max];
                ind_max = i;
            } else if(nums[i] > max2) max2 = nums[i];
        }
        
        if(nums[ind_max] >= 2*max2) return ind_max;
        else return -1;
    }
};
