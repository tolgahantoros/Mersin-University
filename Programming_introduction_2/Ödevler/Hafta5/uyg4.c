#include<stdio.h>
#include<string.h>
void fonk(char []);
char buyult(char);

int main(){
	char cumle[100];
	printf("Bir dizgi giriniz: ");
	gets(cumle);
	fonk(cumle);
	printf("%s", cumle);
	
	
	return 0;
}

void fonk(char cumle[100]){
	int i;
	for(i=0; cumle[i]!='\0'; i++){
		if( (i==0 || cumle[i-1]==' ') && (cumle[i]>='a' && cumle[i]<='z') ){
			cumle[i]=buyult(cumle[i]);
		}
	}
}

char buyult(char kucukHarf){
	if(kucukHarf=='a')
		return 'A';
	else if(kucukHarf=='b')
		return 'B';
	else if(kucukHarf=='c')
		return 'C';
	else if(kucukHarf=='d')
		return 'D';
	else if(kucukHarf=='e')
		return 'E';
	else if(kucukHarf=='f')
		return 'F';
	else if(kucukHarf=='g')
		return 'G';
	else if(kucukHarf=='h')
		return 'H';
	else if(kucukHarf=='i')
		return 'I';
	else if(kucukHarf=='j')
		return 'J';
	else if(kucukHarf=='k')
		return 'K';
	else if(kucukHarf=='l')
		return 'L';
	else if(kucukHarf=='m')
		return 'M';
	else if(kucukHarf=='n')
		return 'N';
	else if(kucukHarf=='o')
		return 'O';
	else if(kucukHarf=='p')
		return 'P';
	else if(kucukHarf=='q')
		return 'Q';
	else if(kucukHarf=='r')
		return 'R';
	else if(kucukHarf=='s')
		return 'S';
	else if(kucukHarf=='t')
		return 'T';
	else if(kucukHarf=='u')
		return 'U';
	else if(kucukHarf=='v')
		return 'V';
	else if(kucukHarf=='w')
		return 'W';
	else if(kucukHarf=='x')
		return 'X';
	else if(kucukHarf=='y')
		return 'Y';
	else if(kucukHarf=='z')
		return 'Z';
	
	else return '_';
	
}
