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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* temp = head;

        while (temp->next->next){
            temp->next = rever(temp->next);
            temp = temp->next;
        }        
    }

    ListNode* rever(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nxt = head->next;

        while (curr){
            curr->next = prev;
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
        }

        return prev;        
    }
};
