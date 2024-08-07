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
    ListNode* addTwoNumbers(ListNode* la, ListNode* lb) {
        ListNode* result=new ListNode(-1);
        ListNode* curr=result;
        ListNode* l1=la;
        ListNode* l2=lb;
        int carry=0;
        while(l1!=NULL||l2!=NULL)
        {
            int sum=carry;
            if(l1)
            sum+=l1->val;
            if(l2)
            sum+=l2->val;
            ListNode* temp=new ListNode(sum%10);
            curr->next=temp;
            curr=curr->next;
            carry=sum/10;
            if(l1)
            l1=l1->next;
            if(l2)
            l2=l2->next;
        }
        if(carry)
       { ListNode* temp=new ListNode(carry);
        curr->next=temp;}
        return result->next;
    }
};