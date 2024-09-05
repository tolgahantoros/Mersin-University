#include<stdio.h>
void fonk(int, int, int [20], int [2][20]);
int main(){
	int x[20], a[2][20], n, i, j=0, rakam;
	printf("Dizi boyutunu giriniz (<=20): ");
	scanf("%d", &n);
	printf("Dizi elemanlarini giriniz: ");
	for(i=0; i<n; i++){
		scanf("%d", &x[i]);
	}
	for(i; i<20; i++){
		x[i]=0;
	}
	printf("Bir tamsayi degeri giriniz: ");
	scanf("%d", &rakam);
	fonk(n, rakam, x, a);
	printf("\n2-Boyutlu Dizi:\n");
	for(i=0; i<2; i++){
		for(j=0; j<20; j++){
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
}
void fonk(int n, int rakam, int x[20], int a[2][20]){
	int i, j;
	
	//Satýr 0
	j=0;
	for(i=0; i<n; i++){
		if(x[i]>rakam){
			a[0][j++]=x[i];
		}
	}
	for(j+1; j<20; j++){
		a[0][j]=0;
	}
	
	//Satýr 1
	j=0;
	for(i=0; i<n; i++){
		if(x[i]<=rakam){
			a[1][j++]=x[i];
		}
	}
	for(j+1; j<20; j++){
		a[1][j]=0;
	}
}
