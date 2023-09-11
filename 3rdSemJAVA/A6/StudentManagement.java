import java.util.Scanner;
import java.util.ArrayList;
class Student{
    int studentId;
    String studentName;
    int studentAge;
    String studentMajor;
    float studentGPA;
    static int totalStudentsEnrolled;
    int gender;
    String address1;
    public Student(){

    }

    public int getId(){
        return studentId;
    }
    Scanner sc= new Scanner(System.in);
    public void setDetails(){
        System.out.println("Enter the student id:");
        studentId=sc.nextInt();
        sc.nextLine();
        System.out.println("Enter the name:");
        studentName=sc.nextLine();
        //sc.nextLine();
        System.out.println("Enter the student age:");
        this.studentAge =sc.nextInt();
        sc.nextLine();
        System.out.println("enter major:");
        this.studentMajor=sc.nextLine();
        //sc.nextLine();
        System.out.println("enter student gpa:");
        this.studentGPA=sc.nextFloat();
        System.out.println("Enter student Gender 1 for male and 0 for female");
        this.gender=sc.nextInt();
        System.out.println("Enter student's address");
        sc.nextLine();
        this.address1=sc.nextLine();




    }

    public void getDetails(int id){

        System.out.println("student Id:"+studentId);
        System.out.println("student name:"+studentName);
        System.out.println("The studnet age:"+studentAge);
        System.out.println("student's major:"+studentMajor);
        System.out.println("student's GPA:"+studentGPA);
        System.out.println("Student's Gender -> "+gender);
        System.out.println("Student's Address -> "+ address1);

    }

    public void updateDetails(int id){
        setDetails();
    }

    public float getGPA(int id){
        return studentGPA;
    }

    public void updateGPA(int id,float newGPA){
        this.studentGPA=newGPA;

    }

    public static int totalStudents(){
        return totalStudentsEnrolled;
    }
}
public class StudentManagement  {
    // void compare(arr,int id1,int id2){

    // }

    public static void compare(int id1,int id2,ArrayList<Student> arr){
        int i=0;
        int j=0;
        for(int k=0;k<arr.size();k++){
            if(arr.get(k).getId()==id1){
                i=k;
            }
            else if(arr.get(k).getId()==id2)
            {j=k;

            }
        }
        if(arr.get(i).getGPA(id1)>arr.get(j).getGPA(id2)){
            arr.get(i).getDetails(id1);
        }
        else{
            arr.get(i).getDetails(id2);
        }
    }

    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        System.out.println(">>> Enter the number of students to manage----------------->");
        int totalStudentsEnrolled= s.nextInt();

        ArrayList<Student> arr=new ArrayList<Student>();
        arr.ensureCapacity(totalStudentsEnrolled);

        for(int i=0;i<totalStudentsEnrolled;i++){
            arr.add(new Student());

            arr.get(i).setDetails();
        }
        System.out.println("check"+arr.size());
        while(true){
            int choice=0;
            System.out.println("The available options are----------------->\n");
            System.out.println("1. Set Details/Change Details");
            System.out.println("2. Fetch Student details");
            System.out.println("3. Change Student,s GPA");
            System.out.println("4. Display no. of students enrolled");
            System.out.println("5. Compare GPA");
            System.out.println("6. Enter '6' To Exit");
            System.out.println("7. Add another student");
            System.out.println("8. Remove student");
            choice=s.nextInt();


            boolean flag=false;
            boolean breakflag=false;


            int i=0;
            switch(choice){
                case 1:
                    System.out.print("Enter the id of the student-->");
                    int id=s.nextInt();
                    i=0;
                    for(;i<arr.size();i++){
                        System.out.println("i:"+i);
                        if(arr.get(i).getId()==id){
                            arr.get(i).updateDetails(id);
                            flag=true;}
                    }
                    if(! flag){
                        System.out.println("WARNING -- the entered ID is not found!!!");
                    }
                    System.out.println("DETAIL OF :"+i);

                    break;
                case 2:
                    System.out.println("enter student id:");
                    id=s.nextInt();
                    i=0;
                    for(;i<arr.size();i++){
                        if(arr.get(i).getId()==id){
                            arr.get(i).getDetails(id);
                            flag=true;}
                    }
                    if(! flag){
                        System.out.println("WARNING -- the entered ID is not found!!!");
                    }



                    break;

                case 3:
                    System.out.println("enter student id:");
                    id=s.nextInt();
                    i=0;
                    for(;i<arr.size();i++){
                        if(arr.get(i).getId()==id){
                            System.out.println("Enter updated GPA"+arr.get(i).studentName);
                            float newGPA= s.nextFloat();
                            arr.get(i).updateGPA(id,newGPA);
                            flag=true;}
                    }
                    if(! flag){
                        System.out.println("WARNING -- the entered ID is not found!!!");
                    }

                    break;
                case 4:
                    System.out.println("total students enrolled are:"+arr.size());
                    break;

                case 5:
                    int id1;
                    int id2;
                    System.out.println("enter id of first student");
                    id1=s.nextInt();
                    System.out.println("enter id of second student");
                    id2=s.nextInt();
                    System.out.println("here are the details of the student with better GPA:");
                    compare(id1,id2,arr);
                    break;


                case 6:
                    breakflag=true;
                    break;

                case 7:
                    arr.add(new Student());
                    arr.get(arr.size()-1).setDetails();
                    break;

                case 8:
                    int tt=s.nextInt();
                    int ii;
                    for(ii=0;ii<arr.size();ii++){
                        if(arr.get(ii).getId()==tt){
                            break;
                        }
                    }
                    if(ii<arr.size()){
                        arr.remove(ii);
                    }
                    else{
                        System.out.println("Cant find");
                    }
                    break;
            }



            if(breakflag) break;
        }

        s.close();
    }}

