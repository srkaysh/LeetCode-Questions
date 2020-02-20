#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban_words(banned.begin(), banned.end());
        unordered_map<string,int> words;
        string token;
        
        for(auto &ch: paragraph) ch = isalpha(ch)? tolower(ch): ' ';
        stringstream par_stream(paragraph);
        while(getline(par_stream, token, ' ')){
            if(!token.empty() && !ban_words.count(token)) words[token]++;
        }
        if(words.size() == 1) return words.begin()->first;
        auto it = max_element(words.begin(), words.end(), [](pair<string,int> p1, pair<string,int> p2){
                                                                return p1.second < p2.second;
                                                            });
        return it->first;
    }
};
