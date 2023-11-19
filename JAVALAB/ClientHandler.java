import java.io.*;
import java.net.*;
import java.util.*;

public class ClientHandler implements Runnable {

  private Socket socket;

  public ClientHandler(Socket socket) {
    this.socket = socket;
  }

  @Override
  public void run() {

    try {
      BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
      PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

      while (true) {

        try
        {
          String input = in.readLine();
          if (input.equals("exit")) {
            break;
          }

          String[] parts = input.split(" ");
          String type = parts[0];
          String course = parts[1];

          if (type.equals("COUNT")) {
            File file = new File("instructors_" + course + ".txt");
            Scanner sc = new Scanner(file);
            int count = 0;
            while (sc.hasNextLine()) {
              sc.nextLine();
              count++;
            }
            out.println(count);

          } else if (type.equals("NAMES")) {

            File file = new File("instructors_" + course + ".txt");
            Scanner sc = new Scanner(file);
            String names = "";
            while (sc.hasNextLine()) {
              names += sc.nextLine() + ", ";
            }
            names = names.substring(0, names.length() - 2);
            out.println(names);
          }
        }
        catch(Exception e)
        {
          out.println("\n\nInvalid input(case sensitive or spelling mistake) or some error has occured\n\n");
        }
      }

      socket.close();
      in.close();
      out.close();

    } catch (IOException e) {
      e.printStackTrace();
    }
  }

}