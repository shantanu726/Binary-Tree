/*

Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Example 1:

Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9
Output:
4 2 1 5 6 3 8 7 9
Explanation:

Example 2:

Input:
       1
    /    \
   2       3
 /    \      \
4      5      6
Output: 4 2 1 5 3 6


*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};
// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

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
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function for Inorder Traversal
void printInorder(Node *root)
{
    if (!root)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// } Driver Code Ends
class Solution
{
public:
    // Function to find the vertical order traversal of Binary Tree.

    /* vector<int> verticalOrder(Node *root)
    {
        //Your code here
        if(!root)
            return {};

        queue<pair<Node*, int>> q;
        unordered_map<int, vector<int>> mp;
        q.push({root, 0});

        int min_level = INT_MAX;
        int max_level = INT_MIN;

        while(!q.empty()) {
            Node* temp = q.front().first;
            int level = q.front().second;
            q.pop();

            min_level = min(min_level, level);
            max_level = max(max_level, level);

            mp[level].push_back(temp->data);

            if(temp->left) q.push({temp->left,level-1});
            if(temp->right) q.push({temp->right, level+1});
        }

        vector<int> ans;

        for(int i = min_level; i<= max_level; ++i) {
            for(auto& x: mp[i]) {
                ans.push_back(x);
            }
        }
        return ans;
    }
    */

    vector<int> verticalOrder(Node *root)
    {
        vector<int> ans;
        map<int, map<int, vector<int>>> hashMap;
        queue<pair<Node *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (q.empty() == false)
        {
            auto curr = q.front();
            q.pop();
            int verticalLevel = curr.second.first;
            int horizontalLevel = curr.second.second;
            Node *node = curr.first;
            hashMap[verticalLevel][horizontalLevel].push_back(node->data);
            if (node->left != NULL)
            {
                q.push({node->left, {verticalLevel - 1, horizontalLevel + 1}});
            }
            if (node->right != NULL)
            {
                q.push({node->right, {verticalLevel + 1, horizontalLevel + 1}});
            }
        }
        for (auto &e : hashMap)
        {
            for (auto &p : e.second)
            {
                for (auto &v : p.second)
                {
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        // string c;
        // getline(cin,c);
        Solution obj;
        Node *root = buildTree(s);
        vector<int> res = obj.verticalOrder(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
