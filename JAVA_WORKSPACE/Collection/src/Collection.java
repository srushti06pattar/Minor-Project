import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

class Student {
    int rollNo;
    String usn;
    String name;
    int semester;
    String mobileNumber;

    public Student(int rollNo, String usn, String name, int semester, String mobileNumber) {
        this.rollNo = rollNo;
        this.usn = usn;
        this.name = name;
        this.semester = semester;
        this.mobileNumber = mobileNumber;
    }

    @Override
    public String toString() {
        return "Roll No: " + rollNo + ", USN: " + usn + ", Name: " + name +
                ", Semester: " + semester + ", Mobile Number: " + mobileNumber;
    }
}

public class Collection {
    List<Student> students;
    int capacity;

    public Collection(int capacity) {
        this.capacity = capacity;
        students = new ArrayList<>(capacity);
    }

    public void increaseCapacity(int newCapacity) {
        if (newCapacity > capacity) {
            this.capacity = newCapacity;
            System.out.println("Course capacity increased to: " + newCapacity);
        } else {
            System.out.println("New capacity must be greater than current capacity.");
        }
    }

    public boolean enrollStudent(Student student) {
        if (students.size() < capacity) {
            students.add(student);
            System.out.println("Student enrolled: " + student.name);
            return true;
        } else {
            System.out.println("Course is full. Cannot enroll student: " + student.name);
            return false;
        }
    }

    public boolean unrollStudent(int rollNo) {
        Iterator<Student> iterator = students.iterator();
        while (iterator.hasNext()) {
            Student student = iterator.next();
            if (student.rollNo == rollNo) {
                iterator.remove();
                System.out.println("Student unrolled: " + student.name);
                return true;
            }
        }
        System.out.println("Student with Roll No: " + rollNo + " not found.");
        return false;
    }

    public void printEnrolledStudents() {
        System.out.println("Students currently enrolled:");
        for (Student student : students) {
            System.out.println(student);
        }
    }

    public static void main(String[] args) {
        Collection course = new Collection(20);

        // i) On request, the capacity was increased from 20 to 25
        course.increaseCapacity(25);

        // ii) Only 3 students enroll for the course
        Student s1 = new Student(1, "USN001", "Alice", 1, "1234567890");
        Student s2 = new Student(2, "USN002", "Bob", 1, "0987654321");
        Student s3 = new Student(3, "USN003", "Charlie", 1, "1122334455");
        course.enrollStudent(s1);
        course.enrollStudent(s2);
        course.enrollStudent(s3);

        // iii) Two students bearing Roll Numbers 2 and 3 voluntarily unroll from the course
        course.unrollStudent(2);
        course.unrollStudent(3);

        // iv) After a month, two students get enrolled in the course
        Student s4 = new Student(4, "USN004", "David", 1, "6677889900");
        Student s5 = new Student(5, "USN005", "Eva", 1, "5566778899");
        course.enrollStudent(s4);
        course.enrollStudent(s5);

        // v) Print the information of all the students currently enrolled in the course
        course.printEnrolledStudents();
    }
}
