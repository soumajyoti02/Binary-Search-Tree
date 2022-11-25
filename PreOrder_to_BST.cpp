Question : Given an array arr[] of N nodes representing preorder traversal of some BST. You have to build the exact BST from it's' given preorder traversal. 
In Pre-Order traversal, the root node is visited before the left child and right child nodes;


Input:
N = 5
arr[]  = {40,30,35,80,100}
Output: 35 30 100 80 40
Explanation: PreOrder: 40 30 35 80 100
Therefore, the BST will be:
              40
           /      \
         30       80
           \        \   
           35      100
Hence, the postOrder traversal will
be: 35 30 100 80 40;


Input:
N = 8
arr[]  = {40,30,32,35,80,90,100,120}
Output: 35 32 30 120 100 90 80 40;


CODE :::::::


class Solution{
public:
    //Function that constructs BST from its preorder traversal.
    Node* helper(Node* root, int data)
    {
        if(root == NULL)
        {
            return newNode(data);
        }
        if(data > root->data) root->right = helper(root->right,data);
        else if(data < root->data) root->left = helper(root->left,data);
    }
    
    Node* post_order(int pre[], int size)
    {
        //code here
        Node* root = newNode(pre[0]);
        for(int i = 1; i < size; i++)        
        {
            root = helper(root,pre[i]);
        }
        return root;
    }
};
