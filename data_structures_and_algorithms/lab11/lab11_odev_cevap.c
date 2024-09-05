#include <stdio.h>    
#include <limits.h>    
#define V 9  
   
void prim(int g[V][V])    
{  
    int eleman[V];    
    int k[V];       
    int m[V];      
    int i, sayac,kenar,v; 
    for (i = 0; i < V; i++)  
    {  
        k[i] = INT_MAX;  
        m[i] = 0;    
    }  
    
    k[0] = 0; 
    eleman[0] = -1;
    
    for (sayac = 0; sayac < V-1; sayac++)    
    {    
        kenar = minimum_agirlik(k, m);    
        m[kenar] = 1;    
        
        for (v = 0; v < V; v++)    
        {  
            if (g[kenar][v] <  k[v] && g[kenar][v] && m[v] == 0 )    
            {  
                eleman[v]  = kenar;
				k[v] = g[kenar][v];    
            }  
        }  
    }    
     
     printf("\n\tKenar \t\t\tAgirlik\n");
	 printf("*****************************************\n");
     for (i = 1; i < V; i++)    
     printf(" %d ile %d dugumleri arasi\t  %d \n", eleman[i], i, g[i][eleman[i]]);    
      
}    

int minimum_agirlik(int k[], int m[])    
{  
    int minimum  = INT_MAX, min,i;     
    
    for (i = 0; i < V; i++)  
        if (m[i] == 0 && k[i] < minimum )   
            minimum = k[i], min = i;    
            
    return min;    
} 

int main()    
{    
    int A[V][V] =  {  {0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                    };  
    prim(A);   
	printf("*****************************************\n"); 
    return 0;  
}  

