import java.util.Scanner;

public class Question5 {
    int[] arr;
    Scanner input=new Scanner(System.in);
    public void allocate(int size){
        System.out.println("Allocating "+size+" sized integer array");
        arr=new int[size];
        //System.out.println("Allocated successfully");
    }
    public void initialize(){
        System.out.println("Enter "+arr.length+" inputs");
        for (int i = 0; i < arr.length; i++) {
            arr[i]= input.nextInt();
        }
        // unlike  taught in class, the foreach model to take input is not working
//        for (int element :
//                arr) {
//            element= input.nextInt();
//        }
       // System.out.println("Inputs taken successfully");
    }
    public void displaycontent(){
        System.out.println("Displaying array content....");
        for (int element :
                arr) {
            System.out.print(element+" ");
        }
        System.out.println("");
    }
    public void reversecontent(){
        System.out.println("Reversing array content....");
        for (int i = 0; i < arr.length/2; i++) {
            int temp=arr[arr.length-i-1];
            arr[arr.length-i-1]=arr[i];
            arr[i]=temp;
        }
        //System.out.println("Revered the array successfully");
    }




    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter number of elements in your array");
        int temp = input.nextInt();
        Question5 object=new Question5();
        object.allocate(temp);
        object.initialize();
        object.displaycontent();
        object.reversecontent();
        object.displaycontent();
    }
}
