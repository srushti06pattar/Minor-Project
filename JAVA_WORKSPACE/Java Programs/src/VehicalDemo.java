class Vehicle{
	private String engineeno;
	private String chasseno;
	private String manfacturer;
	
	public Vehicle(String engineeno,String chaseeno,String manfacturer) {
		this.engineeno=engineeno;
		this.chasseno=chaseeno;
		this.manfacturer=manfacturer;
	}
	public void display() {
		System.out.println("Enginee number" +engineeno);
		System.out.println("Chasee number" +chasseno);
		System.out.println("Manfacturer " +manfacturer);
		
	}
}
class Car extends Vehicle {
	private int wheels;

	public Car(int wheels, String engineeno, String chasseno, String manufacturer) {
		super(engineeno, chasseno, manufacturer);
		this.wheels = wheels;
	}
	public void display() {
		System.out.println("Wheels Number: " + wheels);
		super.display();
	}
}
class Bike extends Vehicle {
	private int wheels;

	public Bike(int wheels, String engineeno, String chasseno, String manufacturer) {
		super(engineeno, chasseno, manufacturer);
		this.wheels = wheels;
	}
	public void display() {
		System.out.println("Wheels Number: " + wheels);
		super.display();
	}
}
class Truck extends Vehicle {
	private int wheels;

	public Truck(int wheels, String engineeno, String chasseno, String manufacturer) {
		super(engineeno, chasseno, manufacturer);
		this.wheels = wheels;
	}
	public void display() {
		System.out.println("Wheels Number: " + wheels);
		super.display();
	}
}

public class VehicalDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Car mycar=new Car(4,"2sd","34d","adi");
		Bike mybike= new Bike(2,"3sd","45d","sru");
		Truck mytruck=new Truck(6,"4sd","76d","asg");
		
		System.out.println("Car deatils");
		mycar.display();
		System.out.println();
		System.out.println("Bike deatils");
		mybike.display();
		System.out.println();
		System.out.println("Truck deatils");
		mytruck.display();
		
		
	}

}
