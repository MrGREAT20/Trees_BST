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
public:
    void preorder(TreeNode* root)
    {
        if(root == NULL){
            return ;
        }
        ans.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        ans.clear();
        preorder(root);
        return ans;
    }
};