class TemperatureException extends Exception{
	String title;
	
	public TemperatureException (String title) {
		this.title=title;
	}
	public String toString() {
		return title;
	}
}
public class TemperatureDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int temp=100;
		
		if(temp>300) {
			try {
				throw new TemperatureException("temperture is excedd than 300 degree");
			}catch(TemperatureException t) {
				t.printStackTrace();
			}
		}
		else if(temp<30) {
			try {
				throw new TemperatureException("temperture is very less than 300 degree");
			}catch(TemperatureException t) {
				t.printStackTrace();
			}
		}
		else {
			System.out.println("temperature is normal");

	}
	}
}
