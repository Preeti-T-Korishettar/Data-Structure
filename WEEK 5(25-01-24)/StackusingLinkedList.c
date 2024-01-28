#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;
void push()
{
    int i,data;
    printf("Enter the data to be inserted\n");
    struct node *last=head;
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&data);
    new_node->data=data;
    new_node->next=NULL;
    if(head==NULL)
    {
        head=new_node;
    }
    else
    {
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=new_node;
    }
}
void pop()
{
    struct node*ptr;
    struct node*ptr1;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else if(head->next==NULL)
    {
        free(head);
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr1=ptr;
            ptr=ptr->next;
        }
        free(ptr);
        ptr1->next=NULL;
        printf("Element at the end is deleted\n");
    }
}
void display()
{
    struct node *node=head;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(node!=NULL)
        {
            printf("%d->",node->data);
            node=node->next;
        }
        printf("\n");
    }
}

void main()
{
    int ch;
    printf("Enter 1:pop \n 2:push \n 3:display \n 4:exit\n");
    while(ch!=4)
    {
    printf("Enter the choice\n");
    scanf("%d",&ch);
        switch(ch)
    {
        case 1: pop();
        break;
        case 2:push();
        break;
        case 3:display();
        break;
        case 4:exit(0);
    }
    }
}
