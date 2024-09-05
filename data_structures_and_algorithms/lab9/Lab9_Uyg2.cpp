#include <iostream>
#include <string>
using namespace std;
int main() {
    string foo [] = {"elma","armut","kavun","karpuz","ananas","ayva","üzüm","mandalina","muz","kivi","portakal","hurma","greyfurt","mango","kayýsý","þeftali","erik","kiraz","incir","dut"};
    string hashtablo[20];
 
    int i,hash;
    for (i = 0; i < 20; i++)
   { hashtablo[i]="0";}
    
   for (i = 0; i < 20; i++)
   {
      hash=i%5;
      if(hashtablo[hash]=="0")
       hashtablo[hash]=foo[i];
      else
      {
          int j=0;
         while(hashtablo[hash]!="0") 
         {            
             hash= (hash+(j*j))%20;                        
             j++;
        }
        hashtablo[hash]=foo[i];
      }         
   }
  for (i = 0; i < 20; i++)
   { cout<< hashtablo[i] <<"\n";}

    
    system("PAUSE");
    return 0;
 
}
