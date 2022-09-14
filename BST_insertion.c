#include <stdio.h>
#include <stdlib.h>
struct node *newNode(int item);
void inorder(struct node *root);
struct node *insert(struct node *node, int key);


struct node {
  int key;
  struct node *left, *right;
};

int main() {
  struct node *root = NULL;
  int n;
  printf("Enter the value of n");
  scanf("%d",&n);
   printf("Enter the tree's value");
  while(n--){
        int x;

  scanf("%d",&x);
  root = insert(root, x);
  }

  printf("Inorder traversal: ");
  inorder(root);

}

struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

void inorder(struct node *root) {
  if (root != NULL) {

    inorder(root->left);

    printf("%d -> ", root->key);

    inorder(root->right);
  }
}

struct node *insert(struct node *node, int key) {

  if (node == NULL) return newNode(key);

  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}



