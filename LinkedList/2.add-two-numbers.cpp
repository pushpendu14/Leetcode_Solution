/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=startr
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int sum, carry=0;
        ListNode* head=nullptr,*temp=nullptr;
        while(l1 || l2 || carry){
            sum=carry;

            if(l1){
                sum += l1->val;
                l1=l1->next;
            }

            if(l2){
                sum += l2->val;
                l2=l2->next;
            }
            carry = sum/10;

            ListNode* newNode = new ListNode(sum%10);

            if(head==nullptr){
                head=newNode;
                temp=newNode;
            }else{
                temp->next=newNode;
                temp=temp->next;
            }
        }
        return head;
    }
};
// @lc code=end

