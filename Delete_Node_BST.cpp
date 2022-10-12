QUESTION : Given a root node reference of a BST and a key, 
delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.;


Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.';
=====================================================================================
APPROACH :: 

When we delete a node from a Binary Search Tree(BST), the BST properties should remain the same.
Hence, we have 3 cases for deleting a node from a BST :

--> The node is a leaf node - In this cases, we can just delete the node and return the root, since deleting any elaf node doesn't affect the remainig tree.

--> The node has one child - In this case, replace the node with the child node and return the root.

--> The node has 2 children - In this case, in order to conserve the BST properties, we need to replace the node with it's inorder successor (The next node that comes in the inorder traversal) i.e;' 
  we need to replace it with either :
1. The greatest value node in its left subtree (or)
2. The smallest value node in its right subtree
and return the root.

Time Complexity : O(h) - h = height of the tree.
(Worst case Time Complexity : O(n) );




CODE :::::::::::::


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root) 
            if(key < root->val) root->left = deleteNode(root->left, key);     //We frecursively call the function until we find the target node
            else if(key > root->val) root->right = deleteNode(root->right, key);       
            else{
                if(!root->left && !root->right) return NULL;          //No child condition
                if (!root->left || !root->right)
                    return root->left ? root->left : root->right;    //One child contion -> replace the node with it's child
					                                                //Two child condition   
                TreeNode* temp = root->left;                        //(or) TreeNode *temp = root->right;
                while(temp->right != NULL) temp = temp->right;     //      while(temp->left != NULL) temp = temp->left;
                root->val = temp->val;                            //       root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);  //        root->right = deleteNode(root->right, temp);		
            }
        return root;
    }   
};
