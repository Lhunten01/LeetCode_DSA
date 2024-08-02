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
    ListNode* findKthNode(ListNode* temp,int k)
    {  
        for(int i=0;i<k&&temp!=NULL;i++)
        {
         temp=temp->next;
        }
        return temp;
    }
    ListNode* reverse(ListNode* head)
    {
           ListNode* prev = nullptr;
        ListNode* current = head;
        while (current != NULL) {
            ListNode* nxt = current->next;
            current->next = prev;
            prev = current;
            current = nxt;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupEnd = dummy;

        while (true) {
            ListNode* kthNode = findKthNode(prevGroupEnd, k);
            if (kthNode == nullptr) break;

            ListNode* groupStart = prevGroupEnd->next;
            ListNode* nextGroupStart = kthNode->next;
            kthNode->next = nullptr;

            prevGroupEnd->next = reverse(groupStart);
            groupStart->next = nextGroupStart;

            prevGroupEnd = groupStart;
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};