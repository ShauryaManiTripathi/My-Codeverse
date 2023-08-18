import java.util.Scanner;

public class Question2 {
    public static void main(String[] args){
        Scanner input= new Scanner(System.in);
        System.out.println("Enter number of elements in your array");
        int temp=input.nextInt();
        int[] arr = new int[temp];
        System.out.println("Enter "+temp+" elements of array");
        for(int i=0;i<temp;i++){
            arr[i]=input.nextInt();
        }
        int freq;
        boolean[] arr2=new boolean[temp];
        for (int i = 0; i < temp; i++) {
            freq=0;
            if(arr2[i]==false) {
                for (int j = i; j < temp; j++) {
                    if (arr[i] == arr[j]) {
                        arr2[j] = true;
                        freq++;
                    }
                }
                System.out.println("The Element " + arr[i] + " has " + freq + " repititions");
            }
        }
        input.close();
    }
}
