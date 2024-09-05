#include<stdio.h>
void fonk(int, int*, int tekSayilar[100], int a[10][10]);
int main(){
	int a[10][10], tekSayilar[100];
	int n, i, j, n2=0;
	printf("Kare matrisin boyutunu giriniz (n<=10):");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("matris[%d][%d]: ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	
	fonk(n, &n2, tekSayilar, a);
	
	printf("\nTek sayilar dizisi:");
	for(i=0; i<n2; i++){
		printf(" %d ", tekSayilar[i]);
	}
	
	return 0;
}

void fonk(int n, int *n2, int tekSayilar[100], int a[10][10]){
	int i, j, k=0;
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(a[i][j]%2!=0){
				tekSayilar[k++]=a[i][j];
			}
		}
	}
	*n2=k;
}
