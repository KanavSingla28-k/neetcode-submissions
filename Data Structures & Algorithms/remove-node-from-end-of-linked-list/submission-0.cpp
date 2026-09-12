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
        int cnt = 0;

        ListNode* temp = head;
        while (temp){
            cnt++;
            temp = temp->next;
        }

        if (cnt == 1 && n == 1) return nullptr;
        if (cnt == n){
            temp = head;
            head = head->next;
            temp->next = nullptr;
            delete temp;
            return head;
        }

        temp = head;
        int size = cnt-n;
        for (int i = 0; i<size-1; i++){
            temp = temp->next;
        }

        ListNode* temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;

        return head;
    }
};
