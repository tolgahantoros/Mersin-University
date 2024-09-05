#include<stdio.h>
#include<string.h>

int main(){
	int nListe1, nListe2;
	int i, j;
	char dizgi1[100][80]={}, dizgi2[100][80]={}, bos;
	FILE *liste1, *liste2, *listeKarsilastir;
	
	printf("Liste1 icin isim sayisi: ");
	scanf("%d", &nListe1);
	printf("Liste2 icin isim sayisi: ");
	scanf("%d", &nListe2);
	
	scanf("%c", &bos);
	liste1=fopen("liste1.txt", "w");
	for(i=0; i<nListe1; i++){
		gets( dizgi1[i] );
		fprintf(liste1, "%s\n", dizgi1[i]);
	}
	fclose(liste1);
	
	liste2=fopen("liste2.txt", "w");
	for(i=0; i<nListe2; i++){
		gets( dizgi2[i] );
		fprintf(liste2, "%s\n", dizgi2[i]);
	}
	fclose(liste2);
	
	
	return 0;
}
