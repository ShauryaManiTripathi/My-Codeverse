import java.util.Arrays;
import java.util.Scanner;
public class Question1 {
    public static void main(String[] args){
        Scanner input= new Scanner(System.in);
        int[] arr = new int[5];
        System.out.println("Enter 5 elements of array");
        for(int i=0;i<5;i++){
            arr[i]=input.nextInt();
        }
        for (int element :
                arr) {
            System.out.print(element +" ");
        }
        int sum=0;
        for (int element :
                arr) {
            sum+=element;
        }
        System.out.println("The sum of array elements is "+ sum);
    }

}
