package paket1;

public class Daire {
	private double r;
	private String color;
	
	static int daireSayisi = 0;

	//yapilandirici , constructor
	Daire(){
		this.r = 1.0;
		this.color = "siyah";
		daireSayisi++;
	}
	
	Daire(double r){
		this.r = r;
		this.color = "siyah";
		daireSayisi++;
	}
	
	Daire(double r, String color){
		this.r = r;
		this.color = color;
		daireSayisi++;
	}
	
	public void setR(double r) {
		this.r = r;
	}
	
	public void setColor(String color) {
		this.color = color;
	}
	
	public double getR() {
		return this.r;
	}
	
	public String getColor() {
		return this.color;
	}
	
	public void daireYazdir() {
		System.out.println("Daire: " + daireSayisi+" Yaricap: " + this.r + " Renk: " + this.color);
	}
	
	public double cevre() {
		return 2*Math.PI*this.r;
	}
	
	public double alan() {
		return Math.PI * Math.pow(r, 2);
	}
}
