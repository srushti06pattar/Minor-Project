package sdmcet.cse.oop.advance;

public class AdvanceMath {
	
	public double sinCalculate(double degree) {
		return Math.sin(Math.toRadians(degree));	
	}
	public double cosCalculate(double degree) {
		return Math.sin(Math.toRadians(degree));
	}
	public double tanCalculate(double degree) {
		return Math.sin(Math.toRadians(degree));
	}
	
	public int primaryDiagonal(int a[][]) {
		int sum=0;
		for(int i=0;i<a.length;i++) {
			for(int j=0;j<a.length;j++) {
				if(i==j)
					sum+=a[i][i];
			}
		}
		return sum;
	}
}
