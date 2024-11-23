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
#include <queue>

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;  
        
        std::queue<TreeNode*> nodes;
        nodes.push(root);  
        int levels = 0;    
        
        while (!nodes.empty()) {
            int size = nodes.size();
            levels++;                
            
            for (int i = 0; i < size; i++) {
                TreeNode* currentNode = nodes.front();  
                nodes.pop();
                
                if (currentNode->left != nullptr) nodes.push(currentNode->left);
                if (currentNode->right != nullptr) nodes.push(currentNode->right);
            }
        }
        
        return levels;
    }
};
