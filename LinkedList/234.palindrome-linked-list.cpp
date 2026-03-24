/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        if(head->next == nullptr) return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next !=nullptr && fast->next->next != nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev=nullptr;
        ListNode* curr=slow->next;
        ListNode* forw=slow->next;

        while(curr != nullptr){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        slow->next=nullptr;
        slow=head;
        while(slow!=nullptr && prev!=nullptr){
            if(slow->val != prev->val){
                return false;
            }else{
                slow=slow->next;
                prev=prev->next;
            }
        }
        return true;
    }
};
// @lc code=end

