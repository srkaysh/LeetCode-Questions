#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        else if(n == 1) return x;
        else if(n == -1) return double(1/x);
        
        double half_pow = myPow(x, n/2);
        if(!(n%2)) return half_pow * half_pow;
        else if(n>0) return half_pow * half_pow * x;
        else return half_pow * double(half_pow / x);
    }
};
