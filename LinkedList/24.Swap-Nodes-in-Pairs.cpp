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
    ListNode* swapPairs(ListNode* head) {

        if(!head || !head->next) return head;
        ListNode *prev=NULL;
        ListNode *curr1=head;
        ListNode *curr2=head;
        ListNode *nextNode=head;

        while(curr1 && curr1->next){

             curr2=curr1->next;
             nextNode=curr2->next;
             curr2->next=curr1;
             curr1->next=nextNode;

             if(!prev){
                head=curr2;
             }else{
                prev->next=curr2;
             }
             prev=curr1;
             curr1 = nextNode;
             curr2 = nextNode; 
        }
        if(curr1) prev->next=curr1;
        return head;
    }
};
