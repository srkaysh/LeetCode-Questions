#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        ssize_t buy=prices[0], sell=prices[0];

        for(ssize_t i=1; i<prices.size(); i++){
            if(prices[i] > sell) sell = prices[i];
        }
        prices.erase(prices.begin());

        return max(int(sell-buy), maxProfit(prices));
    }
};
