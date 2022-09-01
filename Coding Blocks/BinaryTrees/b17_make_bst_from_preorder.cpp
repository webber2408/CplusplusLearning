/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };

class Solution {
public:
    int i=0;
    
    TreeNode* helper(vector<int> & preorder, int maxValue){
        if(i==preorder.size() || preorder[i]>maxValue){
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[i++]);
        
        root->left = helper(preorder, root->val);
        root->right = helper(preorder, maxValue);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       return helper(preorder, INT_MAX);
    }
};
 */