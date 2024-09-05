#include<stdio.h>
int main(){
	int a[10][10], m, i, j;
	printf("m giriniz: ");
	scanf("%d", &m);
	printf("%dx%d dizi giriniz: " , m, m);
	for(i=0; i<m; i++){
		for(j=0; j<m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	printf("\nDizinin ilk hali:\n");
	for(i=0; i<m; i++){
		for(j=0; j<m; j++){
			printf("%-5d", a[i][j]);
		}
		printf("\n");
	}

	printf("\nDizinin yeni hali:\n");
	for(i=i-1; i>=0; i--){
		for(j=0; j<m; j++){
			printf("%-5d", a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
