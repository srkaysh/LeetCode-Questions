#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> indexmap;
        unordered_map<int,int>::iterator it;
        int val;

        for(auto i=0; ; i++){
            val = nums[i];
            it = indexmap.find(val);
            if(it != indexmap.end())
                return {it->second,i};
            indexmap[target - val] = i;
        }
        
        return {};
    }
};
