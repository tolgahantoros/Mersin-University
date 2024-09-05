#include<stdio.h>
#include<string.h>
void fonk(char [], char []);

int main(){
	char cumle[100], kelime[100];
	printf("Bir cumle giriniz: ");
	gets(cumle);
	fonk(cumle, kelime);
	printf("En kisa kelime: %s", kelime);
	
	return 0;
}

void fonk(char cumle[100], char kelime[100]){
	int i, k_uzunluk=0, k_enkisa=100;
	for(i=0; cumle[i]!='\0'; i++){
		k_uzunluk++;
		if(cumle[i]==' '){
			k_uzunluk--;
			if(k_uzunluk<k_enkisa){
				k_enkisa=k_uzunluk;
				strncpy(kelime, &cumle[i-k_uzunluk], k_uzunluk);
				kelime[k_uzunluk]='\0';
			}
			k_uzunluk=0;
		}	
	}
}
