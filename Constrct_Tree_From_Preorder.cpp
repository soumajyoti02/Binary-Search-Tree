QUESTION : Construct a binary tree of size N using two given arrays pre[] and preLN[]. Array pre[] represents preorder traversal of a binary tree. 
Array preLN[] has only two possible values L and N. The value L in preLN[] indicates that the corresponding node in Binary Tree is a leaf node and
value N indicates that the corresponding node is a non-leaf node.
Note: Every node in the binary tree has either 0 or 2 children;

Input :      
N = 5
pre[] = {10, 30, 20, 5, 15}
preLN[] = {N, N, L, L, L}

Output:
          10
        /    \
      30      15
     /  \     
   20    5   
            
            
Simple Approach To solve this program is as Follows :

1. Create an empty stack;
2. Initialize the root as INT_MIN;
3. Traverse the given array;
  3.1) If we find any element lesser than root then return false ;
  3.2) Only Check the elements for right sub-tree;
    As we storing the nodes value in stack at last, Check that if stack_top is lesser than arr[i] then pop untill it becomes false;
    Make root as new stack_top();
    --> Because at right side, Only Assending type elements are present.

  3.3) push the arr[i] into stack;

4. Finally return 1 if 0 isnot returned in any place;


<<<<<----- CODE BELOW ----->>>>>



class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
        // Create an empty stack
        stack<int> s;

        // Initialize current root as minimum possible value
        int root = INT_MIN;

        // Traverse given array
        for (int i = 0; i < N; i++) {
            // If we find a node who is on right side and smaller than root, return false
            if (arr[i] < root) return 0;

            /* If pre[i] is in right subtree of stack top,
            Keep removing items smaller than pre[i]
            and make the last removed item as new
            root. */
            while (!s.empty() && s.top() < arr[i]) {
                root = s.top();
                s.pop();
            }

            /* At this point either stack is empty or
               pre[i] is smaller than root, push pre[i] */
            s.push(arr[i]);
        }
        return 1;
    }
};
