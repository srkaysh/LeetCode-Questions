#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        if(!s.size()) return 0;
        int col_num=0;

        for(char c: s){
            col_num *= 26;
            col_num += (c-'A'+1);
        }

        return col_num;
    }
};
