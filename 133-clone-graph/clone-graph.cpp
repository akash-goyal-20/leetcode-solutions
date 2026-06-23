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
        if (node == NULL) {
            return NULL;
        }
        map<Node*, Node*> mp;
        Node* cloned = new Node(node->val);
        mp[node] = cloned;

        queue<pair<Node*, Node*>> q;
        q.push({node, cloned});

        while (!q.empty()) {
            Node* first = q.front().first;
            Node* second = q.front().second;
            q.pop();

            for (auto it : first->neighbors) {
                if (mp.find(it) == mp.end()) {
                    Node* n = new Node(it->val);
                    mp[it] = n;
                    second->neighbors.push_back(n);
                    q.push({it, n});
                } else {
                    Node* n = mp[it];
                    second->neighbors.push_back(n);
                }
            }
        }

        return cloned;
    }
};