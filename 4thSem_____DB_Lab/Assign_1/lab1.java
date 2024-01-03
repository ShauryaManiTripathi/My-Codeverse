import java.io.*;
import java.util.*;

class Instructor {
    int ID;
    String name;
    String dept_name;
    int salary;

    public Instructor(int ID, String name, String dept_name, int salary) {
        this.ID = ID;
        this.name = name;
        this.dept_name = dept_name;
        this.salary = salary;
    }

}

class Department {
    String dept_name;
    int building;
    int budget;

    public Department(String dept_name, int building, int budget) {
        this.dept_name = dept_name;
        this.building = building;
        this.budget = budget;
    }
}

class lab1 {
    public static void main() {
        Scanner instr, dept;
        ArrayList<Instructor> instructors = new ArrayList<Instructor>();
        ArrayList<Department> departments = new ArrayList<Department>();
        int maxDeptBudget = -99999999;
        try {
            instr = new Scanner(new File("instructor.txt"));
            dept = new Scanner(new File("department.txt"));
            try {
                while (instr.hasNextLine()) {
                    String[] line = instr.nextLine().split(", ");
                    instructors.add(
                            new Instructor(Integer.parseInt(line[0]), line[1], line[2], Integer.parseInt(line[3])));
                }
                while (dept.hasNextLine()) {
                    String[] line = dept.nextLine().split(", ");
                    departments.add(new Department(line[0], Integer.parseInt(line[1]),
                            Integer.parseInt(line[2])));
                    if (Integer.parseInt(line[2]) > maxDeptBudget)
                        maxDeptBudget = Integer.parseInt(line[2]);
                }
            } catch (Exception e) {
                System.out.println(e);

            }
        } catch (Exception e) {
            System.out.println(e);
        }

        System.out.println("All department names---->\n");
        for (int i = 0; i < instructors.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (instructors.get(i).dept_name.equals(instructors.get(j).dept_name)) {
                    break;
                }
                if (j == i - 1) {
                    System.out.println(instructors.get(i).dept_name);
                }
            }

        }
        System.out.println(
                "Find the names of all instructors in the Comp. Sci. department who have salary greater than 70000.  ----->\n");
        for (int i = 0; i < instructors.size(); i++) {
            if (instructors.get(i).dept_name.equals("Comp. Sci.") && instructors.get(i).salary > 70000) {
                System.out.println(instructors.get(i).name);
            }
        }

        System.out.println(
                "Find the names of all the departments (whether an instructor is associated with a department or not) ---->\n");
        for (int i = 0; i < departments.size(); i++) {
            System.out.println(i + ". " + departments.get(i).dept_name);
        }

        System.out.println(
                "Find the names of the departments with the maximum budget. In case there is more than one department\n"
                        + //
                        "with such a budget, show all the names.------> \n");
        for (int i = 0; i < departments.size(); i++) {
            if (departments.get(i).budget == maxDeptBudget) {
                System.out.println(departments.get(i).dept_name);
            }
        }
    }
}