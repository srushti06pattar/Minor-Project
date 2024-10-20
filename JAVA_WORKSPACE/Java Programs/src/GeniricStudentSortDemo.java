import java.util.Scanner;

class Stud implements Comparable<Stud> {
	String usn;
	String firstName;
	String lastName;
	String branch;
	String division;
	int sortOption;

	public Stud(String usn, String firstName, String lastName, String branch, String division, int sortOption) {
		this.usn = usn;
		this.firstName = firstName;
		this.lastName = lastName;
		this.branch = branch;
		this.division = division;
		this.sortOption = sortOption;
	}

	public static void sortStudents(Stud[] students) {
		for (int i = 0; i < students.length - 1; i++) {
			for (int j = 0; j < students.length - i - 1; j++) {
				if (students[j].compareTo(students[j + 1]) > 0) {
					Stud temp = students[j];
					students[j] = students[j + 1];
					students[j + 1] = temp;
				}
			}
		}
	}

	@Override
	public int compareTo(Stud other) {
		switch (sortOption) {
		case 1:
			return this.usn.compareTo(other.usn);
		case 2:
			return this.firstName.compareTo(other.firstName);
		case 3:
			return this.division.compareTo(other.division);
		default:
			return -1;
		}
	}

	public void displayDetails() {
		System.out.println("USN: " + usn + " | Name: " + firstName + " " + lastName + " | Branch: " + branch
				+ " | Division: " + division);
	}
}

public class GeniricStudentSortDemo {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("Enter sort option (1: USN, 2: First Name, 3: Division): ");
		int sortOption = scanner.nextInt();

		Stud students[] = { new Stud("2SD22CS115", "John", "Doe", "Computer Science", "A", sortOption),
				new Stud("2SD22CS101", "Bane", "Smith", "Electronics", "B", sortOption),
				new Stud("2SD22CS100", "Alice", "Johnson", "Mechanical", "A", sortOption),
				new Stud("2SD22CS088", "Suraj", "Gunagi", "Civil", "C", sortOption),
				new Stud("2SD22CS181", "Henry", "Classin", "Mechanical", "D", sortOption) };
		Stud.sortStudents(students);

		System.out.println("Sorted Students:");
		for (Stud st : students) {
			st.displayDetails();
		}
	}
}