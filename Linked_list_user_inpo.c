#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next;
} ;
struct node*head=NULL;
void create(int n);
void display();
void insert_beginning(int p);
void insert_end(int q);
void insert_middle(int pos,int r);
void delete_begin();
void delete_end();

int main()
{
    printf("Enter the value of size\n");
    int n;
    scanf("%d",&n);
    printf("Enter the elements\n");
    create(n);
      display();
    printf("\n");
    printf("Insert element at the beginning\n");
    for(int i=0; i<2; i++)
    {
        int p;
        scanf("%d",&p);
        insert_beginning(p);
    }
     printf("Linked listed values are\n");
    display();
    printf("Insert element at the end\n");
    for(int i=0; i<2; i++)
    {
        int q;
        scanf("%d",&q);
        insert_end(q);
    }
    display();
    printf("Insert element at middle  ");

    int r,pos;
    scanf("%d%d",&pos,&r);
    insert_middle(pos,r);

    display();
    printf("Dlt 1st element\n");
    delete_begin();
    display();
    printf("Dlt last element\n");
    display();
}

void create(int n)
{
    int x;
    struct node *temp,*newnode;

    head=(struct node *)malloc(sizeof(struct node));
    if(head==NULL)
        printf("There is no space");
    else
    {
        printf("Enter 1st element & implement linked list-->");
        scanf("%d",&x);
        head->num=x;
        head->next=NULL;
        temp=head;
    }


    for(int i=2; i<=n; i++)
    {

        newnode= (struct node *)malloc(sizeof(struct node));
        if( newnode==NULL)
        {
            printf("There is no space");
        }
        else
        {
            printf("Enter the  elements of %dth\n",i);
            scanf("%d",&x);
            newnode->num=x;
             newnode->next=NULL;

            temp->next=newnode;
            temp=temp->next;
        }
    }
}

void display()
{
    struct node *temp;
    if(head==NULL)
        printf("EMPTY");
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("Data->%d\n",temp->num);
            temp=temp->next;
        }
    }
}

void insert_beginning(int p)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->num=p;
    temp->next=head;
    head=temp;
}

void insert_end(int q)
{

    struct node*temp = (struct node*)malloc(sizeof(struct node));
    temp->num = q;
    temp->next = NULL;

    struct node *newnode = head;
    while(newnode->next != NULL)
    {
        newnode= newnode->next;
    }

    newnode->next = temp;
}

void insert_middle(int pos,int r)
{
    struct node *temp= malloc(sizeof(struct node));
    temp->num = r;

    struct node *newnode =head;

    for(int i=2; i < pos; i++)
    {
        if(newnode->next != NULL)
        {
            newnode= newnode->next;
        }
    }
    temp->next = newnode->next;
    newnode->next = temp;
}

void delete_begin()
{
    head=head->next;
}
void delete_end()
{
    struct node* temp = head;
    while(temp->next->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}
