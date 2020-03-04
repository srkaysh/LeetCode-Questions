#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<char> paren;
        stack<int> score;
        int val;
        
        for(const char ch: S){
            if(ch == '('){
                paren.push(ch);
                score.push(0);
            }
            else{
                val = 0;
                while(score.top() != 0){
                    val += score.top();
                    score.pop();
                }
                score.pop();
                if(val == 0) score.push(1);
                else score.push(2*val);
                paren.pop();
            }
        }
        
        val = 0;
        while(!score.empty()){
            val += score.top();
            score.pop();
        }
        
        return val;
    }
};
