/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bolum;

import java.util.ArrayList;

/**
 *
 * @author User
 */
public class Bolum {


 
public static void main(String[] args) {
        // TODO code application logic here
    
//3 kişi yaratıp, listeye ekleyelim
    Kisi k1 = new Kisi();
    Kisi.ekle(k1);
    
    Kisi k2 = new Kisi();
    Kisi.ekle(k2);
    
    Kisi k3 = new Kisi();
    Kisi.ekle(k3);
    
//3 ogrenci yaratıp, listeye ekleyelim
    Ogrenci o1=new Ogrenci();
    Kisi.ekle(o1);
    
    Ogrenci o2=new Ogrenci();
    Kisi.ekle(o2);
    
    Ogrenci o3=new Ogrenci();
    Kisi.ekle(o3);
     
//3 hoca yaratıp, listeye ekleyelim
    Hoca h1=new Hoca();
    Kisi.ekle(h1);
    
    Hoca h2=new Hoca();
    Kisi.ekle(h2);
    
    Hoca h3=new Hoca();
    Kisi.ekle(h3);
    
    System.out.println("\n\n-----------------------Bolum-1:  3'u ogrenci, 3'u hoca olmak uzere 9 kisi yarattik ve listeye ekledik. Kisi Listesi: ");
    System.out.print(Kisi.kisiler);
    
    //5 ders yaratip, listeye ekleyelim
    Ders.ekle(new Ders());
    Ders.ekle(new Ders());
    Ders.ekle(new Ders());
    Ders.ekle(new Ders());
    Ders.ekle(new Ders());
    
    System.out.println("\n\n-----------------------Bolum-2: 5 ders yarattik ve ders listesine ekledik. Ders Listesi: ");
    System.out.print(Ders.dersler);
    
    //5 dersin bazilarini ogrencilere, bazilarini hocalara atayalim..yeni ders kopyeleri olusturmayalim
    o1.dersEkle(Ders.dersler.get(0));
    o1.dersEkle(Ders.dersler.get(1));
    o3.dersEkle(Ders.dersler.get(2));
    o3.dersEkle(Ders.dersler.get(3));
    
    h1.dersEkle(Ders.dersler.get(0));
    h3.dersEkle(Ders.dersler.get(1));
    h2.dersEkle(Ders.dersler.get(2));
    h2.dersEkle(Ders.dersler.get(3));
    h2.dersEkle(Ders.dersler.get(4));
    
    System.out.println("\n\n-----------------------Bolum-3: ogrenci ve hocalara ders atamasi yaptik. Kisi Bilgileri: ");
    System.out.print(Kisi.kisiler);
    
    System.out.println("\n\n-----------------------Bolum-4: o1(ogrenci3) ve h1(hoca6) den ders0 'i silelim");
    System.out.println("ogrenci3'un ders0 silinmeden onceki bilgisi:\n"+o1);
    System.out.println("hoca6'nin ders0 silinmeden onceki bilgisi:\n"+h1);
    o1.dersSil(Ders.dersler.get(0));
    h1.dersSil(Ders.dersler.get(0));
    System.out.println("ogrenci3'un ders0 silindikten sonraki  bilgisi:\n"+o1);
    System.out.println("hoca6'nin ders0 silindikten sonraki bilgisi:\n"+h1);
    
    System.out.println("\n\n-----------------------Bolum-5: sadece ogrencileri listeleyelim");
    Kisi.ogrencilistele();
    
    System.out.println("\n\n-----------------------Bolum-6: sadece hocalari listeleyelim");
    Kisi.hocalistele();
}
    
}


class Kisi {
//------------static üyeler--------------
   static ArrayList<Kisi> kisiler=new ArrayList(); //bütün kişilerin(öğrenci veya hoca) için kayıt listesi
   static void ekle(Kisi k) {
      kisiler.add(k);
   }
   static void sil(Kisi k) {
      kisiler.remove(k);
   }
   
