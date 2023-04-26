#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>

#define ARRAYSIZE 5
#define COUNTING 1000

void COUNTING_SORT(int A[], int B[], int k);

int main()
{
	int numbers[ARRAYSIZE];
	int sorted_numbers[ARRAYSIZE];
	int i,j;
	int num;
	time_t t;
	srand((unsigned) time(&t));
	for(i = 0; i < ARRAYSIZE; i++)
	{
		num = rand()%COUNTING;
		numbers[i] = num;
	}

	for(i = 0; i < ARRAYSIZE; i++)
		printf("%d: %d\n", i+1, numbers[i]);

	clock_t start, end;	
	double cpu_time_used;
     
	start = clock();
	COUNTING_SORT(numbers,sorted_numbers,COUNTING);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken by Counting Sort: %f sec\n", cpu_time_used);
	for(i = 0; i < ARRAYSIZE; i++)
		printf("%d: %d\n", i+1, sorted_numbers[i]);
	return 0;
}

void COUNTING_SORT(int A[], int B[], int k)
{
	int i,j;
	int C[k];
	
	for(i=0; i<k; i++){
		C[i]=0;
	}
	
	for(j=0; j<ARRAYSIZE; j++){
		C[A[j]]++;
	}
	
	for(i=1; i<k; i++){
		C[i]=C[i]+C[i-1];
	}
	
	for(j=ARRAYSIZE-1; j>=0; j--){
		B[C[A[j]]-1]=A[j];
		C[A[j]]--;
	}
}

