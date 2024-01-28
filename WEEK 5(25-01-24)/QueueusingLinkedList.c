#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;
void enqueue()
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
void dequeue()
{
    struct node*ptr;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        ptr=head;
        head=head->next;
        free(ptr);
        printf("First element is deleted\n");
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
    printf("Enter\n 1:enqueue \n 2:dequeue \n 3:display \n 4:exit\n");
    while(ch!=4)
    {
    printf("Enter the choice\n");
    scanf("%d",&ch);
        switch(ch)
    {
        case 1:enqueue();
        break;
        case 2:dequeue();
        break;
        case 3:display();
        break;
        case 4:exit(0);
    }
    }
}