import java.util.Scanner;

public class Question4IfElse {
    public static void main(String[] args){
        int int1,int2;
        Scanner input=new Scanner(System.in);
        System.out.println("Enter the dividend and then the divisor");
        int1=input.nextInt();
        int2=input.nextInt();
        if(int2==0){
            System.out.println("Cant divide by zero");
        }
        else if(int1%int2==0){
            System.out.println("Yes, "+int1+" is divisible by "+int2);
        }
        else {
            System.out.println("No, " + int2 + " cant divide " + int1);
        }
    }
}
