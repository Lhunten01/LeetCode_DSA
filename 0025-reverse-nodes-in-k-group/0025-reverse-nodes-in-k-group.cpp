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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||head->next==NULL)
        return head;
        ListNode* temp=head;
        int length=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            length++;
        }

        ListNode* tempNode=new ListNode(0);
        tempNode->next=head;
        ListNode* prev=tempNode;
        ListNode* curr;
        ListNode* nex;
        while(length>=k)
        {   curr=prev->next;
            nex=curr->next;
            for(int i=1;i<k;i++)
            {  
               curr->next = nex->next;
               nex->next = prev->next;
               prev->next = nex;
               nex = curr->next;
            }
            prev=curr;
            length=length-k;
        }
        return tempNode->next;

    }
};