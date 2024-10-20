#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *left;
        struct node *right;
};
struct node *newnode(int x)
{
        struct node *new;
        new=(struct node *)malloc(sizeof(struct node));
        new->data=x;
        new->left=NULL;
        new->right=NULL;
        return new;
}
struct node * create(int x,struct node *r)
{
        if(r==NULL)
                return newnode(x);
        else if(x<r->data)
               r->left=create(x,r->left);
        else if(x>r->data)
               r->right=create(x,r->right);
        return r;
}
void inorder(struct node *r)
{
        
        if(r!=NULL)
        {
                inorder(r->left);
                printf("%d ",r->data);
                inorder(r->right);
        }
}
void preorder(struct node *r)
{
        

        if(r!=NULL)
        {
                printf("%d ",r->data);
                preorder(r->left);
                preorder(r->right);
        }
}
void postorder(struct node *r)
{
       

        if(r!=NULL)
        {
                postorder(r->left);
                postorder(r->right);
                printf("%d ",r->data);
        }
}
main()
{
        int n,x;
        struct node *root=NULL;
        while(1)
        {
                printf("enter\n1 to create BST\n2 to display\n3 to exit\n");
                scanf("%d",&n);
                switch(n)
                {
                case 1:
                        printf("enter the element\n");
                        scanf("%d",&x);
                        root=create(x,root);
                        break;
                case 2: printf("\nresult of preoder traversal is:\n");
                        inorder(root);
                        printf("\nresult of preoder traversal is:\n");
                        preorder(root);
                        printf("\nresult of preoder traversal is:\n");
                        postorder(root);
                        printf("\n");
                        break;
                case 3:exit(0);
                default:printf("enter valid choice\n");
                        break;
             }
        }
}