#include<stdio.h>
#define M 2
#define N 3
#define P 2


int main(){
	int a[10][10];
	int b[10][10];
	int c[10][10];
	int i, j, k;
	printf("Birinci Matris (MxN):\n");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			printf("matris1[%d][%d]: ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	printf("\nIkinci Matris (NxP):\n");
	for(i=0; i<N; i++){
		for(j=0; j<P; j++){
			printf("matris2[%d][%d]: ", i, j);
			scanf("%d", &b[i][j]);
		}
	}
	
	printf("\nMatris Gosterimi 1:\n");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
	printf("\nMatris Gosterimi 2:\n");
	for(i=0; i<N; i++){
		for(j=0; j<P; j++){
			printf("%5d", b[i][j]);
		}
		printf("\n");
	}
	
	printf("\nSonuc Matrisi:\n");
	for(i=0; i<M; i++){
		for(k=0; k<P; k++){
			c[i][k]=0;
			for(j=0; j<N; j++){
				c[i][k] += (a[i][j]*b[j][k]);
			}
			printf("%5d", c[i][k]);
		}
		printf("\n");
	}
	
	
	return 0;
}
