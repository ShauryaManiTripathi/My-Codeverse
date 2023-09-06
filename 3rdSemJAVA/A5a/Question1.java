//Write a Java program that initializes an integer array with 5 elements and calculates the
//average of the elements. Display the sum in the console.

import java.util.Scanner;

public class Question1 {
    public static void main(String[] args){
        int[] nums=new int[5];
        int total=0;
        Scanner scn=new Scanner(System.in);
        for(int i=0;i<5;i++){
            nums[i] = scn.nextInt();
            total+=nums[i];
        }
        System.out.println("the avg is "+(total/5));

    }
}
