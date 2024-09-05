#include<stdio.h>
#include<string.h>
void fonk(char [], char []);

int main(){
	char cumle[100], kisaltma[10];
	do{
		printf("Bir dizgi giriniz: ");
		gets(cumle);
		if(cumle[0]=='\0'){
			break;
		}
		fonk(cumle, kisaltma);
		printf("Kisaltma: %s\n", kisaltma);
		
	}while(cumle[0]!='\0');
	
	return 0;
}

void fonk(char cumle[100], char kisaltma[10]){
	int i, j=0;
	for(i=0; i<strlen(cumle); i++){
		if(i==0 || cumle[i-1]==' '){
			kisaltma[j++]=cumle[i];
		}
	}
	kisaltma[j]='\0';
}
