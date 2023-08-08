/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    int rnode(ListNode* node, int n){
        if(node == nullptr)
            return 0;
        int num = rnode(node->next, n);
        if(num == n){
           node->next = node->next->next; 
        }
        return num+1;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       int num = rnode(head, n);
       if(num == n)
            head = head->next;
       return head;
    }
};
// @lc code=end

