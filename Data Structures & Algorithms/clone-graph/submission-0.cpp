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

    unordered_map<Node*, Node*> mp;
    Node* dfs(Node* node) {

    // Base Case 寫在這裡
    if (node == nullptr){
        return nullptr;
    }
    if (mp.count(node)) {
        return mp[node];
    }
    Node* copy = new Node(node->val);
    mp[node] = copy;

    // 處理 neighbors
    for (auto neighbor : node->neighbors) {
        Node* clonedNeighbor = dfs(neighbor);
        // 將 clonedNeighbor 加入 copy 的 neighbors
        copy->neighbors.push_back(clonedNeighbor);
    }

    // 回傳目前節點的 Clone
    return copy;
    }


    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};
