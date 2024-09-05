#include<stdio.h>
#include<string.h>
void fonk(char [], char [], int*);

int main(){
	int i, j;
	char isim[20], isim2[20];
	printf("Bir isim giriniz: ");
	//gets(isim);
	scanf("%s", isim);
	
	printf("Tekrarlayan isim: ");
	for(i=0; i<strlen(isim); i++){
		fonk(isim, isim2, &i);
		printf("%s", isim2);
	}
	
	return 0;
}

void fonk(char isim[20], char isim2[20], int *i){
	int j;
	for(j=0; j<=*i; j++){
		isim2[j]=isim[j];
		isim2[j+1]='\0';
	}

}
