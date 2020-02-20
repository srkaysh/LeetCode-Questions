#include<cmath>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if(n == 1) return true;
        else if(n == 0) return false;
        unordered_set<int> doesExist;
        int temp=0;
        
        while(!doesExist.count(n)){
            doesExist.insert(n);
            while(n){
                temp += pow((n%10),2);
                n /= 10;
            }
            if(temp == 1) return true;
            n = temp;
            temp = 0;
        }
        
        return false;
    }
};
