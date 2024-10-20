package sdmcet.cse.oop.main;
import sdmcet.cse.oop.basic.*;
import sdmcet.cse.oop.advance.*;


public class MathTestDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a[][]={{1,2,3},{4,5,6},{4,6,8}};
		
		BasicMath b1= new BasicMath();
		if(b1.primeCheck(11)) {
			System.out.println(11 + " Number is prime");
		}
		else
		{
			System.out.println("Number is not prime");
		}
		System.out.println();
		
		System .out.println("Sum Of digits of 456 is "+b1.sumOfDigits(456));
		System.out.println();
		
		AdvanceMath a1=new AdvanceMath();
		
		System.out.println("Sin: "+a1.sinCalculate(20.5));
		System.out.println("Cos"+a1.cosCalculate(20.5));
		System.out.println("tan"+a1.tanCalculate(20.5));
		System.out.println();
		
		
		System.out.println("Sum of primary digonal matrix is: " +a1.primaryDiagonal(a));
		
	}

}
