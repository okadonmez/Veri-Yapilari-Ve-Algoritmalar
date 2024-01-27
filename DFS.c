#include <stdio.h>
#include <stdlib.h>

#define NODE_NUMBER 10

typedef struct node
{
    int action;
    struct node* parent;
    int durum;
    int path_cost;
}node;

typedef struct stack
{
    int capacity;
    int top;
    node* items[NODE_NUMBER];
}stack;

stack* NewStack(int size);
int StackEmpty(stack* pt);
int StackFull(stack* pt);
void Push(node* element, stack* pt);
node* Pop(stack* pt);

int graf[NODE_NUMBER][NODE_NUMBER] = {};
void AddEdge(int v1,int v2);
void ShowMatris();
void DFS(int start,int end);

node* CreateNewNode(int a, node* p, int d,int path_cost);
void PrintSolution(node* n);

int main()
{
    AddEdge(0,1);
    AddEdge(0,2);
    AddEdge(0,3);
    AddEdge(1,4);
    AddEdge(2,5);
    AddEdge(2,6);
    AddEdge(3,7);
    AddEdge(4,8);
    AddEdge(5,9);
    ShowMatris();
    DFS(4,7);
    return 0;
}

void AddEdge(int v1,int v2)
{
    graf[v1][v2] = 1;
    graf[v2][v1] = 1;
}

void ShowMatris()
{
    int i,j;
    for(i = 0; i < NODE_NUMBER; i++)
    {
        for(j = 0; j < NODE_NUMBER; j++)
        {
            printf("%d ",graf[i][j]);
        }
        printf("\n");
    }
}

void DFS(int start,int end)
{
	printf("\n\n<---DFS--->\n\n");
	
	int ziyaretedildimi[NODE_NUMBER] = {};
	int nDurum;
	int nEbeveyn;
    int nAksiyon;
    int j = 0;
    
	stack* yigin = NewStack(NODE_NUMBER);
	node* startNode = CreateNewNode(-1, NULL, start, 0); //Aksiyonu ve ebeveyni -1 Cunku baslangic dugumu 

	Push(startNode, yigin);
    ziyaretedildimi[start] = 1;
    
    while (!StackEmpty(yigin))
    {
    	node* tempNode = Pop(yigin);
    	
    	nDurum = tempNode->durum;
    	
    	if(tempNode->parent != NULL) //Ebeveyni varsa esitle
		{
			nEbeveyn = tempNode->parent->durum;
		}
		else //Yoksa (start dugumu bu durumda) -1 ver
		{
			nEbeveyn = -1;
		}
		
		nAksiyon = tempNode->action;
		
    	printf("Pop -> Dugumun durumu: %d    Dugumun ebeveyni: %d    Dugumun aksiyonu: %d\n", nDurum, nEbeveyn, nAksiyon);
    	
    	if (nDurum == end)
        {
            printf("Hedef dugume ulasildi! Hedef dugumun durumu: %d\n", end);
            
            PrintSolution(tempNode);
            
			return;
        }
        
        /*Bu for dongusu DFS'da daima sinirdaki dugumler arasinda 
		en yuksek derinlige sahip dugumu acar*/
    	for(j = NODE_NUMBER-1; j >= 0; j--)
        {
            if(!ziyaretedildimi[j] && graf[nDurum][j] == 1)
            {
                Push(CreateNewNode(1, tempNode, j, tempNode->path_cost + 1), yigin);
                printf("Push-> %d\n", j);
                
                ziyaretedildimi[j] = 1;
            }
        }
        
        printf("\n");
    }
    
    printf("Hedef dugume ulasilamadi!\n");
}

node* CreateNewNode(int a, node* p, int d,int path_cost)
{
    node* newNode = malloc(sizeof(node));
    newNode->action = a;
    newNode->parent = p;
    newNode->durum = d;
    newNode->path_cost = path_cost;
    return newNode;
}

void PrintSolution(node* n)
{
    printf("Yol maliyeti: %d\n",n->path_cost);
    printf("Yol: ");
    while(n != NULL)
    {
        printf("%d ",n->durum);
        n = n->parent;
    }
}

stack* NewStack(int size)
{
	struct stack *pt = (stack*)malloc(sizeof(stack));

	pt->capacity = size;
	pt->top = -1;

	return pt;
}

int StackEmpty(stack *pt)
{
	return (pt->top == -1);
}

int StackFull(stack *pt)
{
    return (pt->top == pt->capacity-1);
}

void Push(node* element, stack* pt)
{
    if(StackFull(pt))
    {
        printf("Stack doldu! Yeni eleman eklenemez!\n");
    }
    else
    {
        pt->top++;
        pt->items[pt->top] = element;
    }
}

node* Pop(stack* pt)
{
    if(StackEmpty(pt))
    {
        printf("Stack bos!\n");
        exit(-1);
    }
    else
    {
        pt->top--;
        return pt->items[pt->top+1];
    }
}
