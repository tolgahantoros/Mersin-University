#include<stdio.h>
#include<string.h>
void fonk(char []);

int main(){
	char isim[20];
	printf("Bir isim giriniz: ");
	//gets(isim);
	scanf("%s", isim);
	
	fonk(isim);
	
	return 0;
}

void fonk(char isim[20]){
	int i, j;
	char isim2[20];
	
	printf("Tekrarlayan isim: ");
	for(i=0; i<strlen(isim); i++){
		for(j=0; j<=i; j++){
			isim2[j]=isim[j];
			isim2[j+1]='\0';
		}
		printf("%s", isim2);
	}

}
