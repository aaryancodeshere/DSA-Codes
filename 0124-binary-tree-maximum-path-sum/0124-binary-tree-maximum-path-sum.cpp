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
    int ans;

    int solve(TreeNode* root){
        if(!root)return 0;

        int l = solve(root->left);
        int r = solve(root->right);

        int temp1 = l+r+root->val;
        int temp2 = max(l,r) + root->val;
        int temp3 = root->val;

        ans = max({ans,temp1,temp2,temp3});

        return max(temp3,temp2);
    }

    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        solve(root);
        return ans;
    }
};