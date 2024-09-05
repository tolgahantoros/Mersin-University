#include<stdio.h>
#include<string.h>
void fonk(char [], char[]);

int main(){
	char cumle[100], kelime[10];
	printf("Bir cumle giriniz: ");
	gets(cumle);
	printf("Bir kelime giriniz: ");
	gets(kelime);
	
	fonk(cumle, kelime);
	printf("Yeni cumle: %s", cumle);
		
	return 0;
}

void fonk(char cumle[100], char kelime[10]){
	int i, p, j=0, k, k_uzunluk, c_uzunluk, bayrak=0;
	k_uzunluk=strlen(kelime);
	c_uzunluk=strlen(cumle);
	
	for(i=0; cumle[i]!='\0'; i++){
		for(j=i, k=0; k<k_uzunluk; j++, k++){
			if(cumle[j]==kelime[k]){
				bayrak=1;
			}
			else{
				bayrak=0;
				break;
			}
		}
		if(bayrak==1){
		for(p=i; cumle[p]!='\0'; p++){
			cumle[p]=cumle[p+k_uzunluk];
		}
		i--;
		}	
	}
}
