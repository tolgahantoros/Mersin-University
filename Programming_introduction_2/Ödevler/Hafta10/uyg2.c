#include<stdio.h>
#include<string.h>
void sifrele(char []);

int main(){
	char yazi[80];
	FILE *oku, *yaz;
	oku = fopen("yazi.txt", "w");
	printf("Sifrelenecek metin: ");
	gets(yazi);
	fputs(yazi, oku);
	fclose(oku);
	
	oku = fopen("yazi.txt", "r");
	yaz = fopen("sifre.txt", "w");
	while( !feof(oku) ){
		fgets(yazi, 80, oku);
		sifrele(yazi);
		fputs(yazi, yaz);
	}
	fclose(oku);
	fclose(yaz);
	
	oku = fopen("sifre.txt", "r");
	printf("Sifreli metin: ");
	while( !feof(oku) ){
		fgets(yazi, 80, oku);
		printf("%s", yazi);
	}
	fclose(oku);
	
	
	
	return 0;
}

void sifrele(char yazi[]){
	int i;
	for(i=0; i<strlen(yazi); i++){
		if( (yazi[i]>='A' && yazi[i]<'Z') || (yazi[i]>='a' && yazi[i]<'z') ){
			yazi[i]+=1;
		}
		else if( yazi[i]=='Z' ){
			yazi[i]=='A';
		}
		else if( yazi[i]=='z' ){
			yazi[i]=='a';
		}
	}
}



