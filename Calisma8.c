#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>

struct node
{
	int key;
	struct node* left;
	struct node* right;
	struct node* p;
};

struct node *root;

void TreeInsert(struct node *z);
void InOrderTreeWalk(struct node *x);
struct node* TreeSearch(struct node *x, int k);
struct node* TreeMinimum(struct node *x);
struct node* TreeMaximum(struct node *x);
struct node* TreeSuccessor(struct node *x);
void Transplant(struct node *x, struct node *v);
void TreeDelete(struct node *z);

struct node* CreateNewNode(int key);

int main()
{
	struct node* node1 = CreateNewNode(5);
	TreeInsert(node1);
	
	struct node* node2 = CreateNewNode(12);
	TreeInsert(node2);
	
	struct node* node3 = CreateNewNode(7);
	TreeInsert(node3);
	
	struct node* node4 = CreateNewNode(8);
	TreeInsert(node4);
	
	InOrderTreeWalk(root);
	
	struct node* maxnode = TreeMaximum(root);
	printf("\n%d",maxnode->key);
	
	struct node* minnode = TreeMinimum(root);
	printf("\n%d",minnode->key);
	
	struct node* sevennode = TreeSearch(root,7);
	
	printf("\n%d",sevennode->key);
	
	TreeDelete(sevennode);
	
	InOrderTreeWalk(root);
	
	return 0;
}
 
void TreeDelete(struct node *z)
{
	if(z->left == NULL)
		Transplant(z,z->right);
	else if(z->right == NULL)
		Transplant(z,z->left);
	else
	{
		struct node *y = TreeMinimum(z->right);
		if(y->p != z)
		{
			Transplant(y,y->right);
			y->right = z->right;
			y->right->p = y;
		}
		Transplant(z,y);
		y->left = z->left;
		y->left->p = y;
	}
	
	printf("\n\n%d numara silindi\n\n",z->key);
}

void Transplant(struct node *u, struct node *v)
{
	if(u->p == NULL)
		root = v;
	else if(u == u->p->left)
		u->p->left = v;
	else
		u->p->right = v;
	if(v != NULL)
		v->p = u->p;
}

struct node* TreeSuccessor(struct node *x)
{
	if(x->right != NULL)
		return TreeMinimum(x->right);
	struct node* y = x->p;
	while(y != NULL && x == y->right)
	{
		x = y;
		y = y->p;
	}
	return y;
}

struct node* TreeMinimum(struct node *x)
{
	while(x->left != NULL){
	
		x = x->left;
	}
	
	return x;
}

struct node* TreeMaximum(struct node *x)
{
	while(x->right != NULL){
	
		x = x->right;
	}

	return x;
}

struct node* TreeSearch(struct node *x, int k)
{
	if(x == NULL || k == x->key)
	{
		return x;
	}
	if(k < x->key)
		return TreeSearch(x->left,k);
	else
		return TreeSearch(x->right,k);
}

void InOrderTreeWalk(struct node *x)
{
	//sol için çaðýr deðeri yazdýr sonra sað için çaðýr deðer yazdýr

	if(x!=NULL){
		InOrderTreeWalk(x->left);
		printf("%d\n",x->key);
		InOrderTreeWalk(x->right);
	}
}

void TreeInsert(struct node *z)
{
	struct node *y = NULL;
	struct node *x = root;
	while(x != NULL)
	{
		y = x;
		if(z->key < x->key)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	z->p = y;
	if(y == NULL)
	{
		root = z;
	}
	else if(z->key < y->key)
	{
		y->left = z;
	}
	else
	{
		y->right = z;
	}
}

struct node* CreateNewNode(int key)
{
	struct node *newNode = malloc(sizeof(struct node));
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->p = NULL;
	return newNode;
}

