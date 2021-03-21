#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//二叉树的先序遍历
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        queue<TreeNode*> q;
        vector<int> res;
        q.push(root);
        while(!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();
            res.push_back(curr->val);
            if (curr->left != nullptr) {
                q.push(curr->left);
            }
            if (curr->right != nullptr) {
                q.push(curr->right);
            }
        }
        return res;
    }
};