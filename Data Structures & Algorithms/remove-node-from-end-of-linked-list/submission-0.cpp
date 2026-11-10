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
        int length = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            length++;
            curr = curr->next;
        }
        
        // 2. 特殊情況：如果要刪除的是頭節點 (head)
        if (length == n) {
            ListNode* newHead = head->next;
            delete head; // 釋放記憶體
            return newHead;
        }
        
        // 3. 第二次走訪：走到要刪除節點的前一個位置
        curr = head;
        // 需要走 length - n - 1 步
        for (int i = 0; i < length - n - 1; ++i) {
            curr = curr->next;
        }
        
        // 4. 執行刪除
        ListNode* toDelete = curr->next;
        curr->next = curr->next->next;
        delete toDelete; // 釋放記憶體
        
        return head;
    }
};
