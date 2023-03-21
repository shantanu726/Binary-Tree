


/*
Given a binary tree, find the largest value in each level.

Example 1:

Input :
        1
       / \
      2   3 

Output : 1 3
Explanation : 
There are two levels in the tree :
1. {1}, max = 1
2. {2, 3}, max = 3
Example 2:

Input :
        4
       / \
      9   2
     / \   \
    3   5   7 

Output : 4 9 7
Explanation : 
There are three levels in the tree:
1. {4}, max = 4
2. {9, 2}, max = 9
3. {3, 5, 7}, max=7
*/






//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    /*
    vector<int> largestValues(Node* root)
    {
       vector<int>v;
       if(!root)
       {
           return v;
       }
       queue<Node*>q;
       q.push(root);
       
       while(!q.empty())
       {
           int max=INT_MIN;
          
           int size= q.size();
           for(int i=0;i<size;i++)
           {
                Node *cur =q.front();
           q.pop();
               if(cur->left)
               {
                   q.push(cur->left);
               }
               if(cur->right)
               {
                   q.push(cur->right);
               }
               if(max<cur->data)
               {
                   max=cur->data;
               }
           }
           v.push_back(max);
       }
       return v;
    }
    */
    vector<int>largestValues(Node* root,vector<int>&v){
        if(root==NULL) return{};
        
        vector<int>ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int mx=0;
            for(int i=0; i<n;i++){
                Node *tem=q.front();
        v.push_back(tem->data);
                q.pop();
                mx=max(mx,tem->data);
                
                if(tem->left) q.push(tem->left);
                if(tem->right) q.push(tem->right);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    getchar();
    while (t--)
    {

        string inp;
        getline(cin, inp);
        
        vector<int>v;
        struct Node* root = buildTree(inp);
        Solution ob;
        vector<int> ans = ob.largestValues(root,v);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << "\n";

    cout<<"it is for level order travel : ";    
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    }

    return 0;
}
// } Driver Code Ends