#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *top=0;
void push();
void pop();
void display();
void peek();
int main()
{
    push(2);
    push(3);
    push(4);
    display();
    peek();
    push(5);
    peek();
    display();
    pop();
    peek();
    display();
}


void push(int x)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=top;
    top=newnode;
}

void display()
{
    struct node *temp;
    temp=top;
    if(top==0)
        printf("Empty");
    else
    {

        while(temp!=0)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

void peek()
{
    struct node *temp;
    temp=top;
    if(top==0)
        printf("Empty");
    else
    {
        printf("\ntop element is->%d\n",top->data);
    }

}

void pop()
{
    struct node *temp;
    temp=top;
     if(top==0)
        printf("Empty");

    else
    {
       printf("\ntop element is->%d\n",top->data);
       top=top->next;
       free(temp);

    }
}

