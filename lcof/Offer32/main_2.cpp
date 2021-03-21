#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//二叉树的层序遍历
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>>  res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> tmp;
            for (int i = q.size(); i > 0; --i) {
                TreeNode *node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};