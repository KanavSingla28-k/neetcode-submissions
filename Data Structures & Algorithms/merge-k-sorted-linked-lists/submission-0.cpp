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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int, vector<ListNode*>> mp;

        for (ListNode* a: lists){
            while (a){
                mp[a->val].push_back(a);
                a = a->next;
            }
        }

        ListNode dummy(0);
        ListNode* temp = &dummy;

        for (auto& p: mp){
            for (ListNode* a: p.second){
                temp->next = a;
                temp = temp->next;
            }
        }

        return dummy.next;
    }
};
