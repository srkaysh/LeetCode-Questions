#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        int i, size=s.size();
        for(i=0; i<(size/2); i++){
            temp = s[i];
            s[i] = s[size-i-1];
            s[size-i-1] = temp;
        }
    }
};
