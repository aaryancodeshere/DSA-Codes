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
class Solution {
public:

    bool check(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2)return true;
        if(!root1 || !root2)return false;

        if(root1->val != root2->val)return false;

        bool ans1 = check(root1->left,root2->right);
        bool ans2 = check(root1->right,root2->left);

        return ans1 && ans2;

    }

    bool isSymmetric(TreeNode* root) {
        if(!root->left && !root->right)return true;
        if(!root->left || !root->right)return false;
        
        return check(root->left,root->right);

    }
};