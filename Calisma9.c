#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TABLE_SIZE 10

typedef struct node
{
    int data;
    struct node *next;
}node;

node **head;//iki boyutlu isaretci

void SetTable();//cagirilacak ilk
int HashSelect(int key);
int HashBolme(int key);
int HashCarpma(int key);
void HashInsert(int key);
void HashDelete(int key);
int HashSearch(int key);
void display();

int main()
{
	
	SetTable();
	HashInsert(7);
	HashInsert(17);
	HashInsert(27);
	HashInsert(3);
	HashInsert(87);
	HashInsert(47);
	HashInsert(5);
	HashInsert(15);
	HashInsert(25);
	HashInsert(117);
	HashInsert(35);
	HashInsert(12);
	HashInsert(127);
	HashInsert(67);
	HashInsert(32);
	HashInsert(12);
	HashInsert(24);
	display();
	
    return 0;
}

void SetTable()
{
    int i;
    head = (node**)malloc(sizeof(node*)*TABLE_SIZE);
    for(i = 0; i < TABLE_SIZE;i++)
    {
        head[i] = NULL;
    }
}

node* CreateNewNode(int key)
{
    node * newnode=(node *)malloc(sizeof(node));
    newnode->data=key;
    newnode->next = NULL;
    return newnode;
}

int HashBolme(int key)
{
	//k mod m(m tablo buyukluðu)
	
	return key % TABLE_SIZE;
}

int HashCarpma(int key)
{
	//floor()
	
	// L m (kA-[kA]) 
	
	float A = (sqrt(5)-1) / 2;
	
	return floor(TABLE_SIZE*(key*A-floor(key*A)));
}

int HashSelect(int key)
{
	return HashBolme(key);
}

void HashInsert(int key)
{
    int pos;
    pos=HashSelect(key);
    node * newnode=CreateNewNode(key);
    if(head[pos] == NULL)
    {
        head[pos] = newnode;
    }
    else
    {
        newnode->next = head[pos];
        head[pos] = newnode;
    }
}

void HashDelete(int key)
{
    int pos;
    pos=HashSelect(key);
    node* c=head[pos];
    if(c == NULL)
        return;
    else if(c->data == key)
    {
        if(c->next != NULL)
            head[pos] = c->next;
        else
            head[pos] = NULL;
        free(c);
    }
    else
    {
        while(c->next != NULL && c->next->data != key)
            c = c->next;
        if(c->next != NULL)
        {
            node *t = c->next;
            c->next = c->next->next;
            free(t);
        }
    }
}

int HashSearch(int key)
{
    int pos;
    node *c;
    pos = HashSelect(key);
    if(head[pos] == NULL)
        return -1;
    else
    {
        for(c=head[pos];c!=NULL;c=c->next)
        {
            if(c->data == key)
            {
                return pos;
            }
        }
        return -1;

    }
}

void display()
{
    printf("\n\nDisplay starts///////////////\n");
    int i;
    for(i=0;i<TABLE_SIZE;i++)
    {
        printf("\nentries at index %d\n",i);
        if(head[i] == NULL)
        {
            printf("No Hash Entry");

        }
        else
        {
            node* c;
            for(c=head[i];c!=NULL;c=c->next)
                printf("%d->",c->data);
        }
    }
    printf("\n\nDisplay ends////////////////\n");

}
