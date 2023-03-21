/*
..................................  Video 62 luv  .....................................
1. TREE CREATION
2. TREE LEVEL ORDER TRAVEL
3. TREE INORDER
4. TREE PREORDER
5. TREE POSTORDER

*/

#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *bulidTree(node *root)
{
    cout << "Enter data  " << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data for inserting LEFT side " << endl;
    root->left = bulidTree(root->left);
    cout << "Enter data for inserting in RIGHT side " << endl;
    root->right = bulidTree(root->left);
    return root;
}

void levelorderTravel(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *tem = q.front();
        q.pop();
        if (tem == NULL)
        { // past level travel is complete
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << tem->data << " ";
            if (tem->left)
            {
                q.push(tem->left);
            }
            if (tem->right)
            {
                q.push(tem->right);
            }
        }
    }
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    // inorder(root->left);
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    // inorder(root->left);
    // cout<<root->data<<" ";
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelorderTOtree(node *&root)
{
    queue<node *> q;
    cout << "enter data for root " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << "enter left node for : " << temp->data << endl;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        cout << "enter right node for : " << temp->data << endl;
        int rightdata;
        cin >> rightdata;

        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    /*
    ans:
    1
    3 5
    7 11 17
    */
    node *root = NULL;

    /*
    // creating NULL;
    root = bulidTree(root);
    cout << endl;
    cout << endl;
    //
    cout << "level order travel\n";
    levelorderTravel(root);
    cout << "inorder travel " << endl;
    inorder(root);
    cout << endl;
    cout << "preorder travel " << endl;
    preorder(root);
    cout << endl;
    cout << "Postorder travel " << endl;
    postorder(root);
    */

    levelorderTOtree(root); // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    levelorderTravel(root);
    return 0;
}

//  REVERSE LEVEL ORDER
/*
2 11 17
3 5
1
 */