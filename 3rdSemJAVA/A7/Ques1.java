import java.util.Scanner;
public class Ques1 {
    public static void main(String[] args) {
        Scanner scn=new Scanner(System.in);
        String input = scn.nextLine();
        int sum = addNumbersFromString(input);
        System.out.println("Sum of numbers: " + sum);
    }

    public static int addNumbersFromString(String input) {
        String[] parts = input.split(" ");
        int sum = 0;
        if(parts.length==1){
            System.out.println("No numbers entered");
        }
        else if(parts.length==2){
            System.out.println("Need to add at least two numbers");
        }
        else{
        for (String part : parts) {
            try {
                int number = Integer.parseInt(part);
                sum += number;
            }
            catch (NumberFormatException e) {
                continue;
            }
        }
    }

        return sum;
    }
}
