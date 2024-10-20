class Prime extends Thread{
	int lower;
	int upper;

	
	public Prime(int lower,int upper) {
		this.lower=lower;
		this.upper=upper;

	}
	public void run() {
		generatePrime(lower,upper);
	
	}
	
	public synchronized void generatePrime(int lower,int upper) {
		for(int i=lower;i<upper;i++) {
			if(isPrime(i)) {
				System.out.println(Thread.currentThread().getName()+":"+i);
			}		
		}
		
	}
	public boolean isPrime(int n) {
		if(n<=1)
			return false;
		for(int i=2;i<=Math.sqrt(n);i++) {
			if(n%i==0) {
				return false;
			}
		}return true;
	}
}
	

public class primeDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Prime thread1=new Prime(1,100);
		Prime thread2=new Prime(101,200);
		Prime thread3=new Prime(201,300);
		

		try {
			thread1.start();
			thread1.join();
			thread2.start();
			thread2.join();
			thread3.start();
			thread3.join();
		}catch(InterruptedException e) {
			e.printStackTrace();
		}
		

	}

}
