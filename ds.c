
#include <stdio.h>
#include <stdlib.h>
struct node
{
     int data;
     struct node* left;
     struct node* right;
};
 
struct node* newNode(int data)
{
     struct node* node = (struct node*)
                                  malloc(sizeof(struct node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;
 
     return(node);
}
 
void printPostorder(struct node* node)
{
     if (node == NULL)
        return;

     printPostorder(node->left);
     printPostorder(node->right);
     printf("%d ", node->data);
}
 
void printInorder(struct node* node)
{
     if (node == NULL)
          return;
 
     printInorder(node->left);
 
     printf("%d ", node->data);  
      printInorder(node->right);
}
 
void printPreorder(struct node* node)
{
     if (node == NULL)
          return;
 
     printf("%d ", node->data);  
 
     printPreorder(node->left);  

     printPreorder(node->right);
}    

int main()
{
     struct node *root  = newNode(1);
     root->left             = newNode(2);
     root->right           = newNode(3);
     root->left->left     = newNode(4);
     root->left->right   = newNode(5); 
 
     printf("\nPreorder traversal of binary tree is \n");
     printPreorder(root);
 
     printf("\nInorder traversal of binary tree is \n");
     printInorder(root);  
 
     printf("\nPostorder traversal of binary tree is \n");
     printPostorder(root);
 
     getchar();
     return 0;
}











#include <stdio.h>
 
int main()
{
   int c, first, last, middle, n, search, array[100];
 
   printf("Enter number of elements\n");
   scanf("%d",&n);
 
   printf("Enter %d integers\n", n);
 
   for (c = 0; c < n; c++)
      scanf("%d",&array[c]);
 
   printf("Enter value to find\n");
   scanf("%d", &search);
 
   first = 0;
   last = n - 1;
   middle = (first+last)/2;
 
   while (first <= last) {
      if (array[middle] < search)
         first = middle + 1;    
      else if (array[middle] == search) {
         printf("%d found at location %d.\n", search, middle+1);
         break;
      }
      else
         last = middle - 1;
 
      middle = (first + last)/2;
   }
   if (first > last)
      printf("Not found! %d isn't present in the list.\n", search);
 
   return 0;   
}





#include<stdlib.h>
#include<stdio.h>

struct bin_tree 
{
int data;
struct bin_tree * right, * left;
};
typedef struct bin_tree node;

void insert(node ** tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

void print_preorder(node * tree)
{
    if (tree)
    {
        printf("%d\n",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}

void print_inorder(node * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d\n",tree->data);
        print_inorder(tree->right);
    }
}

void print_postorder(node * tree)
{
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n",tree->data);
    }
}

void deltree(node * tree)
{
    if (tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

node* search(node ** tree, int val)
{
    if(!(*tree))
    {
        return NULL;
    }

    if(val < (*tree)->data)
    {
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->data)
    {
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->data)
    {
        return *tree;
    }
}

void main()
{
    node *root;
    node *tmp;


    root = NULL;
  
    insert(&root, 9);
    insert(&root, 4);
    insert(&root, 15);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 17);
    insert(&root, 2);

    printf("Pre Order Display\n");
    print_preorder(root);

    printf("In Order Display\n");
    print_inorder(root);

    printf("Post Order Display\n");
    print_postorder(root);

    tmp = search(&root, 4);
    if (tmp)
    {
        printf("Searched node=%d\n", tmp->data);
    }
    else
    {
        printf("Data Not found in tree.\n");
    }

    deltree(root);
}





#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void main()
{
    struct node
    {
    int num;
    struct node *ptr;
    };
    typedef struct node NODE;
    NODE *head,*first,*temp=0;
    int count=0;
    int choice=1;

    first=0;
    while(choice)
    {
    head=(NODE *)malloc(sizeof(NODE));
    printf("Enter the data item\n");
    scanf("%d",&head->num);
    if(first!=0)
    {
    temp->ptr=head;
    temp=head;
    }
    else
    {
    first=temp=head;
    }
    fflush(stdin);
    printf("Do you want to continue(Type 0 or 1)?\n");
    scanf("%d",&choice);
    }

    temp->ptr=0;
  

    temp=first;
    printf("\nStatus of the linked list\n");
    while(temp!=0)
    {
        printf("%d=> ",temp->num);
        count++;
        temp=temp->ptr;
    }
    
    printf("NULL\n");
    printf("No.of nodes in the list =%d\n",count);
    
}
