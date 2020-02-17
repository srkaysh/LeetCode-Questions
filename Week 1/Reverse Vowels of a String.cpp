#include <string>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        char c;
        int i=0, j=s.size()-1;

        while(i<j){
            while((s[i] != 'a') && (s[i] != 'A') &&
                  (s[i] != 'e') && (s[i] != 'E') &&
                  (s[i] != 'i') && (s[i] != 'I') &&
                  (s[i] != 'o') && (s[i] != 'O') &&
                  (s[i] != 'u') && (s[i] != 'U') && i<s.size()) i++;
            if(i==s.size()) return s;
            while((s[j] != 'a') && (s[j] != 'A') &&
                  (s[j] != 'e') && (s[j] != 'E') &&
                  (s[j] != 'i') && (s[j] != 'I') &&
                  (s[j] != 'o') && (s[j] != 'O') &&
                  (s[j] != 'u') && (s[j] != 'U')) j--;
            if(i<j){
                c=s[i];
                s[i]=s[j];
                s[j]=c;
            }
            i++; j--;
        }

        return s;
    }
};
