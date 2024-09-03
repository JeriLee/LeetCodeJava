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
 
 // 反转链表，很普通，写一写热手
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* newList = head;
        ListNode* current = newList->next;

        newList->next = nullptr;

        while( current != nullptr) {
            ListNode* newCurrent = current->next;
            current->next = newList;
            newList = current;
            current = newCurrent;
        }
        return newList;
    }
};