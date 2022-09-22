===============================================================================
QUESTION : Given a Binary Search Tree, 
modify the given BST such that itis balanced and has minimum possible height.
===============================================================================

Input:
       30
      /
     20
    /
   10
   
Output:
     20
   /   \
 10     30
 
----------------------------------------------------------

Input:
         4
        /
       3
      /
     2
    /
   1
   
Output:
      3            3           2
    /  \         /  \        /  \
   1    4   OR  2    4  OR  1    3   OR ..
    \          /                   \
     2        1                     4 

------------------------------------------------------
Simple Approach For this program is :


1. Start inOrder travarsal and push all the nodes in a vector.
2. In order to balance the tree, we have to make the middle Node as root Node in every step.
3. For this, Call another function :

    solve(int start(0), int end(size of vector), vector<Node*>ino(the vector which stores all the nodes))
    
    i)  Like Binary Search, Set the base condition as if(start > end) return NULL;
    ii) Find the mid Node by (start + end)/2;
    iii) Make the mid index node of Node Storing vector as our root; --> root = ino[mid];
    
    iv) Call the function For root->left and set end as (mid-1) like binary search;
    v) Call the function For root->right and set start as (mid+1);
    vi) Finally return the root as our new root;
    
    

    ### CODE BELOW ###



void inOrder(Node* root, vector<Node*>& ino)
{
    if(root != NULL)
    {
        inOrder(root->left,ino);
        ino.push_back(root);
        inOrder(root->right,ino);
    }
}
Node* solve(int start, int end, vector<Node*>ino)
{
    if(start > end) return NULL;
    int mid = (start + end) / 2; // Mid Node is our new node to balance the tree.
    Node* root = ino[mid];
    root->left = solve(start,mid-1,ino);
    root->right = solve(mid+1,end,ino);
    return root;
}

Node* buildBalancedTree(Node* root)
{
	// Code here
	vector<Node*>ino; // This will store the Nodes of the tree by inOrder Travarsal
	inOrder(root,ino);
	int n = ino.size();
	root = solve(0,n-1,ino);
	return root;
}
