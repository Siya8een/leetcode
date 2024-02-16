#include <string>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mpp;
        for (int i=0; i< s.size(); i++)
        {
            mpp[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        string ans="";
         while(!pq.empty()){
             auto it = pq.top();
             pq.pop();
             int x=it.first;
             char ch=it.second;
             
             for(int i=0;i<x;i++){
                 ans.push_back(ch);
             }
         }
         return ans;
    }
};
