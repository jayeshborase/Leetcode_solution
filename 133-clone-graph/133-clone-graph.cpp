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
    void dfs(Node* original, Node* copy, vector<Node*> &vist){
        vist[copy->val] = copy;
        for(auto ori : original->neighbors){
            if(vist[ori->val] == NULL){
                Node *newNode = new Node(ori->val);
                (copy->neighbors).push_back(newNode);
                dfs(ori,newNode,vist);
            }else
                (copy->neighbors).push_back(vist[ori->val]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
        vector<Node*> vist(101,NULL);
        
        Node *copy = new Node(node->val);
        vist[node->val] = copy;
        
        for(auto ori : node->neighbors){
            if(vist[ori->val] == NULL){
                Node *newNode = new Node(ori->val);
                (copy->neighbors).push_back(newNode);
                dfs(ori,newNode,vist);
            }else
                (copy->neighbors).push_back(vist[ori->val]);
        }
        return copy;
    }
};