QUESTION : Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees;

Input:
   2
 /    \
1      3
Output: 1 
Explanation: 
The left subtree of root node contains node
with key lesser than the root nodes key and 
the right subtree of root node contains node 
with key greater than the root nodes key.
Hence, the tree is a BST;


Input:
  2
   \
    7
     \
      6
       \
        5
         \
          9
           \
            2
             \
              6
Output: 0 ;


CODE :::

class Solution {
public:
    void check(TreeNode* root, TreeNode* &prev, int &f)
    {
        if(root == nullptr) return;
        check(root->left,prev,f);
        if(prev != nullptr and root->val <= prev->val) 
        {
            f = 0;
            return;
        }
        else prev = root;
        check(root->right,prev,f);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode *prev = nullptr;
        int f = 1;
        check(root,prev,f);
        return f;
    }
};
