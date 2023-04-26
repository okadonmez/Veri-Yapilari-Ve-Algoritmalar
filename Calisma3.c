/* Calisma 3 - Yapiacaklar
1. Asagidaki dosyada subArray yapisini kullanarak maksimum altdizi problemini asagidaki fonksiyonlari kullanarak cozunuz.
- Kaba kuvvet ile (BruteFore fonksiyonu)
- Bol ve yonet yontemi ile (FIND_MAX_CROSSING_SUBARRAY, FIND_MAXIMUM_SUBARRAY fonksiyonlari ile)
2. Daha sonra iki farkli yontemi farkli girdi boyutlari ile karsilastiriniz. */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define ARRAYSIZE 365 // toplam fiyat sayisi

typedef struct subArray // baslangic, bitis ve toplam deger bilgisini bir arada tutmak icin kullandigimiz yapi
{
    int maxBasla;
    int maxSon;
    int maxToplam;
}subArray;

subArray FIND_MAX_CROSSING_SUBARRAY(int A[], int low, int mid, int high);
subArray FIND_MAXIMUM_SUBARRAY(int A[], int low, int high);
subArray BruteForce(int A[]);

int main()
{
    int i;
    int fiyatlar[ARRAYSIZE];
    int degisim[ARRAYSIZE];
    time_t t;
    srand((unsigned) time(&t));
    for(i = 0; i < ARRAYSIZE; i++)
    {
        fiyatlar[i] = (rand() % 120) + 1; // fiyatlari olusturalim
    }
    for(i = 1; i < ARRAYSIZE; i++)
    {
        degisim[i] = fiyatlar[i] - fiyatlar[i-1]; // fiyat degisimlerini hesaplayalim
    }
    subArray res = FIND_MAXIMUM_SUBARRAY(degisim,1,ARRAYSIZE-1); // bol ve yonet yontemi
    for(i = 0; i < ARRAYSIZE; i++)
    {
        printf("%d: %d\n", i, fiyatlar[i]);
    }
    printf("Al: %d\n", res.maxBasla - 1); // bulunan degerleri yazdiralim
    printf("Sat: %d\n", res.maxSon);
    printf("Kar: %d\n", res.maxToplam);

    subArray res2 = BruteForce(fiyatlar); // bulunan degerleri yazdiralim
    printf("Al: %d\n", res2.maxBasla);
    printf("Sat: %d\n", res2.maxSon);
    printf("Kar: %d\n", res2.maxToplam);
    
	return 0;
}

subArray BruteForce(int A[])
{
    subArray res;
    
	int i, j;
	int buyuk=0, kucuk=120;
	
	for(i=0; i<ARRAYSIZE; i++){
		
		if(buyuk<=A[i]){
			buyuk = A[i];
		}
		
		if(kucuk>=A[i]){
			kucuk = A[i];
		}
		
		for(j=i+1; j<ARRAYSIZE; j++){
			
			if(A[j] >= buyuk){
				
				buyuk = A[j];
			}
		
			if(A[j] <= kucuk){
				kucuk = A[j];
			}
		}
	}
	printf("\n\n\nbuyuk   %d\n",buyuk);
	printf("kucuk   %d\n",kucuk);
	printf("fark   %d\n\n\n",buyuk-kucuk);
	
	res.maxBasla = kucuk;
	res.maxSon = buyuk;
	res.maxToplam = buyuk-kucuk;
	
	return res;
}

subArray FIND_MAX_CROSSING_SUBARRAY(int A[], int low, int mid, int high)
{
    subArray res;
    
    int left_sum = INT_MIN;
    int right_sum;
    int max_left;
    int max_right;
    int sum = 0;
    int i, j;
    
    for(i = mid; i<low; i++){
    	
    	sum = sum + A[i];
    	
    	if(sum>left_sum){
    		left_sum = sum;
    		max_left = i;
		}
	}
    
    right_sum = INT_MIN;
    sum = 0;
    
    for(j=mid+1; j<high;j++){
    	sum = sum + A[j];
    	
    	if(sum>right_sum){
    		right_sum = sum;
    		max_right = j;
		}
	}
	
	res.maxBasla = max_left;
    res.maxSon = max_right;
    res.maxToplam = left_sum+right_sum;
	
    return res;
}

subArray FIND_MAXIMUM_SUBARRAY(int A[], int low, int high)
{
    subArray res, res1, res2, res3;
    int mid;
    
    if(high==low){
    	
    		res.maxBasla = low;
			res.maxSon = high;
			res.maxToplam = A[low];
    	
    	return res;
	}else{
		mid = (low+high)/2;
		
		
		res1 = FIND_MAXIMUM_SUBARRAY(A,low,mid);
		
		res2 = FIND_MAXIMUM_SUBARRAY(A,mid+1,high);
		
		res3 = FIND_MAXIMUM_SUBARRAY(A,low,high);
		
		if(res1.maxToplam >= res2.maxToplam && res1.maxToplam >= res3.maxToplam){
			return res1;
		}else if(res2.maxToplam >= res1.maxToplam && res2.maxToplam >= res3.maxToplam){
			return res2;
		}else{
			return res3;
		}
	}
    
    return res;
}
