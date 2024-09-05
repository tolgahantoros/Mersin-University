#include<stdio.h>
void banknot(int, int*, int*, int*, int*, int*);
int main(){
	int tutar=0, yuzluk=0, ellilik=0, yirmilik=0, onluk=0, beslik=0;
	do{
		printf("Tutar Giriniz: ");
		scanf("%d", &tutar);
		if(tutar%5!=0){
			printf("Lutfen 5'in kati bir tutar girininiz.\n");
		}
	}while(tutar%5!=0);
	banknot(tutar, &yuzluk, &ellilik, &yirmilik, &onluk, &beslik);
	printf("%d adet yuzluk\n%d adet ellilik\n%d adet yirmilik\n%d adet onluk\n%d adet beslik\nToplam: %dTL", yuzluk, ellilik, yirmilik, onluk, beslik, tutar);
	
	return 0;
}
void banknot(int tutar, int *yuzluk, int *ellilik, int *yirmilik, int *onluk, int *beslik){
	*yuzluk=tutar/100;
	tutar=tutar%100;
	
	*ellilik=tutar/50;
	tutar=tutar%50;
	
	*yirmilik=tutar/20;
	tutar=tutar%20;
	
	*onluk=tutar/10;
	tutar=tutar%10;
	
	*beslik=tutar/5;
}
