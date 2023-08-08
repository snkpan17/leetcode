# include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        if(x == 0)
            return true;
        string str = to_string(x);
        int i = 0, j = str.size()-1;
        while(i < j){
            if(str[i] == str[j]){
                i++; j--;
            }
            else return false;
        }
        return true;
    }
};
// @lc code=end

