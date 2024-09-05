#include<stdio.h>
int main(){
	int a[30], b[30], n, i, j=0, buyuk;
	printf("n degerini giriniz (n < 30): ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		printf("a[%d]: ", i);
		scanf("%d", &a[i]);
	}
	for(i=0; i<n; i++){
		if(a[i]>=a[i+1]){
			b[j++]=a[i];
		}
		else{
			b[j++]=a[i+1];
		}
	}
	printf("\n");
	for(i=0; i<j-1; i++){
		printf("b[%d]: %d\n", i, b[i]);		
	}
	
	return 0;
}
