
import java.util.Scanner;
public class Question3 {
    static int[]arr;
    static Scanner scn=new Scanner(System.in);
    static void initialize(){
        System.out.println("Enter size");
        arr=new int[scn.nextInt()];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = scn.nextInt();
        }
    }
    static int findMIN(){
        int min=Integer.MAX_VALUE;
        for(int i=0;i<arr.length;i++){
            if(arr[i]<min)min=arr[i];
        }
        return min;
    }

    public static void main(String[] args) {
        initialize();
        System.out.println("The minimum value is "+ findMIN());
    }


}
