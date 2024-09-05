#include<stdio.h>
#include<string.h>

typedef struct{
	char liseAdi[50];
	int sinif;
	char sube;
}Lise;
typedef struct{
	char uniAdi[50];
	char fakulte[20];
	char bolum[50];
	int yil;
}Universite;

typedef struct{
	char isim[20];
	char soyisim[20];
	int yas;
	char cepNo[15];
	char sehir[10];
	char atolye[20];
	char ogrencitipi;
	union Okul{
		Lise liseli;
		Universite universiteli;
	};
	
}FestKayit;


int main(){
	int i=0, universiteligirildimi=0;
	char devam;
	FestKayit ogr[20];
	
	do{
		printf("Ogrenci[%d]\n", i+1);
		printf("Ad ve Soyad: ");
		scanf("%s %s", ogr[i].isim, ogr[i].soyisim);
		printf("Yas: ");
		scanf("%d", &ogr[i].yas);
		printf("Cep Telefonu: ");
		scanf("%s", ogr[i].cepNo);
		printf("Sehir: ");
		scanf("%s", ogr[i].sehir);
		printf("Atolye: ");
		scanf("%s", ogr[i].atolye);
		
		do{
			printf("Ogrenci Bilgi (L/U): ");
			scanf(" %c", &ogr[i].ogrencitipi);
			if((ogr[i].ogrencitipi!='L' && ogr[i].ogrencitipi!='l' && ogr[i].ogrencitipi!='U' && ogr[i].ogrencitipi!='u')){
				printf("Lutfen sadece L veya U giriniz.\n");
			}
		}while(ogr[i].ogrencitipi!='L' && ogr[i].ogrencitipi!='l' && ogr[i].ogrencitipi!='U' && ogr[i].ogrencitipi!='u');
		
		if(ogr[i].ogrencitipi=='L' || ogr[i].ogrencitipi=='l'){
			printf("Lise Adi: ");
			scanf("%s", ogr[i].liseli.liseAdi);
			printf("Sinifi: ");
			scanf("%d", &ogr[i].liseli.sinif);
			printf("Sube: ");
			scanf(" %c", &ogr[i].liseli.sube);
		}
		else if(ogr[i].ogrencitipi=='U' || ogr[i].ogrencitipi=='u'){
			printf("Universite Adi: ");
			scanf("%s", ogr[i].universiteli.uniAdi);
			printf("Fakulte: ");
			scanf("%s", ogr[i].universiteli.fakulte);
			printf("Bolum: ");
			scanf("%s", ogr[i].universiteli.bolum);
			printf("Yil: ");
			scanf("%d", &ogr[i].universiteli.yil);
			universiteligirildimi=1;
		}
		
		printf("Ogrenci eklemek istiyor musunuz? (e/h): ");
		scanf(" %c", &devam);
		i++;
		printf("\n");
	}while(i<20 && (devam!='h' && devam!='H'));
	
	
	//Üniversiteli öðrencilerin yaþlarýnýn ortalamasý;
	int topOgr=i, topUni=0, uniTopYas=0;
	double uniOgrYasOrt;
	
	if(universiteligirildimi == 1){
		for(i=0; i<topOgr; i++){
			if(ogr[i].ogrencitipi == 'u' || ogr[i].ogrencitipi == 'U'){
				uniTopYas += ogr[i].yas;
				topUni++;
			}
		}
		uniOgrYasOrt = uniTopYas / (double)topUni;
		printf("Universiteli ogrencilerin yas ortalamasi: %.2f\n", uniOgrYasOrt);
	}
	else{
		printf("Universiteli ogrenci girilmedi.\n");
	}
	
	
	//Atölye sayýsýlarýný indeksleme
	int j, k, bayrak=0, indeks[20][1], nAtolye=0;
	char atolye[20];
	
	for(i=0; i<20; i++){
		indeks[i][0]=0;
	}
	
	for(i=0; i<topOgr; i++){
		bayrak=0;
		strcpy(atolye, ogr[i].atolye);
		
		for(j=i; j>=0; j--){
			if( strcmp(atolye, ogr[j].atolye) !=0 ){
				bayrak=1;
			}
			else{
				bayrak=0;
				break;
			}
		}
		
		if(bayrak==1){
			indeks[j][0]++;
		}
		else{
			for(k=0; k<=i; k++){
				if( strcmp(atolye, ogr[k].atolye) == 0 ){
					indeks[k][0]++;
					break;
				}
			}
		}
	}
	
	//nAtolye: toplam farklý atölye sayýsý
	for(i=0; i<topOgr; i++){
		if(indeks[i][0]!=0){
			nAtolye++;
		}
	}
	printf("\nToplam %d atolye\n", nAtolye);
	
	
	//Atölyedeki üniversiteli ve liseli sayýsý
	int universiteliSay, liseliSay, atolyesira=1;
	char okul[20];
	
	for(i=0; i<topOgr; i++){
		if(ogr[i].ogrencitipi == 'l' || ogr[i].ogrencitipi=='L'){
			okul[i]='L';
		}
		else{
			okul[i]='U';
		}
	}
	
	for(i=0; i<topOgr; i++){
		if(indeks[i][0]!=0){
			universiteliSay=0;
			liseliSay=0;
			strcpy(atolye, ogr[i].atolye);
			for(j=i; j<topOgr; j++){
				if(okul[j]=='L' && (strcmp(atolye, ogr[j].atolye)==0) ){
					liseliSay++;
				}
				else if(okul[j]=='U' && (strcmp(atolye, ogr[j].atolye)==0) ){
					universiteliSay++;
				}
			}
			if(universiteliSay!=0 && liseliSay!=0){
				printf("[%d]%s Atolyesi: %d Liseli, %d Universiteli\n", atolyesira++, atolye, liseliSay, universiteliSay);
			}
			else if(universiteliSay!=0 && liseliSay==0){
				printf("[%d]%s Atolyesi: %d Universiteli\n", atolyesira++, atolye, universiteliSay);
			}
			else if(liseliSay!=0 && universiteliSay==0){
				printf("[%d]%s Atolyesi: %d Liseli\n", atolyesira++, atolye, liseliSay);
			}
			else{
				printf("[%d]%s Atolyesi: -\n", atolyesira++, atolye);
			}
			
		}
	}
	
	
	
	
	return 0;
}












