import java.util.Scanner;

public class Question3 {
    public static void main(String[] args){
        Scanner input= new Scanner(System.in);
        System.out.println("Enter number of elements in your array");
        int temp=input.nextInt();
        int[] arr = new int[temp];
        System.out.println("Enter "+temp+" elements of array");
        for(int i=0;i<temp;i++){
            arr[i]=input.nextInt();
        }
        boolean ispalindrome=true;
        for (int i = 0; i < (temp+1)/2; i++) {
            if(arr[i]!=arr[temp-i-1]){
                ispalindrome=false;
                break;
            }
        }
        System.out.println("The fact that the given array is palindrome is "+ispalindrome);
    }
}
