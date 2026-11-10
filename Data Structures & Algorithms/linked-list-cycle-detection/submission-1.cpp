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
    bool hasCycle(ListNode* head) {
        /*brute
        ListNode* cur = head;
        unordered_set<ListNode*> visited;
        while (cur != nullptr){
            if (visited.count(cur->next)){
                return true;
            }
            visited.insert(cur);
            cur = cur->next;
        }
        return false;
        */
        //fast&slow
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast){
                return true;
            }
        }
        return false;
    }
};
