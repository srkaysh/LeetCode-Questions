#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int i, c[26]={0};

        for(i=0; i<s.size(); i++) c[s[i]-'a']++;
        for(i=0; i<t.size(); i++){
            c[t[i]-'a']--;
            if(c[t[i]-'a']<0) return false;
        }

        return true;
    }
};
