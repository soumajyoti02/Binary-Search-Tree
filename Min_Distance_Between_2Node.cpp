=======================================================================================================================
QUESTION : Given a binary tree and two node values your task is to find the minimum distance between them.
The given two nodes are guaranteed to be in the binary tree.
=======================================================================================================================
Input:
        1
      /  \
     2    3
a = 2, b = 3
Output: 2
  
Explanation: The tree formed is:
       1
     /   \ 
    2     3
We need the distance between 2 and 3.
Being at node 2, we need to take two
steps ahead in order to reach node 3.
The path followed will be:
2 -> 1 -> 3. Hence, the result is 2.
-------------------------------------------------------
  
Simple Approach for this program is as follows :

1. Find the least Common Ancestor of the 2 node a and b;
2. Find the distance of 2 node from that ancestor Node.
3. Simply return the SUM OF DISTANCE OF 2 NODE. 
  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  
In NodeCount function which return the distance of the Node from a root :
---> (root,data,count,ans)
  
 1. It's a recursive function. So set a base condition when root == NULL then return NULL;
 2. If data will become equal to root->data then just copy the value of count in ans;
 3. Call the recursive function 2 times.
   
   i) for root->left and increase count by 1.
   ii) for root->right and increase count by 1.
        
        
In cA function which return the Common Node of 'a' and 'b' :
---> (root,a,b)
  
 1. If root == NULL then return NULL;
 2. If any 1 Node (either 'a' or 'b') is found then return root i.e. return that node as root;
 3. Call the Function recursively 2 times :

   i) For root->left; 
   ii) For root->right;

 4. If Both Left and Right are not NULL then return root as the Ancestor.
 5. If Left is not NULL then return Left;
 6. If only Right is not NULL then return Right;
 7. Return NULL if any other cases arised.
  
  
  
  
  
  
  
  
  
  
class Solution{
    
    /* Should return minimum distance between a and b
    in a tree with given root*/
 public: 
    void nodeCount(Node* root, int data,int count, int& ans)
    {
        if(root == NULL)
            return;
        
        if(root->data == data)
            ans = count;
        
        nodeCount(root->left,data,count+1,ans); // Calling for left part.
        nodeCount(root->right,data,count+1,ans); // Calling for right part.
    }
    
   
    Node* cA(Node* root,int a,int b)
    {
        if(root == NULL) return NULL;
        if(root->data == a or root->data == b) return root;
        
        Node* left = cA(root->left,a,b);
        Node* right = cA(root->right,a,b);
        
        if(left != NULL and right != NULL) return root; 
        else if(left == NULL and right != NULL) return right;
        else if(right == NULL and left != NULL) return left;
        else return NULL;
    }
    
   
    int findDist(Node* root, int a, int b) {
        // Your code here
        root = cA(root,a,b);
        int ans1 = 0, ans2 = 0;
        nodeCount(root,a,0,ans1);
        nodeCount(root,b,0,ans2);
        
        return (ans1+ans2);
        
    }
};
