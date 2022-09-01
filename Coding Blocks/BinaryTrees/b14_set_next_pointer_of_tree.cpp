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


class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return nullptr;
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        root->next = nullptr;
        
        while(!q.empty()){
            // Pop Logic
            Node* f = q.front();
            q.pop();
            
            // Insertion Logic
            if(f == NULL){
                if(!q.empty()) q.push(NULL);
            }else{
                //Extra Logic
                if(q.front() == NULL) f->next = nullptr;
                else f->next = q.front();
                
                // push childs
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
        }
        
        return root;
    }
};

*/