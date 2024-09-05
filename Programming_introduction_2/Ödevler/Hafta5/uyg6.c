#include<stdio.h>
#include<string.h>

int main(){
	int i, p, j=0, k, k_uzunluk, c_uzunluk, bayrak=0;
	char cumle[100], kelime[10];
	printf("Bir cumle giriniz: ");
	gets(cumle);
	printf("Bir kelime giriniz: ");
	gets(kelime);
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

	printf("Yeni cumle: %s", cumle);
		
	return 0;
}
