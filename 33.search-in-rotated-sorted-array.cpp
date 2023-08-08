#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int midx = 0;
        if(l == r){
            if(target == nums[l])
                return l;
            return -1;
        }
        if(nums[l] > nums[r]){
            while(l < r){
                int mid = l + (r-l)/2;
                if(l == mid)
                    break;
                if(nums[mid] > nums[l])
                    l = mid;
                if(nums[mid] < nums[r])
                    r = mid;
            }
            midx = r;
            if(target > nums[midx-1] || target < nums[midx])
                return -1;
        }
        int bi = 0, ei = nums.size();
        if(target <= nums[nums.size()-1]){
            bi = midx;
        }
        else {
           ei = midx; 
        }

        auto itr = lower_bound(nums.begin()+bi, nums.begin()+ei, target);
        if(itr == nums.begin()+ei || *itr != target)
            return -1;
        return itr-nums.begin();

    }
};
// @lc code=end

int main(){
    Solution sol = Solution();
    // vector<int> nums = {4, 5, 6, 7, 0, 1, 3};
    // int target = 0;
    vector<int> nums = {1, 3};
    int target = 3;
    cout<<sol.search(nums, target);
}

