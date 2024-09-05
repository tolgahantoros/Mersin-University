
package xxx;//dogru paketi tanimlamalisiniz

class IlkelTipDonusumleri {
byte b;
int i1=1, i2;
float f;
double d1=2.5, d2;
char c;
short s=3;

void ilkel_tip_donusumleri () {
 //Gorev-1: nesne uyelerinin baslangic degerlerini analiz ediniz. Deger atanmayan degiskenlerin degeri hakkinda yorum yapiniz 
   System.out.println("\n---------------Gorev-1 ciktisi---------------");
   System.out.println("nesne uyelerinin baslangic degerleri soyle");
   System.out.println("c="+c+" b="+b+" s="+s+" i1="+i1+" i2="+i2+" f="+f+" d1="+d1+" d2="+d2);
     
 //Gorev-2: asagida char c='z'; olarak yeni bir yerel degisken tanimliyoruz. c yerel degiskeninin ve c nesne uyesinin(instans degiskeni) baslangic unicode degerini yazdiralim.
   System.out.println("\n---------------Gorev-2 ciktisi---------------");
   char c='z';   //dikkat iki tane c degiskeni oldu:yerel degiskeni c, nesne degiskeni this.c ile erisilir.            
   System.out.println("yerel degisken c:"+c+", unicode degeri:"+(int)c);  
   System.out.println("instans degiskeni c:"+this.c+ ", unicode degeri:"+(int)this.c);    
 
//Gorev-3: i1=c+1; komutunu asagiya ekleyip, i1 `in degerini ekrana yazdiriniz..sag tarafin nihai tipi nedir ? yorum yapiniz?
   System.out.println("\n---------------Gorev-3 ciktisi---------------");
  
//Gorev-4: asagida cast islemini iptal ederek deneyiniz..sonuc ne oldu...Deger kaybi olmamasi icin ne yapabiliriz.
// print islemini analiz edin..kacis karakterleri \n ve \' ne yapti? 
   System.out.println("\n---------------Gorev-4 ciktisi---------------");
   int i= (int)d1 + i1;   
   System.out.print("(int)d1 + i1="+i+" fakat \'d1 + i1'="+(d1 + i1)+"\n");  

//Gorev-5: asagidaki satirlarin yorumunu aciniz, derleyiniz ve hatalari duzeltiniz..hatanin sebebi nedir?    
   System.out.println("\n---------------Gorev-5 ciktisi---------------");
   //s=b;   			//burada hata cikti mi? 
   //s = b + 1;   
   //System.out.println("s=b + 1="+ s);

//Gorev-6: s=3+1 komutunu isletip ekrana yazdirin, sonra s=4 komutunu isletip ekrana yazdirin,programi calistirin, hata ciktiysa sebebini dusunun ve hatayi duzeltin 
   System.out.println("\n---------------Gorev-6 ciktisi---------------");  
   
//Gorev-7: short s; isminde yerel bir degisken daha tanimladik...yorumlari acip derleyiniz ve hatalari bulup, duzeltiniz..
   System.out.println("\n---------------Gorev-7 ciktisi---------------");
  //short s;
  //d1=1.1f + s;
  //this.s=d1;
  //f = 8.4;   

//Gorev-8: Su aritmetik islemlerin sonucunu javaya yazdirin: 3/2, 3/2.0, (float)3/2, (float)(3/2)..x/y islemi ne yapti
   System.out.println("\n\n---------------Gorev-8 ciktisi---------------");
 
//Gorev-9: asagida ilk print isleminde d1+i1 toplanirken, ikincisinde birlestirme uygulanmistir..Sonucu nasil yorumlarsiniz..
   System.out.println("\n---------------Gorev-9 ciktisi---------------");
   System.out.println(d1 + i1+" = d1 + i1,ve bunun cast edilmis degeri ="+i);
   System.out.println("yani, d1 + i1 = "+d1+i1+" fakat sonuc niye farkli cikti..anlamadim");

//Gorev-10:yukarida hangi komutlarda promosyon(tipin genislemesi) vardir..asagiya shorttan double'a gennisleyen yeni bir ornek ekleyip, ciktisini yazdirin
   System.out.println("\n---------------Gorev-10 ciktisi---------------");
}  

public static void main(String [] a) {
IlkelTipDonusumleri x = new IlkelTipDonusumleri ();
SariciSinifDonusumleri y= new SariciSinifDonusumleri ();
x.ilkel_tip_donusumleri();
y.sarici_sinif_donusumleri();

}

}