#include<stdio.h>
void yerdegis(int*, int*);
void hesapla(int, int, float*);

int main(){
	float opt=0;
	int sayi1, sayi2;
	printf("Aralik giriniz: ");
	scanf("%d%d", &sayi1, &sayi2);
	if(sayi1>sayi2){
		yerdegis(&sayi1, &sayi2);
	}
	hesapla(sayi1, sayi2, &opt);
	
	printf("Ortalama: %.2f", opt);
	return 0;
}

void yerdegis(int *sayi1, int *sayi2){
	int temp;
	temp=*sayi1;
	*sayi1=*sayi2;
	*sayi2=temp;
}

void hesapla(int sayi1, int sayi2, float *opt){
	int adet=0;
	for(sayi1; sayi1<=sayi2; sayi1++){
		if(sayi1%2==0 && sayi1!=0){
			*opt+=sayi1;
			adet++;
		}
	}
	*opt/=adet;
}
