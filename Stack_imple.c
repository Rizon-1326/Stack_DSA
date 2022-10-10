#include<stdio.h>
void push( int n);
void pop();
void display();
int top=-1;
int stack[100];
int main()
{
    printf("Enter the size of Stack");
    int n;
    scanf("%d",&n);
    int ch;
  do{  printf("Enter your choice");
    printf("\n1.push()\n\n2.pop()\n\n3.display()");

    scanf("%d",&ch);

        switch(ch)
    {
        case 1:
            push(n);
            break;
        case 2:
            pop();
             break;
        case 3:
            display();
             break;

    }
}while(ch!=4);
}

void push(int n)
{

    if(top==n-1)
        printf("Stack is over flow");
    else
    {
        printf("Enter the %d value",top+1);
        top++;
        int x;
        scanf("%d",&x);
        stack[top]=x;
    }

}

void pop()
{

    if(top==-1)
        printf("Stack is underflow");
    else
    {
        printf("pop the %d value",top);

        int x;
        x=stack[top];
        top--;
        printf("%d",x);
    }
}

void display()
{
    if(top==-1)
        printf("Stack is underflow");
    else
    {
      for(int i=top;i>=0;i--)
      {
          printf("%d  ",stack[i]);
      }
    }

}

