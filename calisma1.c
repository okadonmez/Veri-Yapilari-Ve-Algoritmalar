/* Yapılacaklar: Eklemeli sıralama fonksiyonun içeriğini doldurunuz ve
örnek sayı dizilerini sıralayıp çalıştığını gösteriniz.*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<time.h>

#define ARRAYSIZE 100

void InsertionSort(int A[]);

int main()
{
	int numbers1[ARRAYSIZE];
	int i,j;
	
	//Rastgele sayı oluşturmayı aşağıdaki şekilde yapabiliriz.
	time_t t; // zaman değişkeni oluştur
	srand((unsigned) time(&t)); // Rastgele sayı oluşturucuyu bilgisayarın saati ile eşle

	for(i = 0; i < ARRAYSIZE; i++)
	{
		numbers1[i] = rand(); // 0 ile max int arası sayı oluştur.
	}
	for(i = 0; i < ARRAYSIZE; i++)
		printf("%d:\t%d\n",i+1,numbers1[i]);

	InsertionSort(numbers1);

	printf("********************SIRALAMA SONRASI****************************\n");
     
	for(i = 0; i < ARRAYSIZE; i++)
		printf("%d:\t%d\n",i+1,numbers1[i]);
	return 0;
}

// Algoritmanın içini doldurunuz
void InsertionSort(int A[]){
   
   int j,i;
   int key;
   
   for(j=1; j<ARRAYSIZE; j++){
       
	   key = A[j];
       i = j-1;
   	
	   while(i>=0 && A[i]>key){	
		   A[i+1]=A[i];
	   	   i = i-1;
	   }
   
       A[i+1] = key;
   }
}
