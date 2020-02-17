using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<1) return false;
        while(!(n%2)) n >>= 1;
        if(n == 1) return true;
        else return false;
    }
};
