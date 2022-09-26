QUESTION : Given an array arr[] of N integers and replace every element with the least greater element on its right side in the array. 
  If there are no greater elements on the right side, replace it with -1.;

Input:
arr[] = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28}
Output: {18, 63, 80, 25, 32, 43, 80, 93, 80, 25, 93, -1, 28, -1, -1}
Explanation: 
The least next greater element of 8 is 18.
The least next greater element of 58 is 63 and so on.;

Input:
arr[] = {2, 6, 9, 1, 3, 2}
Output: {3, 9, -1, 2, -1, -1}
Explanation: 
The least next greater element of 2 is 3. 
The least next greater element of 6 is 9.
least next greater element for 9 does not
exist and so on.;

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Approach 1:
Insert Every element in a BST from right to left of the given array. Take the inorder Successor instantly after inserting. That successor is next greater element.
  
   <<<<<<....... CODE BELOW .....>>>>>>
  
class Node{
   public:
   int data;
   Node* left;
   Node* right;
   Node(int x){
       data = x;
       left = NULL;
       right = NULL;
   }
};
class Solution{
    public:
    Node* insert(Node* root, int data, Node*& suc)
    {
        if(root == NULL) 
            return new Node(data);
        if(data < root->data)
        {
            suc = root; // Taking inOrder Successor
            root->left = insert(root->left,data,suc);
        }
        else if(data >= root->data)
        {
            root->right = insert(root->right,data,suc);
        }
        return root;
    }
    
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> ans(n,0);
        Node* root = NULL; // Declare our root.
        for(int i = n-1; i >= 0; i--)
        {
            Node* suc = NULL;
            root = insert(root,arr[i],suc);
            if(suc)
                ans[i] = suc->data;
            else
                ans[i] = -1;
        }
        return ans;
    }
};

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Approach 2: 

1. Declare a vector ans and fill it with -1;
2. Declare a set to get the upper bound of every element;
3. Start travarsing the array from right by FOR i = n-1 to 0;
  3.1) Insert ith element in the set.
  3.2) Declare a auto type variable it and store the upper bound of that element into it;
  3.3) Check if it == set.end() or not. It means if upper bound is found or not;
  3.4) If found then put that value inside ans vector
4. Return ans vector.


   <<<<<<....... CODE BELOW .....>>>>>>
    
class Solution{
    public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> ans(n,-1);
        set<int> st;
        for(int i = n-1; i >= 0; i--)
        {
            st.insert(arr[i]);
            auto it = st.upper_bound(arr[i]);
            if(it != st.end())
            {
                ans[i] = (*it);
            }
        }
        return ans;
    }
};

