   static void sil(String no) {
     int i;
     for(i=0;i<kisiler.size();i++)
         if(kisiler.get(i) instanceof Ogrenci)
            if(  ((Ogrenci)kisiler.get(i)).numara.equals(no)  ) break;      
     if (i<=kisiler.size()) kisiler.remove(i);
   }
   
   static void ogrencilistele() {
     for(int i=0;i<kisiler.size();i++)
         if(kisiler.get(i) instanceof Ogrenci)
            System.out.println((Ogrenci)kisiler.get(i));
   
   }
   
   static void hocalistele() {
     for(int i=0;i<kisiler.size();i++)
         if(kisiler.get(i) instanceof Hoca)
            System.out.println((Hoca)kisiler.get(i));
   
   }
//------------instans üyeler--------------
   String ad,tcno, tel, adres;
   Kisi(){
     ad="kisi"+kisiler.size();
     tcno="tcno"+kisiler.size();
     tel="tel"+kisiler.size();
     adres="adres"+kisiler.size();
     
   }
   @Override 
   public boolean equals(Object o){
     if (o instanceof Kisi){
        Kisi k = (Kisi)o;
        if (k.tcno.equals(tcno)) return true;
     }
     return false;
   }
   @Override 
   public String toString(){
       String s= "ad:"+ad+", tcno:"+tcno+", adres:"+adres+", tel:"+tel;
       if (this instanceof Ogrenci)
              s=s+",numara:"+ ((Ogrenci)this).numara;
       else if (this instanceof Hoca)
              s=s+",unvan:"+((Hoca)this).unvan;
       s=s+"\n";
   return s;
   }
}
 class Ogrenci extends Kisi {
     
   
   //------------instans üyeler--------------
   ArrayList<Ders> al_dersler; //aldığı dersler, Ders.dersler listesine bir referans olacak
   String numara;
   
   void dersEkle(Ders d){
      al_dersler.add(d);
   }
   
   void dersSil(Ders d){
      al_dersler.remove(d);
   }
   
   Ogrenci(){
     al_dersler=new ArrayList();
     numara="no"+kisiler.size();
      ad="ogrenci"+kisiler.size();
   }
  
   @Override 
   public boolean equals(Object o){
     if (o instanceof Ogrenci){
        Ogrenci ogr = (Ogrenci)o;
        if (ogr.numara.equals(numara)) return true;
     }
     return false;
   }
    @Override 
   public String toString(){
       String s=super.toString();
       if (al_dersler.size()>0)
          s =s+ "Dersleri:"+al_dersler.toString()+"\n\n";
       return s;
   }
    
}
 class Hoca extends Kisi {
   //------------instans üyeler--------------
   ArrayList<Ders> ver_dersler; //verdiği dersler, Ders.dersler listesine bir referans olacak
   String unvan;
   void dersEkle(Ders d){
      ver_dersler.add(d);
   }
   
   void dersSil(Ders d){
      ver_dersler.remove(d);
   }
   
   Hoca(){
      ver_dersler=new ArrayList();
      unvan="ogretim uyesi";
      ad="hoca"+kisiler.size();
   }
   @Override 
   public String toString(){
       String s=super.toString();
       if (ver_dersler.size()>0)
          s =s+ "Dersleri:"+ver_dersler.toString()+"\n\n";
       return s;
   }
}
 class Ders {
  //------------static üyeler--------------
   static ArrayList<Ders> dersler=new ArrayList(); //bütün derslerin kayıt listesi
   static void ekle(Ders d) {
      dersler.add(d);
   }
   static void sil(Ders d) {
      dersler.remove(d);
   }
   
 //------------instans üyeler--------------
   String adi;
   int kredi, donem;
   Ders(){
     adi="ders"+dersler.size();
     kredi=3;
     donem=1;  
   }
   
   @Override 
   public boolean equals(Object o){
     if (o instanceof Ders){
        Ders ders = (Ders)o;
        if (ders.adi.equals(adi)) return true;
     }
     return false;
   }
   @Override 
   public String toString(){
       return adi;
   }
}