/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> randomMap;

        Node* prev = new Node(0);
        Node* travel = prev;
        Node* temp = head;

        while (temp){
            Node* newNode = new Node(temp->val);
            travel->next = newNode;
            randomMap[temp] = newNode;
            temp = temp->next;
            travel = travel->next;
        }

        travel = prev->next;
        temp = head;
        while(travel && temp){
            travel->random = randomMap[temp->random];
            travel = travel->next;
            temp = temp->next;
        }
        return prev->next;
    }
};
