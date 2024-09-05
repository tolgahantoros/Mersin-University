/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab4;

/**
 *
 * @author zeki
 */
class test {
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
     
/*****BOLUM 1: her sınıftan birer adet instanslar yaratalım ve gelişigüzel bilgiler girelim****/        
        
        /*****BOLUM 1.1: Varlık,Canli, Insan sınıflarına ait instanslar yaratalım*****/
        Varlik v = new Varlik("insan"); 
        v.set_agirlik(72.5);
        
        Canli c = new Canli("kedi");
        c.sutuketimi=0.3f;
        c.yas=1;
        
        Insan i= new Insan();
        i.medenihali="bekar";
        i.meslek="ogretmen";
        i.sutuketimi=2;
        i.yas=30;
       
        
        /****BOLUM 1.2:bir öğrenci yaratalım ve tüm bilgilerini girelim*****/
        Ogrenci o1= new Ogrenci("ali");
        o1.set_agirlik(70); //ağırlık özelliği korunuyor..kapsüllenmiş
        o1.yas=20;          //yas özelliği korunmuyor..kapsüllenmemiş.
        o1.sutuketimi=2.5f;
        o1.cinsiyet='K';
        o1.medenihali="bekar";
        o1.okulad="Mersin Univ.";
                
        Ders d1= new Ders(); //dersi yaratıp,bilgiler girip, o1' e ekleyelim
        d1.adi="Nesneye Yonelik Programlama";
        d1.vizenotu=30;
        d1.finalnotu=60;
           
        Insan hoca = new Insan(); //hocayı yaratıp, d1 ' in hocası olarak sonra atayalım
        o1.dersekle(d1);      //d1 i, o1 e ekliyoruz
        hoca.medenihali="evli";
        hoca.cinsiyet='E';
        hoca.yas=50;
        hoca.sutuketimi=1.2f;
        d1.hocasi = hoca; // hoca'yı d1' e burada atadık. hoca ve d1.hocasi aynı nesne oldu
        
       /****BOLUM 1.3: varsayılan bilgilerle yeni bir öğrenci yaratalım. d1 dersini ve iki yeni dersi alsın****/ 
        Ogrenci o2= new Ogrenci();
        o2.dersekle(d1);
        o2.dersekle(new Ders()); //yeni bir ders daha ekleyelim. Ders bilgilerini sonra değiştirebiliriz
        o2.dersekle(new Ders()); //yeni bir ders daha ekleyelim. Ders bilgilerini sonra değiştirebiliriz
        
        
        /******BOLUM 2:statik ve instans tanımlı sayıcıların değerlerini analiz edelim ***********/
        //static değişkenlere hem sınıf ismiyle hemde instans ismiyle ulaşabiliriz.
        System.out.println("\nBolum 2 ............................");
        System.out.print("varlik sayisi:"+Varlik.varliksayisi+ ", canli sayisi:"+ c.canlisayisi+", insan sayisi:"+i.insansayisi);
        System.out.print(" ogrenci sayisi:"+ Ogrenci.ogrencisayisi);
        System.out.print(" ders sayisi:"+ Ders.derssayisi);
        System.out.println(" o1.ders_sayisi:"+ o1.derssayisi+" o2.ders_sayisi:"+o2.derssayisi);
        
        
/******BOLUM 3:nesneler arası cast işlemini analiz edelim ***********/
        
        /***BOLUM 3.1: bir nesneyi atasına cast edelim, sonra da atasından kendisine cast edelim****/
        System.out.println("\nBolum 3.1 ............................");
        
        Insan i1= o1;  //o1 öğrencisiyle aynı özelliklere sahip bir insan yaratmanın kısayolu : gizli cast
                       // nesneyi atasına cast ettik = özelden genele geçiş = her ögrenci bir insandır--> açık caste gerek yok
                       //i1 artık bir öğrenci instansına sahip oldu.
        Insan.yazdır(i1);
        
        Ogrenci o3=null, o4=null;  
        
        if (i1 instanceof Ogrenci) 
            o3 = (Ogrenci)i1;  //i1 Ogrenci instansına sahip olduğundan mümkün. yoksa hata çıkar,
        
        if (i instanceof Ogrenci) 
            o4 = (Ogrenci)i;  //i Ogrenci instansına sahip değil, bu satıra gelmez,
        
        System.out.println("o3="+o3+", o4="+o4);  //adreslerin string ifadesini yazdır
        
        
        /***BOLUM 3.2: nesneleri en büyük atalarına cast edelim sonra castle ilgili işlemler yapalım***/
        System.out.println("\nBolum 3.2 ............................");
        
        Varlik [] varliklar = new Varlik[5]; // 5 varlık yaratalım. yukarda yarattıklarımızı sırayla atayalım
        
        varliklar[0] = v;
        varliklar[1] = c;
        varliklar[2] = i;
        varliklar[3] = o1;
        varliklar[4] = o2;
        
