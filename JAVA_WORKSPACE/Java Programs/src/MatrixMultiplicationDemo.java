class MatrixMultiplier extends Thread{
	private final int[][] matrixA;
	private final int[][] matrixB;
	private final int[][] result;
	final int row;
	final int column;
	
	public MatrixMultiplier(int[][] matrixA,int[][] matrixB,int[][] result,int row,int column) {
		this.column=column;
		this.matrixA=matrixA;
		this.matrixB=matrixB;
		this.row=row;
		this.result=result;
	}
	public void run() {
		int i=0;
		int sum =0;
		for(i=0;i<matrixA.length;i++) {
			sum=sum+(matrixA[row][i]*matrixB[i][column]);
			
		}
		result[row][column]=sum;
		
	}
}
public class MatrixMultiplicationDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[][] matrixA = {{1,1,1},{2,2,2},{3,3,3}};
		int[][] matrixB = {{4,4,4},{5,5,5},{6,6,6}};
		int[][] result = new int[matrixA.length][matrixA[0].length];
		Thread[][] thread = new Thread[matrixA.length][matrixA[0].length];
		int i;
		int j;
		for(i=0;i<matrixA.length;i++) {
			for(j=0;j<matrixA[0].length;j++) {
				 thread[i][j] = new MatrixMultiplier(matrixA,matrixB,result,i,j);
				thread[i][j].start();
			}
		}
		
		try {
			for ( i = 0; i < matrixA.length; i++) {
				for ( j = 0; j < matrixB[0].length; j++) {
					thread[i][j].join();
				}
			}
		} catch (InterruptedException e) {
			e.printStackTrace();
		}

		// Display the result matrix
		System.out.println("Result Matrix:");
		for ( i = 0; i < result.length; i++) {
			for ( j = 0; j < result[0].length; j++) {
				System.out.print(result[i][j] + " ");
			}
			System.out.println();
		}
		
	}

}

