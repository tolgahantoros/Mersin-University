#include<stdio.h>
#include<string.h>
void fonk(char [], char []);
int main(){
	char isim[10], isim2[100];
	printf("Bir isim giriniz: ");
	scanf("%s", isim);
	fonk(isim, isim2);
	printf("Tekrarlayan isim: %s", isim2);
	
	return 0;
}

void fonk(char isim[10], char isim2[100]){
	int i;
	for(i=0; i<strlen(isim); i++){
		strncat(isim2, isim, i+1);
	}
	isim2[strlen(isim2)]='\0';
}
