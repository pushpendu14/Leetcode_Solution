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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummySmall = new ListNode(0);
        ListNode *dummyLarge = new ListNode(0);

        ListNode *small = dummySmall;
        ListNode *large = dummyLarge;

        while(head){
            if(head->val < x){
                small->next = head;
                small=small->next;
            }else {
                large->next = head;
                large=large->next;
            }
            head=head->next;
        }
        large->next=nullptr;
        small->next = dummyLarge->next;

        return dummySmall->next;
    }
};
