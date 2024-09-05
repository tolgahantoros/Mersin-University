#include<stdio.h>
int main(){
	int a[10][10], n, i, j;
	printf("Kare matrisin boyutu: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(i==j || i+j+1==n){
				a[i][j]=1;
			}
			else{
				a[i][j]=0;
			}
		}
	}
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%2d", a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
