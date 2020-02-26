#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        size_t i=0;

        while(i < s.size()){
            if(s[i] != t[i]) return false;
            i++;
        }

        return true;
    }
};
