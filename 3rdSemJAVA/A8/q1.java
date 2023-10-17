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
            students.add(new Student("Swayam NPTEL", 1, "2000"));
            students.add(new Student("UP police", 2, "1999"));
            students.add(new Student("Snehansu Depp", 3, "2001"));
            students.add(new Student("David Lal", 4, "2002"));
            students.add(new Student("Ama de armas", 5, "1998"));

            int n;
            System.out.println("Enter the number of xtra students you want to add...");
            n = sc.nextInt();
            for(int i=0;i<n;i++){
                System.out.println("Enter the name of the student");
                String name = sc.next();
                System.out.println("Enter the roll number of the student");
                int roll = sc.nextInt();
                System.out.println("Enter the birthyear of the student");
                String birthyear = sc.next();
                students.add(new Student(name,roll,birthyear));
            }
    
            System.out.println("So sorting will be based on???");
            System.out.println("1)first name");
            System.out.println("2)title");
            System.out.println("3)reverse order of their roll number");
            System.out.println("4)ascending order of their birthyear");
    
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
    
            System.out.println("Sorted List:");
            for (Student student : students) {
                System.out.println(student);
            }
        }
}
