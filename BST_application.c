#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right,*parent;
};
struct node* root=NULL;
struct node*BST_insert(struct node *root,int key);
struct node*newnode(int key);
struct node * Max_node(struct node *Tnode);
struct node * Min_node(struct node *Tnode);
struct node * Tree_successor(int key);
void Inorder(struct node *Tnode);
struct node* Tree_search(struct node * Tnode,int key);
void Tree_delete(int key);

int main()
{
    int n;
    printf("Enter the size of tree\n");
    scanf("%d",&n);
    int r;
printf("Enter the value of root\n");
scanf("%d",&r);
root=BST_insert(root,r);
    for(int i=1;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        BST_insert(root,x);
    }
    printf("Print the values in inorder tree ");
    Inorder(root);
    printf("\n");

    printf("Print the maximum value\n");
    struct node *max= Max_node(root);
    printf("maximum value is %d\n",max->data);

    printf("Print the minimum value\n");
    struct node *min= Min_node(root);
     printf("minimum value is %d\n",min->data);


    printf("Enter the element you want to search:\n");
    int a;
    scanf("%d",&a);
    struct node * search=Tree_search(root,a);
    if(search==NULL){
        printf("Element not found\n");
    }
    else
    printf("searched element is %d\n",search->data);

    printf("Enter the element whose successor should be expose\n");

     int s;
     scanf("%d",&s);
     struct node * successor=Tree_successor(s);
    printf("successor is %d element is %d\n",s,successor->data);

    printf("Enter the element you want to delete \n");
    scanf("%d",&a);
    Tree_delete(a);
    printf("After deletion:\n");
    Inorder(root);
    printf("\n");
}

struct node*BST_insert(struct node *root,int key)
{
    struct node* y=NULL;
    struct node* x=root;
    struct node * z=newnode(key);
    while(x!=NULL)
    {
        y=x;
        if(z->data<x->data)
        {
            x=x->left;
        }
        else
        {
         x=x->right;
        }

    }
    z->parent=y;

    if(y==NULL)
    {
        root=z;
    }
    else if(z->data<y->data)
        y->left=z;
    else
        y->right=z;
    return root;

};

struct node*newnode(int key)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=key;
    temp->left=temp->right=temp->parent=NULL;
    return temp;
};

void Inorder(struct node *Tnode)
{
    if(Tnode!=NULL)
    {
        Inorder(Tnode->left);
        printf("%d\t",Tnode->data);
        Inorder(Tnode->right);
    }

}
struct node * Max_node(struct node *Tnode)
{
    while(Tnode->right!=NULL)
    {
        Tnode=Tnode->right;
    }
    return Tnode;
};
struct node * Min_node(struct node *Tnode)
{
    while(Tnode->left!=NULL)
    {
        Tnode=Tnode->left;
    }
    return Tnode;
};

struct node* Tree_search(struct node * Tnode,int key){
    if (key==NULL || key== Tnode->data){
        return Tnode;
    }
    if(key<Tnode->data){
        return Tree_search(Tnode->left,key);
    }
    else return Tree_search(Tnode->right,key);
};

struct node *Tree_successor (int value){
    struct node* x=Tree_search(root,value);
    if (x->right!=NULL){
        return Min_node(x->right);
    }
    struct node* y=x->parent;
    while(y!=NULL&&x==y->right){
        x=y;
        y=y->parent;
    }
    return y;

}

void Tree_delete(int key){
    struct node* z=Tree_search(root,key);
    struct node* y;
    struct node* x;

    if (z->left==NULL||z->right==NULL){
        y=z;
    }
    else y=Tree_successor(z->data);
    if(y->left!=NULL){
        x=y->left;
    }
    else x=y->right;
    if(x!=NULL){
        x->parent=y->parent;
    }
    if(y->parent==NULL){
        root=x;
    }
    else if(y==y->parent->left){
        y->parent->left=x;
    }
    else y->parent->right=x;
    if(y!=z){
        z->data=y->data;
    }

};
