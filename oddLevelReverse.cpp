/*
Input: root = [0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]
Output: [0,2,1,0,0,0,0,2,2,2,2,1,1,1,1]
Explanation:
The odd levels have non-zero values.
The nodes at level 1 were 1, 2, and are 2, 1 after the reversal.
The nodes at level 3 were 1, 1, 1, 1, 2, 2, 2, 2, and are 2, 2, 2, 2, 1, 1, 1, 1 after the reversal.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */








class Solution
{
public:
  TreeNode *reverseOddLevels(TreeNode *root)
  {
    if (!root)
      return root;

    queue<TreeNode *> q;
    vector<int> values;
    q.push(root);
    int level = 0;
    vector<int> temp;
    while (!q.empty())
    {
      int sz = q.size();

      for (int i = 0; i < sz; i++)
      {
        TreeNode *node = q.front();
        q.pop();

        if (level % 2 != 0)
          node->val = values[sz - i - 1];

        if (node->left)
        {
          q.push(node->left);
          temp.push_back(node->left->val);
        }
        if (node->right)
        {
          q.push(node->right);
          temp.push_back(node->right->val);
        }
      }
      values = temp;
      temp.clear();
      level++;
    }
    return root;
  }
};
