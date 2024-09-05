
package xxx;//dogru paketi tanimlamalisiniz

class SariciSinifDonusumleri {

void sarici_sinif_donusumleri () {
System.out.println("\nbundan sonraki mesajlar baska bir siniftan geliyor..fakat ayni paketteyiz");

//Gorev-11: asagidaki kodu calistirip, analiz edin ve yorumlayin?
  System.out.println("\n---------------Gorev-11 ciktisi---------------");  
  Integer i = new Integer(3); 	// sinif oldugundan new ile instansi (nesne) yaratilir
  int j = 3;
  Integer k = new Integer(j);
  boolean b = i==k;	  // i ve k tipi adres ve degerleri farkli
  Integer s = k;
  boolean e = s==k;	  // k ve s tipi adres ve degerleri ayni
  j = i.intValue() + k.intValue();
  System.out.println("b="+b+" e="+e+" j="+j);

//Gorev-12: asagidaki kodlar blok icine alindi..blok icinde tanimli degiskenlere, blok disindan erisim olmaz..yerel degisken olurlar..asagidaki komutlari analiz edin
  {
   System.out.println("\n---------------Gorev-12 ciktisi---------------");  
   Integer x = 3;   //instans yaratmadan kisayol ile deger atadik..Boxing
   int y=x;         // Sarici -->Ilkel tipe otomatik donustu..Unboxing ..
   System.out.println("int x="+x+" Integer y="+y); 
  }

//Gorev-13: asagidaki islemin neticesini analiz ediniz..Bu kod parcasinin amaci nedir?
  System.out.println("\n---------------Gorev-13 ciktisi---------------");  
  Integer x=1;   //x bir Sarici Nesne..Bu nesne neden otomatik yaratildi...
  int z=1;       //z bir ilkel tipli degisken, nesne degil...burada boxing yada unboxing var mı?     
  b = x==z;  	// burada boxing yada unboxing var mı? hangisi var?
  System.out.println("x==z :" +b); 

//Gorev-14: asagidaki islemin neticesini analiz ediniz..
  System.out.println("\n---------------Gorev-14 ciktisi---------------");  
  Integer m=3;  //m = bir adres
  Integer n=3;  // n = bir adres 
  b=m==n;  	//m ve n neden ayni adresi gosteriyor..
  System.out.println("m==n :" +b); 

//Gorev-15: asagidaki kiyaslama isleminin neden ayni yada farkli oldugu hakkinda yorum yapiniz
boolean b1=Integer.valueOf(3)==Integer.valueOf(3);
boolean b2=Integer.valueOf(128)==Integer.valueOf(128);
System.out.println("b1="+b1+" b2="+b2);

}  


}