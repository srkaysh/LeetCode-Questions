#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> domainCount;
        auto it = cpdomains.begin();
        size_t i=0, count=0;
        vector<string> result;

        while(it != cpdomains.end()){
            i = (*it).find(' ');
            count = stoi((*it).substr(0,i));
            do{
                domainCount[(*it).substr(i+1)] += count;
                i = (*it).find('.',i+1);
            }while(i != string::npos);
            it++;
        }

        for(auto it = domainCount.begin(); it != domainCount.end(); it++){
            result.push_back(to_string(it->second) + " " + it->first);
        }

        return result;
    }
};
