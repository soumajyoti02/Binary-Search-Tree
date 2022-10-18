QUESTION : Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.;
===========================================================================================================================================
Input:
      1
    /   \
   2     3
Output: 1 2 3;
-----------------------------------------

Input:
          1
       /    \
     2       3
   /        
 4       
Output: 1 2 3 4
Explanation:
The converted BST will be

        3
      /   \
    2     4
  /
 1
  
  
=======================================================================
  
class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void construct(Node* root, vector<int> inorder,int &i)
    {
        if(root == NULL) return;
        construct(root->left,inorder,i);
        root->data = inorder[i];
        i++;
        construct(root->right,inorder,i);
    }
    void inOrder(Node *root, vector<int>& inorder)
    {
        if(root)
        {
            inOrder(root->left,inorder);
            inorder.push_back(root->data);
            inOrder(root->right,inorder);
        }
    }
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        vector<int> inorder;
        inOrder(root,inorder);
        sort(inorder.begin(),inorder.end());
        int i = 0;
        construct(root,inorder,i);
        return root;
    }
};
