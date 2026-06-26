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
        queue<Node*> q;

        // clone first node
        Node* clone = new Node(node->val);
        mp[node] = clone;
        q.push(node);

        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();

            for (Node* nei : cur->neighbors) {
                if (mp.find(nei) == mp.end()) {
                    // clone neighbor
                    mp[nei] = new Node(nei->val);
                    q.push(nei);
                }
                // connect clone graph
                mp[cur]->neighbors.push_back(mp[nei]);
            }
        }

        return clone;
    }
};