#include<stdio.h>
int main(){
	int a[100], n, i;
	printf("Kac sayi girmek istiyorsunuz (1-100): ");
	scanf("%d", &n);
	printf("%d adet pozitif tamsayi giriniz: ", n);
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	printf("Tek sayilar:");
	for(i=0; i<n; i++){
		if(a[i]%2==1){
			printf(" %d", a[i]);
		}
	}
	printf("\nCift sayilar:");
	for(i=0; i<n; i++){
		if(a[i]%2==0){
			printf(" %d", a[i]);
		}
	}
	
	return 0;
}
