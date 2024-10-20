import java.util.*;
class Student{
	int rollno;
	String usn;
	int semester;
	String divison;
	
	public Student(int rollno,String usn,int semester,String divison) {
		this.rollno=rollno;
		this.usn=usn;
		this.semester=semester;
		this.divison=divison;
	}
	public void display() {
		System.out.println("Roll number "+rollno);
		System.out.println("USN "+usn);
		System.out.println("Semster "+semester);
		System.out.println("Divison "+ divison);
		
	}
}
public class PostgraduateDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Vector<Student> vStudent= new Vector<Student>(20,5);
		Scanner sc=new Scanner(System.in);
		System.out.println("Request to increase capacity");
		char resp=sc.next().charAt(0);
		if(resp=='y'|| resp=='n') {
			if(resp=='y') {
				vStudent.ensureCapacity(25);
				System.out.println("The Current Capacity: " + vStudent.capacity());
			}
			else
			{
				System.out.println("Invalid choice");
			}
		}
		
		vStudent.addElement(new Student(1,"2sd22cs108",4,"H"));
		vStudent.addElement(new Student(2,"2sd22cs109",4,"H"));
		vStudent.addElement(new Student(3,"2sd22cs106",4,"H"));
		
		System.out.println("students got enrolled");
		for(Student st:vStudent) {
			st.display();
		}
		
		vStudent.removeElementAt(1);
		vStudent.removeElementAt(1);
		System.out.println("\nRoll no : 2 and Roll No: 3 Voluntarily unrolled from the course");
		
		vStudent.addElement(new Student(2, "2SD22CS021", 4, "H"));
		vStudent.addElement(new Student(3, "2SD22CS022", 4, "H"));
		System.out.println("After a Month two students are enrolled");
		
		System.out.println("Current Infomation of all the Students Enrolled");
		for (Student st : vStudent) {
			st.display();
		}

	}

}
