#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	int i, j;
	char cumle[100];
	printf("Bir dizgi giriniz: ");
	gets(cumle);
	
	for(i=0; i<strlen(cumle); i++){
		if(isspace(cumle[i])){
			for(j=i; j<strlen(cumle); j++){
				cumle[j]=cumle[j+1];
			}
		}
	}
	puts(cumle);
	
	return 0;
}
