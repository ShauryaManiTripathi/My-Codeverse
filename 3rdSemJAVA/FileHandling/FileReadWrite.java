package FileHandling;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class FileReadWrite {
    public static void main(String[] args) {
        String filePath = "/home/shaurya/Desktop/VScode/3rdSemJAVA/FileHandling/input.txt"; // Replace with the path to your file

        try {
            // Read the file
            String content = readFile(filePath);
            System.out.println("Original content:\n" + content);

            // Modify the content (for demonstration, let's convert it to uppercase)
            String modifiedContent = content.toUpperCase();

            // Rewrite the file with modified content
            writeFile(filePath, modifiedContent);

            System.out.println("File has been successfully rewritten with modified content.");
        } catch (IOException e) {
            System.err.println("Error handling the file: " + e.getMessage());
        }
    }

    private static String readFile(String filePath) throws IOException {
        StringBuilder content = new StringBuilder();

        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                content.append(line).append("\n");
            }
        }

        return content.toString();
    }

    private static void writeFile(String filePath, String content) throws IOException {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
            writer.write(content);
        }
    }
}
