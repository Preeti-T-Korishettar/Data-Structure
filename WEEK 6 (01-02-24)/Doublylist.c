#include <stdio.h>
#include <ctype.h>
struct node
{
    int val;
    struct node * prev;
    struct node * next;
};
struct node *head=NULL;
void insert_left()
{
   int pos;
   struct node* ptr1=head;
   printf("Enter the position to the left of which the data to be inserted\n");
   scanf("%d",&pos);
   struct node*new_node = (struct node*)malloc(sizeof(struct node));
   printf("Enter the value to be inserted\n");
   scanf("%d",&new_node->val);

   if(head==NULL)
   {
       head=new_node;
       head->prev=NULL;
       head->next=NULL;
   }
   else if(pos==1)
   {
       new_node->next=head;
       new_node->prev=NULL;
       head->prev=new_node;
       head=new_node;
   }
   else
   {
   for(int i=0;i<pos-1;i++)
   {
       ptr1=ptr1->next;
   }
   new_node->prev=ptr1->prev;
   new_node->next=ptr1;
   ptr1->prev->next=new_node;
   ptr1->prev=new_node;
   }
}
void delete_pos()
{
   int data;
   struct node* ptr=head;
   printf("Enter the data to be deleted\n");
   scanf("%d",&data);
   if(ptr->val==data)
   {
     head=head->next;
     free(ptr);
     printf("Deleted\n");
     return;
   }
   else
  {
   while(ptr->val!=data)
   {
       ptr=ptr->next;
       if(ptr->next==NULL)
       {
           ptr->prev->next=NULL;
           free(ptr);
           printf("deleted\n");
           return;
       }
   }
   ptr->next->prev=ptr->prev;
   ptr->prev->next=ptr->next;
   head=ptr;
   printf("Deleted");
  }
}
void display()
{
   struct node*p=head;
   while(p!=NULL)
   {
       printf("%d->",p->val);
       p=p->next;
   }
}
void main()
{
    int ch;
    printf("Enter:\n 1:insert\n 2:delete\n 3:display \n 4:exit\n ");
    while(ch!=4)
    {
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert_left();
            break;
            case 2:delete_pos();
            break;
            case 3:display();
            break;
        }
    }
}
