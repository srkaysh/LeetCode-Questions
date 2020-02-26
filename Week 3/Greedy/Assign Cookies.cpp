#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        size_t nContent=0, g_i=0, s_i=0;
        
        while(g_i < g.size() && s_i < s.size()){
            if(g[g_i] <= s[s_i]){
                nContent++;
                g_i++;
            }
            s_i++;
        }
        
        return nContent;
    }
};
