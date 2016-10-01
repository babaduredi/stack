#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

struct TreeNode {
   int val;
   int height;
   TreeNode *left, *right;
   TreeNode(int val):val(val), height(1), left(NULL), right(NULL) {}
};

void preorder(TreeNode *root) {
   if (!root)
      return;
   cout << root->val << " ";
   preorder(root->left);
   preorder(root->right);
}

void postorder(TreeNode *root) {
   if (!root)
      return;
   postorder(root->left);
   postorder(root->right);
   cout << root->val << " ";
}


int height(TreeNode *node) {
   if (!node)
      return 0;
   return node->height;
}

TreeNode* rotateLeft(TreeNode *node) {
   TreeNode *newRoot = node->right;
   TreeNode *temp = node->right->left;
   node->right->left = node;
   node->right = temp;

   // update heights
   node->height = 1 + max(height(node->left), height(node->right));
   newRoot->height = 1 + max(height(newRoot->left), height(newRoot->right));

   return newRoot;
}

TreeNode* rotateRight(TreeNode *node) {
   TreeNode *newRoot = node->left;
   TreeNode *temp = node->left->right;
   node->left->right = node;
   node->left = temp;

   // update heights
   node->height = 1 + max(height(node->left), height(node->right));
   newRoot->height = 1 + max(height(newRoot->left), height(newRoot->right));

   return newRoot;
}

TreeNode* insert(TreeNode *root, int val) {
   if (!root) {
      TreeNode *newNode = new TreeNode(val);
      return newNode;
   }
   if (root->val <= val)
      root->right = insert(root->right, val);
   else
      root->left = insert(root->left, val);

   root->height = 1 + max(height(root->left), height(root->right));

   int diff = height(root->left) - height(root->right);
   if (diff > 1) { // the left cases, this will balance ultimately with right rotation
      if (root->left->val > val) { // left left case
         return rotateRight(root);
      }
      else { // left right case
         root->left = rotateLeft(root->left);
         return rotateRight(root);
      }
   }
   else if (diff < -1) { // the right cases, this will balance ultimately with left rotation
      if (root->right->val < val) { // right right case
         return rotateLeft(root);
      }
      else { // right left case
         root->right = rotateRight(root->right);
         return rotateLeft(root);
      }
   }
   return root;
}

int main() {
   TreeNode *root = NULL;

  /* Constructing tree given in the above figure */
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);

  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */

  printf("Pre order traversal of the constructed AVL tree is \n");
  preorder(root);
  cout << endl;
  printf("Post order traversal of the constructed AVL tree is \n");
  postorder(root);
  cout << endl;
  return 0;
}
