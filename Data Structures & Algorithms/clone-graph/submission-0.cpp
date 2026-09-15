/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> mp;

        Node* copy = new Node(node->val, {});
        mp[node] = copy;

        queue<Node*> q;
        q.push(node);

        while (!q.empty()){
            Node* curr = q.front(); q.pop();

            for (Node* n: curr->neighbors){
                if (!mp.count(n)){
                    mp[n] = new Node(n->val, {});
                    q.push(n);
                }
                mp[curr]->neighbors.push_back(mp[n]);
            }         
        }
        return copy;
    }
};
