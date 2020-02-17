#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        bool carry = true;
        while(carry && (i>=0)){
            digits[i] = (digits[i] + 1)%10;
            if(digits[i--] != 0) carry = false;
        }
        if(i == -1 && carry) digits.insert(digits.begin(),1);
        return digits;
    }
};
