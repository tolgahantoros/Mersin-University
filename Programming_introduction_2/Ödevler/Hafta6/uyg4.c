#include<stdio.h>
#include<string.h>
#include<ctype.h>
void fonk(char []);

int main(){
	char cumle[100];
	printf("Bir dizgi giriniz: ");
	gets(cumle);
	fonk(cumle);
//	puts(cumle);
	printf("%s", cumle);
}

void fonk(char cumle[100]){
	int i;
	for(i=0; cumle[i]!='\0'; i++){
		if( (i==0 || isspace(cumle[i-1])) && islower(cumle[i]) ){
			cumle[i]=toupper(cumle[i]);
		}
	}
}
