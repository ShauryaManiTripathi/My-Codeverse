import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;
class Student implements Comparable<Student> {
    String name;
    int roll;
    String birthyear;

    public Student(String name, int roll, String birthyear) {
        this.name = name;
        this.roll = roll;
        this.birthyear = birthyear;
    }

    @Override
    public int compareTo(Student other) {
        // Default comparison for sorting by name
        return this.name.compareTo(other.name);
    }

    @Override
    public String toString() {
        return "Name: " + name + ", Roll: " + roll + ", Birthyear: " + birthyear;
    }
}

public class q1 {
    
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            ArrayList<Student> students = new ArrayList<>();
    
            // Add 5 student objects to the ArrayList
            students.add(new Student("Alice Smith", 102, "2000"));
            students.add(new Student("Bob Johnson", 105, "1999"));
            students.add(new Student("Charlie Brown", 103, "2001"));
            students.add(new Student("David Lee", 101, "2002"));
            students.add(new Student("Eve Miller", 104, "1998"));
    
            System.out.println("How would you like to sort the students?");
            System.out.println("1) With respect to the first name");
            System.out.println("2) With respect to the title");
            System.out.println("3) In the reverse order of their roll number");
            System.out.println("4) In the ascending order of their birthyear");
    
            int choice = sc.nextInt();
    
            switch (choice) {
                case 1:
                    // Sort by first name
                    Collections.sort(students);
                    break;
                case 2:
                    // Sort by title (assuming titles are the last word in the name)
                    Collections.sort(students, Comparator.comparing(s -> s.name.split(" ")[s.name.split(" ").length - 1]));
                    break;
                case 3:
                    // Sort in reverse order of roll number
                    Collections.sort(students, Collections.reverseOrder(Comparator.comparingInt(s -> s.roll)));
                    break;
                case 4:
                    // Sort in ascending order of birth year
                    Collections.sort(students, Comparator.comparing(s -> s.birthyear));
                    break;
                default:
                    System.out.println("Invalid choice.");
                    return;
            }
    
            System.out.println("Sorted students:");
            for (Student student : students) {
                System.out.println(student);
            }
        }
}
