#include <stdio.h>
#include <math.h>
#include<iostream>


void ekleme_sirala(int a[], int veri)
{
int i, key, j,sayac=0;
for (i = 1; i < veri; i++)
{
	key = a[i];
	j = i-1;

	while (j >= 0 && a[j] > key)
	{
		a[j+1] = a[j];
		j = j-1;
		sayac+=1;
	}
	a[j+1] = key;
	sayac+=1;
}
printf("sayac=%d\n",sayac);
}

void yazdir_dizi(int a[], int veri)
{
int i;
for (i=0; i < veri; i++)
	printf("%d ", a[i]);
printf("\n\n");
}

secme_sirala(int a[],int veri){
	
	int i,j,min,loc,temp,sayac=0;
	  for(i=0;i<veri-1;i++)
    {
        min=a[i];
        loc=i;
        for(j=i+1;j<veri;j++)
        {
            if(min>a[j])
            {
                min=a[j];
                loc=j;
            }
            sayac+=1;
        }
 
        temp=a[i];
        a[i]=a[loc];
        a[loc]=temp;
    }
    printf("sayac=%d\n",sayac);

}

void swap(int *xp,int *yp){
	
	int temp=*xp;
	*xp=*yp;
	*yp=temp;
		
}

void kabarcik_sirala(int a[],int veri){
	int i,j,sayac=0;
	
	for(i=0;i<veri-1;i++)
	   
	   for(j=0;j<veri-i-1;j++)
	   {
	   	sayac+=1;
	     
	     if(a[j]>a[j+1])
	       
	       swap(&a[j],&a[j+1]);
	   }
	       
 printf("sayac=%d\n",sayac);

}


int main()
{
	int a[] = {2,3,6,7,5,8,9,4,15};
	int b[]= {7,3,5,8,2,9,4,15,6};
	int veri = sizeof(a)/sizeof(a[0]);
     
    printf("insertion_sort\n");
	ekleme_sirala(a, veri);
	yazdir_dizi(a, veri);
	printf("selection_sort\n");
	secme_sirala(a,veri);
	yazdir_dizi(a,veri);
	printf("bubble_sort\n");
	kabarcik_sirala(a,veri);
	yazdir_dizi(a,veri);
	int veri1=sizeof(b)/sizeof(b[0]);
	
system("PAUSE");
	return 0;
}

