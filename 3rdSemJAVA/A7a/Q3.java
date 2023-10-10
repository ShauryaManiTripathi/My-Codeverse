package A7;

import java.util.Arrays;
import java.util.Scanner;

public class Q3 {
    interface Driver {
        default int driveCar(int age,boolean explicit) {
            if (age < 40) {
                if(explicit)
                System.out.println("Driving Car");
                return 10;
            } else {
                if(explicit)
                System.out.println("Driving Car");
                return 0;
            }
        }

        default int driveBike(int age,boolean explicit) {
            if (age < 40) {
                if(explicit)
                System.out.println("Driving Bike");
                return 5;
            } else {
                if(explicit)
                System.out.println("Driving Bike");
                return 0;
            }
        }
    }

    interface Singer {
        default int sing(int age,boolean explicit) {
            if (age < 20) {
                if(explicit)
                System.out.println("Singing");
                return 15;
            } else {
                if(explicit)
                System.out.println("Singing");
                return 0;
            }
        }

        default void riyaz() {
            System.out.println("Riyaz");
        }
    }

    static class Person {
        int age;

        Person() {
        }

        Person(int age) {
            this.age = age;
        }

        void eat() {
            System.out.println("Eating");
        }

        void sleep() {
            System.out.println("Sleeping");
        }
    }

    static class Employee extends Person implements Driver, Singer {
        Employee(int age) {
            super(age);
        }

        int officeWork(boolean explicit) {
            if (age < 40) {
                if(explicit)
                System.out.println("Office work");
                return 20;
            } else {
                if(explicit)
                System.out.println("Office work");
                return 10;
            }
        }

        public int driveCar(boolean explicit) {
            return Driver.super.driveCar(age,explicit);
        }

        public int driveBike(boolean explicit) {
            return Driver.super.driveBike(age,explicit);
        }

        public int sing(boolean explicit) {
            return Singer.super.sing(age,explicit);
        }

        @Override
        public void riyaz() {
            Singer.super.riyaz();
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Employee[] employees = new Employee[5];
        int[] employeeEIFs = new int[5];

        for (int i = 0; i < 5; i++) {
            System.out.print("Enter age for Employee " + (i + 1) + ": ");
            int age = scanner.nextInt();
            employees[i] = new Employee(age);
            employeeEIFs[i] = employees[i].driveCar(false) + employees[i].driveBike(false) +
                    employees[i].sing(false) + employees[i].officeWork(false);
        }

        sort(employees, employeeEIFs);

        System.out.println("\nSorted Employees by Employee Importance Factor (EIF):");
        for (Employee employee : employees) {
            System.out.println("Age: " + employee.age + ", EIF: " +
                    (employee.driveCar(false) + employee.driveBike(false) +
                            employee.sing(false) + employee.officeWork(false)));
        }
    }

    static void sort(Employee[] employees, int[] eifs) {
        int n = employees.length;
        for (int i = 1; i < n; i++) {
            Employee keyEmployee = employees[i];
            int keyEIF = eifs[i];
            int j = i - 1;
            while (j >= 0 && eifs[j] < keyEIF) {
                employees[j + 1] = employees[j];
                eifs[j + 1] = eifs[j];
                j = j - 1;
            }
            employees[j + 1] = keyEmployee;
            eifs[j + 1] = keyEIF;
        }
    }

}