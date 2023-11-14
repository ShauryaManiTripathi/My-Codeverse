import java.util.Scanner;

class InvalidEmailException extends Exception {
    public InvalidEmailException(String message) {
        super(message);
    }
}
class InvalidPINException extends Exception {
    public InvalidPINException(String message) {
        super(message);
    }
}

class InvalidRollNumberException extends Exception {
    public InvalidRollNumberException(String message) {
        super(message);
    }
}

class InvalidEmployeeIDException extends Exception {
    public InvalidEmployeeIDException(String message) {
        super(message);
    }
}

class Person {
    private String firstName;
    private String lastName;
    private String PAN;
    private String address;
    String PIN;

    public Person(String firstName, String lastName, String PAN, String address, String PIN) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.PAN = PAN;
        this.address = address;
        this.PIN = PIN;
    }
}

class Student extends Person {
    private String emailID;
    private String rollNumber;

    public Student(String firstName, String lastName, String PAN, String address, String PIN, String emailID, String rollNumber) {
        super(firstName, lastName, PAN, address, PIN);
        this.emailID = emailID;
        this.rollNumber = rollNumber;
    }
    public boolean validate() throws InvalidEmailException, InvalidPINException, InvalidRollNumberException {
        if (!PIN.matches("\\d{6}")) {
            throw new InvalidPINException("Invalid PIN code");
        }
        if (!rollNumber.matches("stud\\d{5}")) {
            throw new InvalidRollNumberException("Invalid Roll Number");
        }
        if (!emailID.matches("[A-Za-z0-9!@#\\\\$&*]+@[A-Za-z]+\\\\.[A-Za-z]+")) {
            throw new InvalidEmailException("Invalid Email ID");
        }
        return true;
    }
}

class Employee extends Person {
    private String emailID;
    private String employeeID;

    public Employee(String firstName, String lastName, String PAN, String address, String PIN, String emailID, String employeeID) {
        super(firstName, lastName, PAN, address, PIN);
        this.emailID = emailID;
        this.employeeID = employeeID;
    }
    public boolean validate() throws InvalidEmailException, InvalidPINException, InvalidEmployeeIDException {
        if (!PIN.matches("\\d{6}")) {
            throw new InvalidPINException("Invalid PIN code");
        }

        if (!employeeID.matches("emp\\d{3}")) {
            throw new InvalidEmployeeIDException("Invalid Employee ID");
        }

        if (!emailID.matches("[A-Za-z0-9!@#\\\\$&*]+@[A-Za-z]+\\\\.[A-Za-z]+")) {
            throw new InvalidEmailException("Invalid Email ID");
        }
        return true;
    }
}

public class Information {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            System.out.println("Enter student information:");
            System.out.print("First Name: ");
            String firstName = scanner.next();
            System.out.print("Last Name: ");
            String lastName = scanner.next();
            System.out.print("PAN: ");
            String PAN = scanner.next();
            System.out.print("Address: ");
            String address = scanner.next();
            System.out.print("PIN: ");
            String PIN = scanner.next();
            System.out.print("Email ID: ");
            String emailID = scanner.next();
            System.out.print("Roll Number: ");
            String rollNumber = scanner.next();

            Student student = new Student(firstName, lastName, PAN, address, PIN, emailID, rollNumber);

            student.validate();
            System.out.println("Student information is valid.");
        } catch (InvalidEmailException | InvalidPINException | InvalidRollNumberException e) {
            System.out.println("Error: " + e.getMessage());
        }

        try {
            System.out.println("\nEnter employee information:");
            System.out.print("First Name: ");
            String firstName = scanner.next();
            System.out.print("Last Name: ");
            String lastName = scanner.next();
            System.out.print("PAN: ");
            String PAN = scanner.next();
            System.out.print("Address: ");
            String address = scanner.next();
            System.out.print("PIN: ");
            String PIN = scanner.next();
            System.out.print("Email ID: ");
            String emailID = scanner.next();
            System.out.print("Employee ID: ");
            String employeeID = scanner.next();

            Employee employee = new Employee(firstName, lastName, PAN, address, PIN, emailID, employeeID);

            employee.validate();
            System.out.println("Employee information is valid.");
        } catch (InvalidEmailException | InvalidPINException | InvalidEmployeeIDException e) {
            System.out.println("Error: " + e.getMessage());
        }
        try {
            int[] arr = new int[3];
            int value = arr[4];
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("ArrayIndexOutOfBoundsException: " + e.getMessage());
        }
        try {
            String str = null;
            int length = str.length();
        } catch (NullPointerException e) {
            System.out.println("NullPointerException: " + e.getMessage());
        }

        scanner.close();
    }
}