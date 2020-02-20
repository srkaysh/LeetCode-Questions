#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        if(!s.size()) return -1;
        unordered_map<char,int> charSeen;
            
        for(int i=0; i<s.size(); i++) charSeen[s[i]]++;
        
        for(int i=0; i<s.size(); i++){
            if(charSeen[s[i]] == 1) return i;
        }
        return -1;
    }
};
