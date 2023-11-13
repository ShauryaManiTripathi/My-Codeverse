import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class RegexTutorial {
    public static void main(String[] args) {
        // Define a regular expression pattern
        String regex = "hello";

        Pattern pattern = Pattern.compile(regex);

        // Define a string to search for matches
        String input = "hello world";

        // Create a Matcher object from the input string and the Pattern object
        Matcher matcher = pattern.matcher(input);

        // show use of pattern.matcher.matches()
        if (matcher.matches()) {
            System.out.println("Match found!");
        } else {
            System.out.println("Match not found.");
        }

        // Use the Matcher object to find matches in the input string
        if (matcher.find()) {
            System.out.println("Match found!");
        } else {
            System.out.println("Match not found.");
        }

        // Let's explore some other regex syntax

        // Character classes
        regex = "[abc]"; // Matches a single character that is either a, b, or c
        regex = "[^abc]"; // Matches a single character that is not a, b, or c
        regex = "[a-z]"; // Matches a single character from a to z
        regex = "[A-Z]"; // Matches a single character from A to Z
        regex = "[0-9]"; // Matches a single digit from 0 to 9
        regex = "[^0-9]"; // Matches a single character that is not a digit

        // Quantifiers
        regex = "a*"; // Matches zero or more occurrences of the character a
        regex = "a+"; // Matches one or more occurrences of the character a
        regex = "a?"; // Matches zero or one occurrence of the character a
        regex = "a{3}"; // Matches exactly three occurrences of the character a
        regex = "a{3,}"; // Matches three or more occurrences of the character a
        regex = "a{3,5}"; // Matches between three and five occurrences of the character a

        // Anchors
        regex = "^hello"; // Matches the string "hello" at the beginning of a line
        regex = "world$"; // Matches the string "world" at the end of a line

        // Groups
        regex = "(hello)"; // Matches the string "hello" and captures it as a group
        regex = "hello|world"; // Matches either the string "hello" or the string "world"
        regex = "\\d"; // Matches a digit (same as [0-9])
        regex = "\\D"; // Matches a non-digit (same as [^0-9])
        regex = "\\s"; // Matches whitespace (spaces, tabs, newlines, etc.)
        regex = "\\S"; // Matches non-whitespace
        regex = "\\w"; // Matches a word character (letters, digits, or underscore)
        regex = "\\W"; // Matches a non-word character

        // Flags
        regex = "hello"; // Case-sensitive matching
        regex = "(?i)hello"; // Case-insensitive matching

        // Let's test some of these regex patterns

        regex = "[abc]";
        input = "a";
        pattern = Pattern.compile(regex);
        matcher = pattern.matcher(input);
        if (matcher.find()) {
            System.out.println("Match found!");
        } else {
            System.out.println("Match not found.");
        }
        if (input.matches(regex)) {
            System.out.println("Match found! normal method");
        } else {
            System.out.println("Match not found.");
        }

        regex = "a+";
        input = "aaa";
        pattern = Pattern.compile(regex);
        matcher = pattern.matcher(input);
        if (matcher.find()) {
            System.out.println("Match found!");
        } else {
            System.out.println("Match not found.");
        }

        regex = "^hello";
        input = "hello world";
        pattern = Pattern.compile(regex);
        matcher = pattern.matcher(input);
        if (matcher.find()) {
            System.out.println("Match found!");
        } else {
            System.out.println("Match not found.");
        }

        regex = "\\d";
        input = "123";
        pattern = Pattern.compile(regex);
        matcher = pattern.matcher(input);
        if (matcher.find()) {
            System.out.println("Match found!");
        } else {
            System.out.println("Match not found.");
        }

        regex = "(?i)hello";
        input = "HELLO";
        pattern = Pattern.compile(regex);
        matcher = pattern.matcher(input);
        if (matcher.find()) {
            System.out.println("Match found!");
        } else {
            System.out.println("Match not found.");
        }
        // show me use of //// in regex
        regex = "[A-Za-z0-9!@#$&*]+@[A-Za-z]+\\\\.[A-Za-z]";
        input = "shaurya#tripathi@gmail.com";
        pattern = Pattern.compile(regex);
        matcher = pattern.matcher(input);
        if (matcher.find()) {
            System.out.println("Match found!");
        } else {
            System.out.println("Match not found.");
        }
        if (input.matches(regex)) {
            System.out.println("Match found! normal method");
        } else {
            System.out.println("Match not found.");
        }

        // show me a basic email verification regex and a basic password verification
        // regex
        // email verification regex
        // this basic email verification regex is not working, fix this
        regex = "[A-Za-z0-9!@#$&*]+@[A-Za-z]+\\\\.[A-Za-z]";
        input = "sharipathi@gmailcom";
        pattern = Pattern.compile(regex);
        matcher = pattern.matcher(input);
        if (matcher.find()) {
            System.out.println("Match found!");
        } else {
            System.out.println("Match not found.");
        }
        if (input.matches(regex)) {
            System.out.println("Match found! normal method");
        } else {
            System.out.println("Match not found.");
        }
        // password verification regex
        regex = "[A-Za-z0-9!@#$&*]+";
        input = "shaurya#tripathi";
        pattern = Pattern.compile(regex);
        matcher = pattern.matcher(input);
        if (matcher.find()) {
            System.out.println("Match found!");
        } else {
            System.out.println("Match not found.");
        }
        if (input.matches(regex)) {
            System.out.println("Match found! normal method");
        } else {
            System.out.println("Match not found.");
        }
        ArrayList<String> emails = new ArrayList<String>();
        emails.add("user@domain.com");
        emails.add("user@domain.co.in");
        emails.add("user.name@domain.com");
        emails.add("user'name@domain.co.in");

        // Invalid emails
        emails.add(".username@yahoo.com");
        emails.add("username@yahoo.com.");
        emails.add("username@yahoo..com");

        regex = "^[a-zA-Z0-9_!#$%&amp;'*+/=?`{|}~^-]+(?:\\.[a-zA-Z0-9_!#$%&amp;'*+/=?`{|}~^-]+)*@[a-zA-Z0-9-]+(?:\\.[a-zA-Z0-9-]+)*$";

        pattern = Pattern.compile(regex);

        for (String email : emails) {
            matcher = pattern.matcher(email);
            System.out.println(email + " : " + matcher.matches());
        }

    }
}
