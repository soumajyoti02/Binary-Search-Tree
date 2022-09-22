=================================================================================================
QUESTION  : Given a Binary Tree, write a function to populate next pointer for all nodes. 
The next pointer for every node should be set to point to inorder successor.
=================================================================================================
Input:
        10
       /  \
      8    12
     /
    3
  

Output: 3->8 8->10 10->12 12->-1
Explanation: The inorder of the above tree is :
3 8 10 12. So the next pointer of node 3 is 
pointing to 8 , next pointer of 8 is pointing
to 10 and so on.And next pointer of 12 is
pointing to -1 as there is no inorder successor 
of 12.

-----------------------------------------------------------

Input:
        1
      /   \
     2     3
Output: 2->1 1->3 3->-1 

-----------------------------------------------------------

Simple Approach For Solving this problem : 

(Use Reverse Inorder Traversal) 
Traverse the given tree in reverse inorder traversal and keep track of previously visited node. 
When a node is being visited, assign a previously visited node as next.

We have to Connect the next pointers of root node and make a linked-list;
So Recursively go to the last right side node and push all nodes :
    if(prev == NULL) prev = root;
    else
    {
        root->next = prev;
        prev = root;
    }


    ### CODE BELOW ###


class Solution
{
public:
    
    void inOrder(Node* root,Node* &prev)
    {
        if(root != NULL)
        {
            inOrder(root->right,prev);
            if(prev == NULL) prev = root;
            else
            {
                root->next = prev;
                prev = root;
            }
            inOrder(root->left,prev);
        }
    }
    void populateNext(Node *root)
    {
        //code here
        Node* prev = NULL;
        inOrder(root,prev);
    }
};
