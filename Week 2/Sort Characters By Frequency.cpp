#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        vector<string> freqStr(s.size(),"");
        string result;
        
        for(const char ch: s)
            freq[ch]++;
        for(const auto &it: freq)
            freqStr[(it.second)-1].append(it.second, it.first);
        for(int i=freqStr.size()-1; i>=0; i--)
            if(!freqStr[i].empty()) result.append(freqStr[i]);
        
        return result;
    }
};
