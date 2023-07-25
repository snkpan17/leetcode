#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() == 0 || t.size() > s.size())
            return "";
        int minlen = INT_MAX;
        string smin;
        // t can have a number of duplicate characters 
        unordered_map<char, int> map;
        for(auto ch: t){
            map[ch]++;
        }
        // No of unique characters in t
        int nUnique = map.size();
        int i = 0, j = -1;
        int size = s.size();
        while(j < size){
            ++j;
            if(map.find(s[j]) == map.end()){
                continue;
            }
            map[s[j]]--;
            if(map[s[j]] == 0)
                --nUnique;
            if(nUnique == 0){
                // Valid window having all required no of unique characters
                if(j-i+1 < minlen){
                    minlen = j-i+1;
                    smin = s.substr(i, minlen);
                }

                // Decrease window till possible to maintain invariant
                // If element at start is not in map -> not required unique character
                // While map[s[i]] is not > 0 -> I can remove this 
                // i < j always true
                while(map.find(s[i]) == map.end() || map[s[i]] < 0){
                    if(map.find(s[i]) != map.end()) 
                        map[s[i]]++;
                    ++i;
                    if(j-i+1 < minlen){
                        minlen = j-i+1;
                        smin = s.substr(i, minlen);
                    }
                }

                //Removal of first element in window will fail the invariant
                if(i < j){
                    map[s[i]]++;
                    ++i;
                    ++nUnique;
                } 
            }
        } 
        return smin;
    }
};
// @lc code=end

int main(){
    Solution sol = Solution();
    string s, t;
    cin>>s>>t;
    string str = sol.minWindow(s, t);
    cout<<str<<endl;
    // cout<<s.minWindow("a", "a")<<endl;
    // cout<<s.minWindow("a", "aa")<<endl;
}

