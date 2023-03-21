/*
Given a Binary Tree where each node has positive and negative values. Convert this to a tree where each node contains the sum of the left and right sub trees in the original tree. The values of leaf nodes are changed to 0.

For 
EXAMPLE 1:

                  10
               /      \
             -2        6
           /   \      /  \ 
         8     -4    7    5
should be changed to 

                 20(4-2+12+6)
               /      \
         4(8-4)      12(7+5)
           /   \      /  \ 
         0      0    0    0



Example 2:

Input:
            10
        /        \
      -2           6
     /   \        /  \
    8    -4      7     5
    / \   / \    / \   / \
  2  -2 3  -5  9  -8 2   8
Output:
            29
        /        \
       2          23
     /  \        /  \
    0   -2      1    10
   / \  / \    / \   / \
   0  0 0   0  0   0 0   0
Explanation:
                 (2+6+8-4+7+5+2-2+3-5+9-8+2+8)
               /                                \
          (8-4+2-2+3-5)                    (7+5+9-8+2+8)
          /      \                            /      \       
       (2-2)   (3-5)                        (9-8)    (2+8)
        /     \  /    \                      /     \   /     \
       0      0 0      0                   0        0 0       0

*/





// C++ program to convert a tree into its sum tree
#include <bits/stdc++.h>
using namespace std;

/* A tree node structure */
class node
{
	public:
int data;
node *left;
node *right;
};

// Convert a given tree to a tree where
// every node contains sum of values of
// nodes in left and right subtrees in the original tree
int toSumTree(node *Node)
{
	// Base case
	if(Node == NULL)
	return 0;

	// Store the old value
	int old_val = Node->data;

	// Recursively call for left and
	// right subtrees and store the sum as
	// old value of this node
	Node->data = toSumTree(Node->left) + toSumTree(Node->right);

	// Return the sum of values of nodes
	// in left and right subtrees and
	// old_value of this node
	return Node->data + old_val;
}

// A utility function to print
// inorder traversal of a Binary Tree
void printInorder(node* Node)
{
	if (Node == NULL)
		return;
	printInorder(Node->left);
	cout<<" "<<Node->data;
	printInorder(Node->right);
}

/* Utility function to create a new Binary Tree node */
node* newNode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
}

/* Driver code */
int main()
{
	node *root = NULL;
	int x;
	
	/* Constructing tree given in the above figure */
	root = newNode(10);
	root->left = newNode(-2);
	root->right = newNode(6);
	root->left->left = newNode(8);
	root->left->right = newNode(-4);
	root->right->left = newNode(7);
	root->right->right = newNode(5);
	
	toSumTree(root);
	
	// Print inorder traversal of the converted
	// tree to test result of toSumTree()
	cout<<"Inorder Traversal of the resultant tree is: \n";
	printInorder(root);
	return 0;
}

// This code is contributed by rathbhupendra
