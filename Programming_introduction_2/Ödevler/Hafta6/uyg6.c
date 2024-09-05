#include<stdio.h>
#include<string.h>
int main(){
	int i, j, k, bayrak;
	char cumle[100], kelime[10];
	printf("Bir cumle giriniz: ");
	gets(cumle);
	printf("Bir kelime giriniz: ");
	scanf("%s", kelime);
	
	for(i=0; i<strlen(cumle); i++){
		bayrak=0;
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
			for(j=i; cumle[j]!='\0'; j++){
				cumle[j]=cumle[j+strlen(kelime)];
			}
		}
	}
	puts(cumle);
	
	
	return 0;
}
