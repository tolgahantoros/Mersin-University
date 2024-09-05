#include<stdio.h>
int main(){
	int i, j;
	double a[5][2], ort=0.0;
	printf("5x2'lik dizinin elemanlari:\n");
	for(i=0; i<5; i++){
		for(j=0; j<2; j++){
			printf("a[%d][%d]: ", i, j);
			scanf("%lf", &a[i][j]);
		}
	}
	printf("\nDizi gosterimi:\n");
	for(i=0; i<5; i++){
		for(j=0; j<2; j++){
			printf("%5.1lf", a[i][j]);
		}
		printf("\n");
	}
	printf("\nSatir Ortalamalari:\n");
	for(i=0; i<5; i++){
		ort=0.0;
		for(j=0; j<2; j++){
			ort+=(a[i][j]);
		}
		printf(" satir %d: %5.1lf\n", i, ort/2);
	}
	printf("\nSutun Ortalamalari:\n");
	for(j=0; j<2; j++){
		ort=0.0;
		for(i=0; i<5; i++){
			ort+=(a[i][j]);
		}
		printf(" sutun %d: %5.1lf\n", j, ort/5);
	}
	
	return 0;
}
