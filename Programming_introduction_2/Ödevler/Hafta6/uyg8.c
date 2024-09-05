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
	int i, j, indeks_alt=0, indeks_ust=0, k_uzunluk=0, k_enkisa=100;
	for(i=0; cumle[i]!='\0'; i++){
		k_uzunluk++;
		if(cumle[i]==' '){
			k_uzunluk--;
			if(k_uzunluk<k_enkisa){
				k_enkisa=k_uzunluk;
				indeks_ust=i-1;
				indeks_alt=indeks_ust-k_uzunluk+1;
			}
			k_uzunluk=0;
		}	
	}
	for(indeks_alt, j=0; indeks_alt<=indeks_ust; indeks_alt++, j++){
		kelime[j]=cumle[indeks_alt];
	}
	kelime[j]='\0';
}
