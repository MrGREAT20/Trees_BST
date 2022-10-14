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
 */
vector<int>ans;
class Solution {
    void inorder(TreeNode* root){
        if(root == NULL){
            return ;
        }
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        ans.clear();
        inorder(root);
        return ans;
        
    }
};