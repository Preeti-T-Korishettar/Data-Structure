#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node*right;
};
struct node*root=NULL;

void create()
{
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to be inserted\n");
    scanf("%d",&new_node->data);
    struct node*ptr=root;
    struct node*ptr1;
    new_node->left=NULL;
    new_node->right=NULL;

    if(root==NULL)
    {
        root=new_node;
    }
    else
    {
        while(ptr->left!=NULL || ptr->right!=NULL)
        {
            if(new_node->data > ptr->data)
            {
                if(ptr->right!=NULL)
                {
                  ptr=ptr->right;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if(ptr->left!=NULL)
                {
                  ptr=ptr->left;
                }
                else
                {
                    break;
                }
            }
        }
        if(new_node->data > ptr->data)
        {
          ptr->right=new_node;
        }
        else
        {
            ptr->left=new_node;
        }
    }
}

void pre_order(struct node*ptr)
{
    struct node* trav=ptr;
    if(ptr!=NULL)
    {
        printf("%d",ptr->data);
        pre_order(ptr->left);
        pre_order(ptr->right);
    }
}

void inorder(struct node*ptr)
{
    struct node* trav=ptr;
    if(ptr!=NULL)
    {
        inorder(ptr->left);
        printf("%d",ptr->data);
        inorder(ptr->right);
    }
}

void post_order(struct node*ptr)
{
    struct node* trav=ptr;
    if(ptr!=NULL)
    {
        post_order(ptr->left);
        post_order(ptr->right);
        printf("%d",ptr->data);
    }
}


void main()
{
    printf("Enter\n 1.Create\n 2.Pre-order\n 3.In-order\n 4.post-order\n 5.EXIT\n");
    int ch;
    do{
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:create();
            break;
            case 2:pre_order(root);
            break;
            case 3:inorder(root);
            break;
            case 4:post_order(root);
            break;
        }
    }while(ch!=5);
}
