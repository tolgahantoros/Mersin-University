package paket1;

public class MainClass {

	public static void main(String[] args) {
		Daire d1;
		d1 = new Daire();
		d1.daireYazdir();
		
		double alanD1 = d1.alan();
		
		
		//d1.setR(2.4);
		//d1.setColor("mavi");
		
		//d1.daireYazdir();
		
		
		Daire d2;
		d2 = new Daire(2.5);
		d2.daireYazdir();
		//d2.setColor("sari");
		//d2.daireYazdir();
		
		Daire d3 = new Daire();
		d3.daireYazdir();
		
		System.out.println("1. dairenin yaricapi: " + d1.getR());
		System.out.println("1. dairenin rengi: " + d1.getColor());
		
		System.out.println(Daire.daireSayisi);
		
		System.out.println("E: " + Math.E + "PI: " + Math.PI);
		
	}

}
