#include<stdio.h>
void fon(int*, int*, int*);
int main(){
	int bHarf, kHarf, topKar;
	fon(&bHarf, &kHarf, &topKar);
	printf("%d adet buyuk harf\n%d adet kucuk harf\nToplam %d adet karakter girildi.", bHarf, kHarf, topKar);
	
	return 0;
}

void fon(int *bHarf, int *kHarf, int *topKar){
	char ch;
	int f_bHarf=0, f_kHarf=0, f_topKar=0;
	printf("Cumle: ");
	do{
		scanf("%c", &ch);
		if(ch>='A' && ch<='Z'){
			f_bHarf++;
		}
		else if(ch>='a' && ch<='z'){
			f_kHarf++;
		}
		f_topKar++;
	}while(ch!='.');
	
	*bHarf=f_bHarf;
	*kHarf=f_kHarf;
	*topKar=f_topKar;
}
