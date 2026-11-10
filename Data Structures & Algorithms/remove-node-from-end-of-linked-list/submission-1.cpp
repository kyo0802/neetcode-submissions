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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*brute
        // calculate length
        int length = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            length++;
            curr = curr->next;
        }
        
        // delete head
        if (length == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        
        //walk to prev
        curr = head;
        for (int i = 0; i < length - n - 1; ++i) {
            curr = curr->next;
        }

        //delete
        ListNode* toDelete = curr->next;
        curr->next = curr->next->next;
        delete toDelete; 
        
        return head;
        */
        ListNode dummy(0, head);
        ListNode* slow = & dummy;
        ListNode* fast = & dummy;

        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }

        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
    

        return dummy.next;




    }
};
