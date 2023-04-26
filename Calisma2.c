/* Calisma 2 - Yapilacaklar
1- Oncelikle asagida uygun yerlere birlestirmeli sıralama algoritmasini yaziniz. Algoritmanin dogru calistigindan emin olunuz.
2- Daha sonra iki farkli siralama algoritmasinin performansini farkli girdi boyutlari ile karsilastiriniz - Ornegin 100, 1000, 10000, 100000 sayi gibi.
3- Sonuclarinizi ve yazdiginiz kodu e-posta ile bana gonderebilirsiniz.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define ARRAYSIZE 100

void InsertionSort(int A[]);
void Merge(int A[], int p, int q, int r);
void MergeSort(int A[],int p, int r);

int main()
{
    int A1[ARRAYSIZE];
    int A2[ARRAYSIZE];
    int i;
    int num;
    time_t t;
    srand((unsigned) time(&t));
    for(i = 0; i < ARRAYSIZE; i++)
    {
        num = rand();
        A1[i] = num;
        A2[i] = num;
    }

    for(i = 0; i < ARRAYSIZE; i++)
    {
        printf("%d: %d\n", i+1, A2[i]);
    }

    clock_t start_t, end_t;
    double cpu_time_used;
    start_t = clock();
    InsertionSort(A1);
    end_t = clock();
    cpu_time_used = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Toplam gecen sure (Eklemeli Siralama): %f saniyedir.\n", cpu_time_used);

    start_t = clock();
    // MergeSort cagirilma seklini degistirebilirsiniz.
    MergeSort(A2,0,ARRAYSIZE-1);
    
    end_t = clock();
    cpu_time_used = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Toplam gecen sure (Birlestirmeli Siralama): %f saniyedir.\n", cpu_time_used);

    for(i = 0; i < ARRAYSIZE; i++)
    {
        printf("%d: %d\n", i+1, A2[i]);
    }

    return 0;
}

void InsertionSort(int A[])
{
    int i,j,key;
    for(j = 1; j < ARRAYSIZE; j++)
    {
        key = A[j];
        i = j - 1;
        while(i >= 0 && A[i] > key)
        {
            A[i+1] = A[i];
            i = i - 1;
        }
        A[i+1] = key;
    }
}

void Merge(int A[], int p, int q, int r)
{
	int i,j,k;
 	int n1 = q-p+1;
 	int n2 = r-q;
	int Right[n2],Left[n1];
	
	for(i=0;i<n1;i++){	
		Left[i] = A[p+i];
	}
	
	for(j=0;i<n2;j++){	
		Right[j] = A[q+j+1];
	}
	
	Left[n1] = INT_MAX;
	Right[n2] = INT_MAX;
	
	i = 0;
	j = 0;
	
	for(k=p;k<=r;k++){
		
		if(Left[i]<=Right[j]){
			A[k] = Left[i];
			i = i+ 1;
			
		}else{
			A[k] = Right[j];
			j = j+1;
		}
	
	}
}

void MergeSort(int A[],int p, int r)
{
	if(p<r){
		int m = (p+r)/2;
		MergeSort(A,p,m);
		MergeSort(A,m+1,r);
		
		Merge(A,p,m,r);
	}
}
