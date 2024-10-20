#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *new(int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
    else
        return;
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
    else
        return;
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
    else
        return;
}
struct node *insert(struct node *node, int x)
{
    if (node == NULL)
    {
        return new (x);
    }
    else if (x < node->data)
    {
        node->left = insert(node->left, x);
    }
    else if (x > node->data)
    {
        node->right = insert(node->right, x);
    }
    return node;
}
int search(struct node *root,int key)
{
    if(root==NULL)
        return 0;
    else if(root->data==key)
        return 1;
    else if(root->data>key)
        return search(root->left,key);
    else if(root->data)
        return search(root->right,key);
}
void main()
{  
    int val,key;
    struct node *root = NULL;
    int a[50], i, n;
    printf("enter size of elements\n");
    scanf("%d", &n);
    printf("enter elements into tree\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    root = insert(root, a[0]);
    for (i = 1; i < n; i++)
    {
        insert(root, a[i]);
    }
    printf("\ninorder traversal of binary tree\n");
    inorder(root);
    printf("\npreorder traversal of binary tree\n");
    preorder(root);
    printf("\npostorder traversal of binary tree\n");
    postorder(root);
    printf("enter element to search\n");
    scanf("%d",&key);
    val=search(root,key);
    if(val)
        printf("search successful\n");
    else
        printf("search unsuccessful\n");

}