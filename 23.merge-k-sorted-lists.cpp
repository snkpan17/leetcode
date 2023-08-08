#include<bits/stdc++.h>
using namespace std;

  struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>> pq;
        ListNode* head = nullptr;
        ListNode* prev = nullptr;
        for(auto node: lists){
            if(node)
            pq.push({-1*(node->val), node});
        }
        if(pq.empty())
            return head;
        while(pq.size() > 1){
            pair<int, ListNode*> p = pq.top();
            pq.pop();
            auto temp = p.second;
            if(temp->next)
                pq.push({-1*(temp->next->val), temp->next});
            if(!prev){
                head = prev = temp;
                continue;
            }
            prev->next = temp;
            prev = prev->next;
        }
        auto temp = pq.top().second;
        pq.pop();
        while(temp){
            if(!prev){
                head = prev = temp;
                temp = temp->next;
                continue;
            }
            prev->next = temp;
            temp = temp->next;
            prev = prev->next;
        } 
        return head;
    }
};
// @lc code=end

