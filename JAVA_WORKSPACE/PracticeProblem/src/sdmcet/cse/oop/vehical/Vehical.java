package sdmcet.cse.oop.vehical;

class Vehicle {
    int wheels;

    Vehicle(int wheels) {
        this.wheels = wheels;
    }

    void displayInfo() {
        System.out.println("Number of wheels: " + wheels);
    }
}

class Car extends Vehicle {
    String engineNumber;
    String chassisNumber;
    String manufacturer;

    Car(int wheels, String engineNumber, String chassisNumber, String manufacturer) {
        super(wheels);
        this.engineNumber = engineNumber;
        this.chassisNumber = chassisNumber;
        this.manufacturer = manufacturer;
    }

    @Override
    void displayInfo() {
        super.displayInfo();
        System.out.println("Car Engine Number: " + engineNumber);
        System.out.println("Car Chassis Number: " + chassisNumber);
        System.out.println("Car Manufacturer: " + manufacturer);
    }
}

class Bike extends Vehicle {
    String engineNumber;
    String chassisNumber;
    String manufacturer;

    Bike(int wheels, String engineNumber, String chassisNumber, String manufacturer) {
        super(wheels);
        this.engineNumber = engineNumber;
        this.chassisNumber = chassisNumber;
        this.manufacturer = manufacturer;
    }

    @Override
    void displayInfo() {
        super.displayInfo();
        System.out.println("Bike Engine Number: " + engineNumber);
        System.out.println("Bike Chassis Number: " + chassisNumber);
        System.out.println("Bike Manufacturer: " + manufacturer);
    }
}

class Truck extends Vehicle {
    String engineNumber;
    String chassisNumber;
    String manufacturer;

    Truck(int wheels, String engineNumber, String chassisNumber, String manufacturer) {
        super(wheels);
        this.engineNumber = engineNumber;
        this.chassisNumber = chassisNumber;
        this.manufacturer = manufacturer;
    }

    @Override
    void displayInfo() {
        super.displayInfo();
        System.out.println("Truck Engine Number: " + engineNumber);
        System.out.println("Truck Chassis Number: " + chassisNumber);
        System.out.println("Truck Manufacturer: " + manufacturer);
    }
}

public class Vehical {
    public static void main(String[] args) {
        Car car = new Car(4, "C123", "CH123", "Toyota");
        Bike bike = new Bike(2, "B456", "CH456", "Honda");
        Truck truck = new Truck(6, "T789", "CH789", "Ford");

        car.displayInfo();
        System.out.println();
        bike.displayInfo();
        System.out.println();
        truck.displayInfo();
    }
}



