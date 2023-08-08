#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        if(nums[l] < nums[r] || l == r){
            return nums[l];
        }
        while(l < r){
            int mid = l + (r-l)/2;
            if(l == mid)
                break;
            if(nums[mid] > nums[l])
                l = mid;
            if(nums[mid] < nums[r])
                r = mid;
        }
        return nums[r];
    }
};
// @lc code=end

