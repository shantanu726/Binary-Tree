/*
Given a binary tree of size N, your task is to that find all duplicate subtrees from the given binary tree.

Note: Here's the Output of every Node printed in the Pre-Order tree traversal format. Arrange nodes in the answer array based on the lexicographically incresing order of their preorder traversal of subtree.
For Example: if we have 3 preorder traversal as {1,2,3},{1},{11,2,3} than your lexicographically increasing order is {1},{1,2,3},{11,2,3}, you are supposed to output the head of all these subtrees in the same order.
Input :
       1
      / \
     2   3
    /   / \
   4   2   4
      /
     4

Output : 
   2           
  /    and    4
 4
Explanation: Above Trees are two duplicate subtrees. 
Therefore, you need to return above trees root in the 
form of a list.
Explanation: Above Trees are two 
duplicate subtrees.i.e  and 
Therefore,you need to return above trees 
root in the form of a list.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = "";
        currVal+=ip[i];
            
        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

void preorder(Node* root,vector<int> &temp){
    if(!root){
        return ;
    }
    //cout<<root->data<<" ";
    temp.push_back(root->data);
    preorder(root->left,temp);
    preorder(root->right,temp);
}


// } Driver Code Ends
//function Template for C++

/*
Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node* left, *right;
};
*/
// you are required to complete this function
// the function and return an vector of Node
// which contains all the duplicate sub-tree

 vector<Node*>ans;
 unordered_map<string,int>mp;
   
   string solve(Node*root){
       if(root==NULL)
       return "$";
       
       string s=" ",lf,ri;
       
    
    // s=s+to_string(root->data);
    
       s=s+solve(root->left);
         s=s+to_string(root->data);
       s=s+solve(root->right);
       
     
     /*
       lf = solve(root->left);
       ri = solve(root->right);
        s = to_string(root->data)+"🙂"+lf+"🙂"+ri;
    */
    
   mp[s]++;
   
       if(mp[s]==2){
       ans.push_back(root);
       }
       return s;
       }
  
   vector<Node*> printAllDups(Node* root){

      ans.clear();
      mp.clear();
       solve(root);
       return ans;
      
   }



int main() {


    int tc;
    cin>>tc;
    while(tc--)
    {
        
        string treeString;
        getline(cin>>ws,treeString);
        //cin.ignore();
        //cin.clear();
        //cout<<treeString<<"\n";

        Node* root = buildTree(treeString);
        vector<Node*> res = printAllDups(root);

        vector<vector<int>>ans;
        
        for(int i=0;i<res.size();i++){
            vector<int> temp;
            preorder(res[i],temp);
            ans.push_back(temp);
        }
        
        sort(ans.begin(),ans.end());
        
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
        //cout<<"\n";

        
    }
return 0;
}





// } Driver Code Ends