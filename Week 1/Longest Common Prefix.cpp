#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix="";
        if(!strs.size()) return prefix;
        char c;
        int j;

        for(int i=0; i < strs[0].size(); i++){
            c = strs[0][i];
            for(j=0;j<strs.size();j++){
                if((strs[j].size() < i) || (strs[j][i] != c)) return prefix;
            }
            prefix.push_back(c);
        }

        return prefix;
    }
};
