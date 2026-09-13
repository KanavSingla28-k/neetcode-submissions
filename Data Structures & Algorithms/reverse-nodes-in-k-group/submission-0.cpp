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
        if (!head) return head;

        int cnt = 0;
        ListNode* temp = head;
        while (temp){
            cnt++;
            temp = temp->next;
        }
        if (cnt<k) return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        for (int i = 0; i<k; i++){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        if (curr) head->next = reverseKGroup(curr, k);

        return prev;
    }
};
