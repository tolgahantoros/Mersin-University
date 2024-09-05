#include <iostream>
#include <string>
using namespace std;
int main() {
    string foo [] = {"elma","armut","kavun","karpuz","ananas","ayva","üzüm","mandalina","muz","kivi","portakal","hurma","greyfurt","mango","kayýsý","þeftali","erik","kiraz","incir","dut"};
    string ara;
    int i;
    cout<<"Hangi meyve?\n";
    cin>>ara;
    
   for (i = 0; i < 20; i++)
   {
      if (foo[i] == ara)     
      {
         cout<<ara<<" meyvesi "<<i<<". lokasyonda \n";
         break;
     }
   }
   if (i == 20)
    cout<<ara<<" meyvesi listede yok";

    
    system("PAUSE");
    return 0;
 
}

 




