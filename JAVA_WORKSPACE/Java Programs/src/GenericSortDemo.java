import java.util.Arrays;

public class GenericSortDemo {
	
	public <T> void swap( T array[],int i,int j) {
		if(i!=j) {
			T temp=array[i];
			array[i]=array[j];
			array[j]=temp;
		}
	}
	
	public <T extends Comparable<T>> void sort(T array[]) {
		for(int i=0;i<array.length;i++) {
			int small=i;
			for(int j=i+1;j<array.length;j++) {
				if(array[j].compareTo(array[small])<=0) {
					small=j;
				}
			}
			swap(array,i,small);
			
		}
	}


	public static void main(String[] args) {
		// TODO Auto-generated method stub
		GenericSortDemo gs=new GenericSortDemo();
		Integer num[]= {5,3,2,8,5};
		System.out.println("befort sort"+Arrays.toString(num));
		gs.sort(num);
		System.out.println("After sort"+Arrays.toString(num));
		
		String str[] = { "mango", "grapes", "cherry", "apple", "orange" };
		System.out.println("Before Sort: " + Arrays.toString(str));
		gs.sort(str);
		System.out.println("After Sort: " + Arrays.toString(str));
	}

}
