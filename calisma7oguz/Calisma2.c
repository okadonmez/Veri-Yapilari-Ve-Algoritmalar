#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int capacity;
    int top;
    int* items;
}stack;

stack* NewStack(int size);
int StackEmpty(stack* pt);
int StackFull(stack* pt);
void Push(int element, stack* pt);//ekleme
int Pop(stack* pt);//alma

int main()
{
	stack* yigin = NewStack(5);
	
	Push(10,yigin);
	Push(20,yigin);
	Push(30,yigin);
	Push(40,yigin);
	
	Pop(yigin);
	Pop(yigin);
	Pop(yigin);
	
	Push(10,yigin);
	Push(20,yigin);
	Push(30,yigin);
	Push(50,yigin);
	
	Pop(yigin);
	Pop(yigin);
	
	return 0;
}

stack* NewStack(int size)
{
	stack *pt = (stack*)malloc(sizeof(stack));

	pt->capacity = size;
	pt->top = -1;
	pt->items = (int*)malloc(sizeof(int) * size);

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

void Push(int element, stack* pt)
{
    if(StackFull(pt))
    {
        printf("Stack doldu! Yeni eleman eklenemez!\n");
    }
    else
    {
        pt->top++;
        pt->items[pt->top] = element;
        printf("%d elemani eklendi\n",element);
    }
}

int Pop(stack* pt)
{
    if(StackEmpty(pt))
    {
        printf("Stack bos!\n");
        exit(-1);
    }
    else
    {
        pt->top--;
        printf("%d elemani siliniyor.\n",pt->items[pt->top+1]);
        return pt->items[pt->top+1];
    }
}


