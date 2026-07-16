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
    ListNode* merge(ListNode* left, ListNode *right){
        ListNode *dummy = new ListNode(0);
        ListNode *temp=dummy;

        while(left && right){
            if(left->val <= right->val){
                temp->next=left;
                temp=temp->next;
                left=left->next;
            }else{
                temp->next=right;
                temp=temp->next;
                right=right->next;
            }
        }

        if(left){
            temp->next=left;
        }

        if(right){
            temp->next=right;
        }

        return dummy->next;

    }
    ListNode* sortList(ListNode* head) {

        if(!head || !head->next) return head;

        ListNode *slow=head;
        ListNode *fast=head;

        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *r = slow->next;
        slow->next=nullptr;
        ListNode *left = sortList(head);
        ListNode *right = sortList(r);

        return merge(left,right);
        
    }
};