        //canli olan varlıkların adını ve yaşını yazdıralım
        for (int j=0;j<varliklar.length;j++)
            if (varliklar[j] instanceof Canli) 
                System.out.println(varliklar[j].oku_isim()+"--> yaş:"+((Canli)varliklar[j]).yas);   
   
/***BOLUM 4: nesnelerin esitligi ile ilgili işlemler yapalım***/
        //equals metodu Object sinifinda zaten tanimli...tanimi soyle Object.equals (Object o)
        //fakat biz Varlik sinifinda equals metodunu overload ediyoruz
      System.out.println("\nBolum 4 ............................");
      System.out.println("o1 ve o2 esit mi (bizim equal metodu ile): "+ o1.equals(o2));
      Ogrenci o5= new Ogrenci (o1.oku_isim());   
      System.out.println("o1 ve o5 esit mi(bizim equal metodu ile): "+ o1.equals(o5));
      System.out.println("o1 ve o5 esit mi(varsayilan Oject.equal metodu ile): "+ o1.equals((Object)o5));
      o1=o5;
      System.out.println("o1=o5 atamasından sonra (varsayilan Oject.equal metodu ile): "+ o1.equals((Object)o5));
    }
}

 class Varlik {
    static int varliksayisi=0;
    private double agirlik; 
    private String isim;
   
    Varlik(){ //varsayılan isimle yarat
        varliksayisi++;
        isim="Varlik"+varliksayisi;    
    } 
    Varlik(String ad){ //verilen isimle yarat
        isim=ad;
        varliksayisi++;
               
    }
    public double oku_agirlik(){ return agirlik; }
    public String oku_isim(){return isim;}
    public void set_isim(String s) {isim=s;}
    public void set_agirlik(double kg) {agirlik=kg;}
       
    public boolean equals (Varlik a){
        return a.isim.equals(isim);
    }
    
   
 }


class Canli extends Varlik{
   static int canlisayisi=0;
   float  sutuketimi; //günlük su tüketimi olsun
   int yas;
   
   Canli(String ad){
     set_isim(ad);
     canlisayisi++;
   }
   Canli() {  
       canlisayisi++;
       set_isim("Canli"+canlisayisi);   //varsayılan isim
   } 
   
}

//Insan: varsayılan olarak 1 yaşında 2.5 kg, adı "Insanxxx" olan erkek bir bebek olsun
class Insan extends Canli{  
    static int insansayisi=0;
    String meslek="yok";  //en basit ilklendirme yolu = tanımlanırken ilklendirme
    String medenihali="bekar"; //evli, bekar, dul
    char cinsiyet = 'E'; //E(rkek) ve K(ız)
    
    {//instans ilklendirici, bazı ilklendirmeleri burada da yapabiliriz yada yapılandırıcı da yapabiliriz
      set_agirlik(2.5);
      sutuketimi=0.2f;
      yas=1;
    }
     
    Insan(){ //varsayılan isimle yarat
       super("Insan" + ++insansayisi); //supersınıfın (atasının) ilgili yapılandırıcısını (bu durumda String parametreli olan) işletir. 
       //yazılmazsa yapılandırıcının ilk satırında parametresiz gizli bir super(); çağırımı vardır.
    }
    Insan(String ad) { //verilen isimle yarat
       super();   //super() zaten gizli olarak var..yazmamıza gerek yoktu.
       set_isim(ad); 
       ++insansayisi;
    }
    
    static void yazdır(Insan i) { //verilen insana ait bilgileri yazdırsın
       System.out.println("adı:"+ i.oku_isim());
       System.out.println("agirlik:"+ i.oku_agirlik());
       System.out.println("su tüketimi:"+ i.sutuketimi);
       System.out.println("yas:"+ i.yas);
       System.out.println("cinsiyet:"+ i.cinsiyet);
       System.out.println("meslek:"+ i.meslek);       
    }
    
}

class Ogrenci extends Insan {
  static final int MAXDERSSAYISI=20;  //bu sınıf altında global constant
  static int ogrencisayisi=0; 
  String okulad;  //instans değişkenleri otomatik null(sıfır)lanır, varsayılan "" değerini görürsünüz
  int derssayisi=0;  //ilklendirme yapmasakta otomatik sifir olurdu
  private Ders [] dersler; 
  
  Ogrenci(String ad) {
      super(ad);
      ogrencisayisi++;
      meslek="ogrenci";
      dersler= new Ders[MAXDERSSAYISI]; 
  }
  
  Ogrenci() {
    super("Ogrenci" + ++ogrencisayisi);
    meslek="ogrenci";
    dersler= new Ders[MAXDERSSAYISI]; 
  }
  
  //ders basarili eklenirse true yoksa false donsun. dersler MAXDERSSAYISINI asmasin
  boolean dersekle(Ders d) {
    if (derssayisi<MAXDERSSAYISI) {     
       dersler[derssayisi]=d;    
       derssayisi++;
       return true;  //burada exit olsun
    }
    return false; //buraya gelmisse maxderssayisina ulasilmis demektir
  }
  
  
}


class Ders {
  static int derssayisi=0;
  String adi; 
  int vizenotu;
  int finalnotu;
  Insan hocasi;
  Ders(){
    derssayisi++;
    adi="Ders"+derssayisi; //varsayılan ders adı
  }
}