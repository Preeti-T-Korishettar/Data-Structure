#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head1=NULL;
struct node *head2=NULL;
void linklist1()
{
    int n,i,data;
    printf("Enter the number of elements in linked list\n");
    scanf("%d",&n);
    printf("Enter the elements to be inserted for first linked list\n");
    for(i=0;i<n;i++)
    {
    struct node *last1=head1;
    struct node *new_node1;
    new_node1=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&data);
    new_node1->data=data;
    new_node1->next=NULL;
    if(head1==NULL)
    {
        head1=new_node1;
    }
    else
    {
    while(last1->next!=NULL)
    {
        last1=last1->next;
    }
    last1->next=new_node1;
    }
    }
}
void linklist2()
{
    int n,i,data;
    printf("Enter the number of elements in linked list\n");
    scanf("%d",&n);
    printf("Enter the elements to be inserted for second linked list\n");
    for(i=0;i<n;i++)
    {
    struct node *last2=head2;
    struct node *new_node2;
    new_node2=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&data);
    new_node2->data=data;
    new_node2->next=NULL;
    if(head2==NULL)
    {
        head2=new_node2;
    }
    else
    {
    while(last2->next!=NULL)
    {
        last2=last2->next;
    }
    last2->next=new_node2;
    }
    }
}
void sort()
{
    struct node *curr = head1;
    struct node *ptr = NULL;
    int temp;
    while(curr != NULL)
    {
        ptr = curr->next;
        while(ptr !=NULL)
        {
            if(curr->data > ptr->data)
            {
                temp = curr->data;
                curr->data=ptr->data;
                ptr->data=temp;
            }

            ptr = ptr->next;
        }
        curr = curr->next;
    }
    display();

}
void reverse()
{
    struct node* prev=NULL;
    struct node* ptr=NULL;
    while(head1!=NULL)
    {
        ptr=head1->next;
        head1->next=prev;
        prev=head1;
        head1=ptr;
    }
    head1=prev;
    display();
}
void concate()
{
    struct node*temp=head1;
    if(head1==NULL)
    {
       struct node *node=head2;
        while(node!=NULL)
        {
            printf("%d->",node->data);
            node=node->next;
        }
        printf("\n");
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=head2;
    }
    struct node *node=head1;
        while(node!=NULL)
        {
            printf("%d->",node->data);
            node=node->next;
        }
        printf("\n");
}
void display()
{
    struct node *node=head1;
    if(head1==NULL)
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
    printf("First list\n");
    linklist1();
    printf("Implementation of sort\n");
    printf("Elements after sorting are\n");
    sort();
    printf("Implementation of reversing linked list\n ");
    printf("Elements after reversing the linked list are\n");
    reverse();
    printf("Implementation of concatenation\n");
    linklist2();
    printf("Elements after concatenation are\n");
    concate();
    printf("All operations are done\n");

}
