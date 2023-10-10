package A7;
import java.util.Scanner;

public class Q2 {
    interface Driver {
        default int driveCar(int age) {
            if (age < 40) {
                System.out.println("Driving Car");
                return 10;
            } else {
                System.out.println("Driving Car");
                return 0;
            }
        }

        default int driveBike(int age) {
            if (age < 40) {
                System.out.println("Driving Bike");
                return 5;
            } else {
                System.out.println("Driving Bike");
                return 0;
            }
        }
    }

    interface Singer {
        default int sing(int age) {
            if (age < 20) {
                System.out.println("Singing");
                return 15;
            } else {
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

        int officeWork() {
            if (age < 40) {
                System.out.println("Office work");
                return 20;
            } else {
                System.out.println("Office work");
                return 10;
            }
        }


        public int driveCar() {
            return Driver.super.driveCar(age);
        }


        public int driveBike() {
            return Driver.super.driveBike(age);
        }


        public int sing() {
            return Singer.super.sing(age);
        }

        @Override
        public void riyaz() {
            Singer.super.riyaz();
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int age;

        System.out.print("Enter your age: ");
        age = scanner.nextInt();

        Employee employee = new Employee(age);

        int choice;

        do {
            System.out.println("Menu:");
            System.out.println("1. Employee as Driver");
            System.out.println("2. Employee as Singer");
            System.out.println("3. Employee as Person");
            System.out.println("4. Office Work");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    Driver driver = employee;
                    int r1 = driver.driveCar(age);
                    int r2 = driver.driveBike(age);
                    System.out.println("Returned value of driveCar: " + r1);
                    System.out.println("Returned value of driveBike: " + r2);
                    break;

                case 2:
                    Singer singer = employee;
                    int r = singer.sing(age);
                    singer.riyaz();
                    System.out.println("Returned value of sing: " + r);
                    break;

                case 3:
                    Person person = employee;
                    person.eat();
                    person.sleep();
                    break;

                case 4:
                    int returnedVal = employee.officeWork();
                    System.out.println("Returned value of officeWork: " + returnedVal);
                    break;

                case 5:
                    System.out.println("Exiting the program.");
                    break;

                default:
                    System.out.println("Invalid choice. Please try again.");
            }

        } while (choice != 5);
    }
}