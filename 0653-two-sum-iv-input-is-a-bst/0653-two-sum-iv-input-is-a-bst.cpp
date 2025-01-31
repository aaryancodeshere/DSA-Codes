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
    bool search(TreeNode* root,unordered_set<int>& s, int k){
        if(!root)return false;
        if(s.contains(k-root->val))return true;
        s.insert(root->val);
        return search(root->left,s,k) || search(root->right,s,k);
    }

    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return search(root,s,k);

    }
};