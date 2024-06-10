#include<stdio.h>
#include<stdlib.h>
struct node{
	int key;
	struct node*left;
	struct node*right;
	int height;
};
int getheight(struct node*n){
	if(n == NULL)
	return 0;
	return n->height;
}

struct node*createnode(int key){
	struct node* node=(struct node*)malloc(sizeof(struct node));
	node->key=key;
	node->left=NULL;
	node->right=NULL;
	node->height=NULL;
	return node;
}
int getbalancefactor(struct node*n){
	if(n==NULL){
	return 0;
}
return getheight(n->left) - getheight(n->right);
}
struct node* leftrotate(struct node*x){
	struct node*y=x->right;
	struct node*t2=y->left;
	y->left=x;
	x->right=t2;
	x->height=max(getheight(x->right),getheight(x->left))+1;
	y->height=max(getheight(y->right),getheight(y->left))+1;
	return y;
}
int main() 
{ 
  struct Node *root = NULL; 
  root = insert(root, 10); 
  root = insert(root, 20); 
  root = insert(root, 30); 
  root = insert(root, 40); 
  root = insert(root, 50); 
  root = insert(root, 25); 
   printf("Preorder traversal of the constructed AVL tree is \n"); 
  preOrder(root); 
  return 0; 
} 
