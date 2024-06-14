#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};
struct node * newNode(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node *));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
};
struct node * insert(struct node *my_node,int data)
{
    if(my_node == NULL)
        return newNode(data);
    else
    {
        if(data<my_node->data)
            my_node->left = insert(my_node->left,data);
        else
            my_node->right = insert(my_node->right,data);
        return my_node;
    }
};

int find_min(struct node *my_node)
{
    if(my_node->left == NULL)
        return my_node->data;
    else
        return find_min(my_node->left);
}
int find_max(struct node *my_node)
{
    if(my_node->right == NULL)
        return my_node->data;
    else
        return find_min(my_node->right);
}
int max_value(int a,int b)
{
    if(a>b) return a;
     return b;
}
int height(struct node *my_node)
{
    if(my_node== NULL) return 0;
    else
    return max_value(height(my_node->left),height(my_node->right))+1;
}

struct node* my_remove(struct node* my_node,int data)
{
    if(my_node==NULL)
        return NULL;
    else
    {
        if(data == my_node->data)
        {
            if(my_node->left == NULL && my_node->right == NULL)
                my_node= NULL;
            else if(my_node->left == NULL)
            {
                struct node * temp = my_node;
                my_node = my_node->right;
                temp->right = NULL;
                free(temp);
            }
            else if(my_node->right == NULL)
            {
                struct node *temp = my_node;
                my_node = my_node->left;
                temp->left = NULL;
                free(temp);
            }
            else
            {
                int value = find_min(my_node->right);
                my_node->data = value;
                my_node->right = my_remove(my_node->right,value);
            }
        }
        else if(data>my_node->data)
            my_node->right = my_remove(my_node->right,data);
        else
            my_node->left = my_remove(my_node->left,data);
        return my_node;
    }
}



int my_search(struct node* my_node,int data)
{
    if(my_node==NULL)
        return 0;
    else if(my_node->data == data)
        return 1;
    else
    {
        if(data>my_node->data)
            return my_search(my_node->right,data);
        else
            return my_search(my_node->left,data);
    }
}
void inorder_traversal(struct node *my_node)
{
    if(my_node == NULL) return;
    inorder_traversal(my_node->left);
    printf("%d ",my_node->data);
    inorder_traversal(my_node->right);
}
void pre_traversal(struct node *my_node)
{
    if(my_node == NULL) return;
    printf("%d ",my_node->data);
    inorder_traversal(my_node->left);
    inorder_traversal(my_node->right);
}
void post_traversal(struct node *my_node)
{
    if(my_node == NULL) return;
    inorder_traversal(my_node->left);
    inorder_traversal(my_node->right);
    printf("%d ",my_node->data);
}
int main()
{
    struct node *root = NULL;
    while(1)
    {
        int option;
        printf("Choose operation:\n1)insert\n2)my_remove\n3)height\n4)my_search\n5)min\n6)max\n7)inorder\n8)preorder\n9)postorder\n10)exit\nEnter option:");
        scanf("%d",&option);
        if(option==1)
        {
            int value;
            printf("Enter value :");
            scanf("%d",&value);
            root = insert(root,value);
        }
        else if(option==2)
        {
             int value;
            printf("Enter value :");
            scanf("%d",&value);
            root = my_remove(root,value);
        }
        else if(option==3)
        {
            printf("Height : %d\n",height(root));
        }
        else if(option==4)
        {
             int value;
            printf("Enter value :");
            scanf("%d",&value);
            int result = my_search(root,value);
            if(result==0)
                printf("my_search result : not found!\n");
            else
                printf("my_search result : element found!\n");
        }
        else if(option == 5)
        {
            printf("Min Value : %d\n",find_min(root));
        }
        else if(option == 6)
            printf("Max Value : %d\n",find_max(root));
        else if(option==7)
           {

                printf("Elements : ");
            inorder_traversal(root);
            printf("\n");
           }
        else if(option==8)
        {
             printf("Elements : ");
            pre_traversal(root);
            printf("\n");
        }
        else if(option == 9)
        {
             printf("Elements : ");
            post_traversal(root);
            printf("\n");
        }
        else
         break;
    }
    return 0;
}
