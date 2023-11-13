package FileHandling;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Sumfromfile {
    public static void main(String[] args) {
        String filePath = "/home/shaurya/Desktop/VScode/3rdSemJAVA/FileHandling/input.txt"; // Replace with the path to your file

        try {
            int sum = calculateSumFromFile(filePath);
            System.out.println("Sum of numbers in the file: " + sum);
        } catch (IOException e) {
            System.err.println("Error reading from the file: " + e.getMessage());
        }
    }

    private static int calculateSumFromFile(String filePath) throws IOException {
        int sum = 0;

        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                try {
                    int number = Integer.parseInt(line);
                    sum += number;
                } catch (NumberFormatException e) {
                    System.err.println("Invalid number format in the file: " + line);
                }
            }
        }

        return sum;
    }
}
