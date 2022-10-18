QUESTION : Given a Binary search tree. 
Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree;

Input:
      4
    /   \
   2     9
k = 2 
Output: 4;

Input:
       9
        \ 
          10
K = 1
Output: 10;

Approach : 
--> make a counter = 1 and a variable answer  = -1 to store the answer;
i) Call For right side.
ii) if(counter == target) then add the root value to answer and increase counter and return;
iii) else just increase the counter;
iv) Call for the right side;


CODE :::::


class Solution
{
    public:
    void kthLargestUtil(Node *root, int k, int &c, int &res)
    {
        if (root == NULL || c >= k)
            return;
        
        kthLargestUtil(root->right, k, c, res);
        
        c++;
        if (c == k)
        {
    		res = root->data;
            return;
        }
        
        kthLargestUtil(root->left, k, c, res);
    }
    
    public:
    int kthLargest(Node *root, int k)
    {
        int c = 0;
        int res = -1;
        kthLargestUtil(root, k, c, res);
        return res;
    }

};
