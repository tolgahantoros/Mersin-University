#include<stdio.h>
#include<string.h>
void fonk(char [], char [], char []);
int main(){
	char cumle[100], kelime[10], cumle2[100];
	printf("Bir metin giriniz: ");
	gets(cumle);
	printf("Bir kelime giriniz: ");
	scanf("%s", kelime);
	fonk(cumle, kelime, cumle2);
	puts(cumle2);
	
	return 0;
}

void fonk(char cumle[100], char kelime[10], char cumle2[100]){
	int i, j, k, bayrak=0;
	for(i=0; i<strlen(cumle); i++){
		if(cumle[i]==kelime[0]){
			for(j=i, k=0; k<strlen(kelime); k++, j++){
				if(cumle[j]==kelime[k]){
					bayrak=1;
				}
				else{
					bayrak=0;
					break;
				}
			}
		}
		if(bayrak==1){
			cumle2[i]=cumle[i+strlen(kelime)];
		}
		else{
			cumle2[i]=cumle[i];
		}
	}
	cumle2[i]='\0';
}
