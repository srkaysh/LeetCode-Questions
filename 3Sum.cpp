#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {};
        int el1, i2, i3;
        int sum;
        vector<vector<int>> result;
        
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            el1 = nums[i];
            i2 = i+1; i3 = nums.size()-1;
            while(i2<i3){
                sum = nums[i2] + nums[i3];
                if(sum < -el1) i2++;
                else if(sum > -el1) i3--;
                else{
                    result.push_back(vector<int> {el1, nums[i2], nums[i3]});
                    i2++;
                    while(i2<i3 && nums[i2] == nums[i2-1]) i2++;
                }
            }
            while(i<nums.size()-2 && nums[i+1]==nums[i]) i++;
        }
        
        return result;
    }
};
