#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder {
    int no;
    priority_queue<int, vector<int>, greater<>> minq;
    priority_queue<int> maxq;
public:
    MedianFinder() {
       no = 0; 
    }
    
    void addNum(int num) {
       ++no;
       if(no < 3){
            minq.push(num);
            return;
       }
       if(no%2 == 0){
            if(num < minq.top()){
                maxq.push(num);
                int val = maxq.top();
                maxq.pop();
                minq.push(val);
                return;
            }
            minq.push(num);
            return;
       } 
       minq.push(num);
       maxq.push(minq.top());
       minq.pop();
    }
    
    double findMedian() {
        if(no == 1 || no%2)
            return minq.top(); 
        double first = minq.top();
        minq.pop();
        double second = minq.top();
        minq.push(first);
        return (first+second)/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

