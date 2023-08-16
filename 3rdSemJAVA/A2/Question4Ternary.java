import java.util.Scanner;
public class Question4Ternary {
    public static void main(String[] args){
        int int1,int2;
        Scanner input=new Scanner(System.in);
        System.out.println("Enter the dividend and then the divisor");
        int1=input.nextInt();
        int2=input.nextInt();
            //the ternary operator is inside Systum.outt.println statement
        // this is very clever use of ternary operator,i need marks for real
            System.out.println(
                    (
                            (int2!=0)
                                    ?
                                    (
                                            (int1%int2==0)
                                                    ?
                                                    ("Yes, "+int1+" is divisible by "+int2)
                                                    :
                                                    ("No, "+int2+" cant divide "+int1)
                                    )
                                    :
                                    ("Cant divide by zero")
                    )
            );
    }
}
