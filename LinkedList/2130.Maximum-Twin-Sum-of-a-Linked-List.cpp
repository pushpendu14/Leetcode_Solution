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
    ListNode* reverse(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* forw=head;

        while(curr){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;

        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* prev=nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=nullptr;
        ListNode* reverseHead = reverse(slow);

        int sumOfTwin=INT_MIN;
        while(head){
            int sum = head->val + reverseHead->val;
            head = head->next;
            reverseHead = reverseHead->next;
             sumOfTwin = max(sumOfTwin,sum);
        }

        return sumOfTwin;
    }
};
