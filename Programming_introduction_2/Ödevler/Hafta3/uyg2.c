#include<stdio.h>
int main(){
	int n, ogrNo[100], ogrNot[100], i, endusuk, endusukOgr, enyuksek, enyuksekOgr;
	printf("Ogrenci sayisini giriniz(1-100): ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		printf("Ogrencinin numarasini ve notunu giriniz: ");
		scanf("%d %d", &ogrNo[i], &ogrNot[i]);
	}
	
	endusuk = ogrNot[0];
	enyuksek = ogrNot[0];
	endusukOgr = ogrNo[0];
	enyuksekOgr = ogrNo[0];
	
	for(i=0; i<n; i++){
		if(ogrNot[i]<endusuk){
			endusuk = ogrNot[i];
			endusukOgr = ogrNo[i];
		}
	}
	for(i=0; i<n; i++){
		if(ogrNot[i]>enyuksek){
			enyuksek = ogrNot[i];
			enyuksekOgr = ogrNo[i];
		}
	}
	
	printf("\n%d numarali ogrenci en yuksek notu (%d) almistir.\n", enyuksekOgr, enyuksek);
	printf("%d numarali ogrenci en dusuk notu (%d) almistir.\n", endusukOgr, endusuk);
	
	
	return 0;
}
