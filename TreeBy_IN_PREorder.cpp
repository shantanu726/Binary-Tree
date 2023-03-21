//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/

/*
class Solution{
    public:
    Node* solve(int in[], int il, int ir, int pre[], int &pi) {
        if(ir < il)
            return NULL;
        int root = pre[pi++], i;
        Node* curr = new Node(root);
        if (il == ir) return curr;
        for(i = il; i <= ir; i++)
            if (in[i] == root) break;

        curr->left = solve(in, il, i-1, pre, pi);
        curr->right = solve(in, i+1, ir, pre, pi);
        return curr;

    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int pi = 0;
        return solve(in,0,n-1,pre,pi);
    }
};

ALL TASTE CASE PASS 305 /305
*/

// 304/305 pass not success
class Solution
{

public:
    void createmap(int in[], map<int, int> &nodeToindex, int n)

    {

        for (int i = 0; i < n; i++)

        {

            nodeToindex[in[i]] = i;
        }
    }

    Node *solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToindex)

    {

        // base case

        if (index >= n || inorderStart > inorderEnd)

        {

            return NULL;
        }

        int element = pre[index++];

        Node *root = new Node(element);

        int position = nodeToindex[element];

        // recursive call

        root->left = solve(in, pre, index, inorderStart, position - 1, n, nodeToindex);

        root->right = solve(in, pre, index, position + 1, inorderEnd, n, nodeToindex);

        return root;
    }

    Node *buildTree(int in[], int pre[], int n)

    {

        int preOrderindex = 0;

        map<int, int> nodeToindex;

        createmap(in, nodeToindex, n);

        Node *ans = solve(in, pre, preOrderindex, 0, n - 1, n, nodeToindex);

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int inorder[n], preorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout << endl;
    }
}

// } Driver Code Ends