#include<stdio.h>
#include<string.h>

int main(){
	int i, j, k, bayrak=0;
	char cumle[100], kelime[10];
	printf("Bir metin giriniz: ");
	gets(cumle);
	printf("Bir kelime giriniz: ");
	scanf("%s", kelime);
	
	for(i=0; cumle[i]!='\0'; i++){
		if(cumle[i]==kelime[0]){
			for(j=i, k=0; k<strlen(kelime); j++, k++){
				if(cumle[j]==kelime[k]){
					bayrak=1;
				}
				else{
					bayrak=0;
					break;
				}
			}
			if(bayrak==1){
				break;
			}
		}
	}
	if(bayrak==1){
		printf("'%s' kelimesi, metin icinde %d. karakterden basliyor.", kelime, i);
	}
	else{
		printf("'%s' kelimesi, metin icinde yoktur.", kelime);
	}
	
	
	return 0;
}
