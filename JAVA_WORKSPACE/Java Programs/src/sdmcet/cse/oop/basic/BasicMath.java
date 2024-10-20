package sdmcet.cse.oop.basic;

public class BasicMath {
		public boolean primeCheck(int num) {
			if(num==0) {
				 return false;
			}
			for(int i=2;i<num/2;i++) {
				if(num%i==0)
					return false;
			}
			return true;
		}
		
		public int sumOfDigits(int num) {
			int sum=0;
			
			while(num!=0) {
				int digit=num %10;
				sum+=digit;
				num/=10;
			}
			
			return sum;
			
		}
}
