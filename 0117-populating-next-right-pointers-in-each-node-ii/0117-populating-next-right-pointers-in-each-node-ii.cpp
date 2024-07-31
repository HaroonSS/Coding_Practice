/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if(!root)
            return {};
        
        queue<Node*> q;
        
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                Node* currNode = q.front();
                q.pop();
                
                if(size == 0){
                    currNode->next = NULL;
                } else {
                    currNode->next = q.front();
                }
                
                if(currNode->left){
                    q.push(currNode->left);
                }
               if(currNode->right){
                    q.push(currNode->right);
                }
            }
        }
        
        return root;
        
    }
};