#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
  int value;
  struct node *left;
  struct node *right;
} node;

node *createNode       (int value);
node *insertLeft       (node *root, int value);
node *insertRight      (node *root, int value);
void inorderTraversal  (node *root);
void preorderTraversal (node *root);
void postorderTraversal(node *root);
void InsertIntoTreeUB  (node *root, int value);
// void PrintTree(node *root, int H);


int main()
{
  node *root = createNode(1);
  insertLeft(root, 2);
  insertRight(root, 3);
  insertLeft(root->left, 4);

  printf("\nInorder traversal \n");
  inorderTraversal(root);

  printf("\nPreorder traversal \n");
  preorderTraversal(root);
  printf("\n-------------------------------\n");
  // printf("\nPostorder traversal \n");
  // postorderTraversal(root);
  
  InsertIntoTreeUB(root, 5);
  InsertIntoTreeUB(root, 8);
  InsertIntoTreeUB(root, 11);
  printf("\nPreorder traversal \n");
  preorderTraversal(root);
  printf("\nInorder traversal \n");
  inorderTraversal(root);

}

// Inorder traversal
void inorderTraversal(node *root)
{
  if (root == NULL)
    return;
  inorderTraversal(root->left);
  printf("%d ->", root->value);
  inorderTraversal(root->right);
}

// Preorder traversal
void preorderTraversal(node *root)
{
  if (root == NULL)
    return;
  printf("%d ->", root->value);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(node *root)
{
    if (root == NULL)
      return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ->", root->value);
}

// Create a new Node
node *createNode(int value)
{
    node *newNode = malloc(sizeof(node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert on the left of the node
node *insertLeft(node *root, int value)
{
  root->left = createNode(value);
  return root->left;
}

// Insert on the right of the node
node *insertRight(node *root, int value)
{
  root->right = createNode(value);
  return root->right;
}

void InsertIntoTreeUB(node *root, int value)
{ 
  if (!root){
    createNode(value);
  }
  if (value < root->value){
    if (root->left == NULL){
      root->left = createNode(value);
    }
    else{
    InsertIntoTreeUB(root->left, value);
    }
  }
  else{
    if (root->right == NULL){
      root->right = createNode(value);
    }
    else{
      InsertIntoTreeUB(root->right, value);
  }
  }
}
