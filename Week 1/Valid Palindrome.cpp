#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while((i-j) < 1){
            while(((s[i] < 48) || ((s[i] > 57) && (s[i] < 65)) || ((s[i] > 90) && (s[i] < 97)) || (s[i] > 122)) && (i-j))
                i++;
            while(((s[j] < 48) || ((s[j] > 57) && (s[j] < 65)) || ((s[j] > 90) && (s[j] < 97)) || (s[j] > 122)) && (i-j))
                j--;
            if((s[i] - s[j]) && ((abs(s[i] - s[j]) != 32) || (((s[i] - 'a') < 0) && ((s[j] - 'a') < 0)))) return false;
            i++; j--;
        }
        return true;
    }
};
