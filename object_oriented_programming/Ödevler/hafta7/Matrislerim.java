// Ad Soyad:

package lab3;

public class Matrislerim {
	 int [][] matris1;
	 int [][] matris2;

	
	 static ... randomMatris (int N) {//elemanları [1 2*N] arasında olan [N x N] random matris oluştur.
		...
	}
	
	 void setMatris(byte m , int [][] mat) {
		
		//m =1 ise matris1 'i , m=2 ise matris2' yi değiştir.  
	}
	
	void setMatris(byte m , String mat) { //overload metod
		
		//m =1 ise matris1 'i , m=2 ise matris2' yi değiştir.  
	}
	
	 ... getMatris(byte m ) {
		
		//m =1 ise matris1 'i , m=2 ise matris2' yi return et.  
	}
	
	
     private... topla(){ //matris1+matris2  işlemini yap ve sonucu return et. 
	 ...
	} 
	
	 private... carp(){ //matris1*matris2  işlemini yap ve sonucu return et. 
	 ...
	}
    public void matrisYazdir(int [][] mat) {
		
		//verilen matris 'i her kolonu hizalı olacak şekilde ekrana yazdır.  
	}
	
    public static void main(String[] args) {
		
        Matrislerim m = new Matrislerim();
        m.setMatris(1,Matrislerim.randomMatris(8));
        m.setMatris(2,Matrislerim.randomMatris(8));		
		int [][] sonuc=m.topla();
		m.matrisYazdır(sonuc); 
		
	}
}