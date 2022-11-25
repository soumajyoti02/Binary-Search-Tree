Question : Given two BSTs, return elements of both BSTs in sorted form;

Input:
BST1:
       5
     /   \
    3     6
   / \
  2   4  
BST2:
        2
      /   \
     1     3
            \
             7
            /
           6
Output: 1 2 2 3 3 4 5 6 6 7
Explanation: 
After merging and sorting the
two BST we get 1 2 2 3 3 4 5 6 6 7;


Input:
BST1:
       12
     /   
    9
   / \    
  6   11
BST2:
      8
    /  \
   5    10
  /
 2
Output: 2 5 6 8 9 10 11 12
Explanation: 
After merging and sorting the
two BST we get 2 5 6 8 9 10 11 12;



Code below :::::


class Solution
{
    public:
    void inorder(Node* root, vector<int>& ans)
    {
        if(root) {
            inorder(root->left,ans);
            ans.push_back(root->data);
            inorder(root->right,ans);
        }
    }
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> tree1;
       vector<int> tree2;
       
       inorder(root1,tree1);
       inorder(root2,tree2);
       
       vector<int> ans;
       
       int i = 0, j = 0;
       
       while(i < tree1.size() and j < tree2.size()) {
           if(tree1[i] < tree2[j]) 
           {
               ans.push_back(tree1[i]);
               i++;
           }
           else 
           {
               ans.push_back(tree2[j]);
               j++;
           }
       }
       
       while(i < tree1.size())
       {
           ans.push_back(tree1[i]);
           i++;
       }
       while(j < tree2.size())
       {
           ans.push_back(tree2[j]);
           j++;
       }
       return ans;
    }
};















