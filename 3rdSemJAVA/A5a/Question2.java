
import java.util.Scanner;

public class Question2 {
    static int[] top=new int[3];
    static void set(){
        for(int i=0;i<3;i++){
            top[i]=Integer.MIN_VALUE;
        }
    }
    static void update(int candidate){
        if(candidate>=top[0]){
            if(candidate==top[0])return;
            else {
                top[2] = top[1];
                top[1] = top[0];
                top[0] = candidate;
            }
        } else if (candidate>=top[1]) {
            if(candidate==top[1])return;
            else {
                top[2] = top[1];
                top[1] = candidate;
            }
        } else if (candidate>=top[2]) {
            if(candidate==top[2])return;
            else {
                top[2] = candidate;
            }
        }
    }
    static int getTopper(int index){
            return top[index];
    }
    public static void main(String[] args) {
        Question2.set();
        Scanner scn=new Scanner(System.in);
        int size=scn.nextInt();
        int[] arr=new int[size];
        for(int i=0;i<arr.length;i++){
            arr[i]=scn.nextInt();
            Question2.update(arr[i]);
        }
        System.out.println("The 3rd Largest Element is "+getTopper(2));

    }

}
