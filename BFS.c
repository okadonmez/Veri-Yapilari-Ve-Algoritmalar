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

typedef struct Queue {
    int front; //isleme al
    int rear; //ekleme
    int numberOfElements; //siradaki eleman sayisi
    int capacity; //siranin maksimum buyuklugu
    node* array[NODE_NUMBER];
}Queue;

int graf[NODE_NUMBER][NODE_NUMBER] = {};
void AddEdge(int v1,int v2);
void ShowMatris();
void BFS(int start,int end);

Queue* createQueue(int size);
int isFull(Queue* queue);
int isEmpty(Queue* queue);
void enqueue(Queue* queue, node* item);
node* dequeue(Queue* queue);

void PrintSolution(node* n);
node* CreateNewNode(int a, node* p, int d,int path_cost);



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
    BFS(7,8);
	//BFS(0,9); //Test icin
	//BFS(0,1); //Test icin
	
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

void BFS(int start,int end)
{
	printf("\n\n<---BFS--->\n\n");

    int ziyaretedildimi[NODE_NUMBER] = {};
    int nDurum;
	int nEbeveyn;
    int nAksiyon;
    int j = 0;

    Queue* kuyruk = createQueue(NODE_NUMBER);
    node* startNode = CreateNewNode(-1, NULL, start, 0); //Aksiyonu ve ebeveyni -1 Cunku baslangic dugumu 
    
	enqueue(kuyruk, startNode);
    ziyaretedildimi[start] = 1;

    while (!isEmpty(kuyruk))
    {
        node* tempNode = dequeue(kuyruk);
        
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
		
        printf("Dugumun durumu: %d    Dugumun ebeveyni: %d    Dugumun aksiyonu: %d\n", nDurum, nEbeveyn, nAksiyon);

        if (nDurum == end)
        {
            printf("Hedef dugume ulasildi! Hedef dugumun durumu: %d\n", end);
            
            PrintSolution(tempNode);
            
			return;
        }

        for (j = 0; j < NODE_NUMBER; j++)
        {
            if (ziyaretedildimi[j] != 1 && graf[nDurum][j] == 1)
            {
                enqueue(kuyruk, CreateNewNode(1, tempNode, j, tempNode->path_cost + 1));
                
                ziyaretedildimi[j] = 1;
            }
        }
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

Queue* createQueue(int size)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = size;
    queue->front = 0;
    queue->numberOfElements = 0;
    queue->rear = 0;
    return queue;
}

int isFull(Queue* queue)
{
    return (queue->numberOfElements == queue->capacity);
}

int isEmpty(Queue* queue)
{
    return (queue->numberOfElements == 0);
}

void enqueue(Queue* queue, node* item)
{
    if (isFull(queue))
    {
        printf("Ekleme yapilamaz, sira dolu!\n");
        return;
    }
    queue->array[queue->rear] = item;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->numberOfElements = queue->numberOfElements + 1;
}

node* dequeue(Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("Sira bos! Program sonlandiriliyor!\n");
        exit(-1);
    }
    node* item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->numberOfElements = queue->numberOfElements - 1;
    return item;
}
