import java.io.*;
import java.net.*;
import java.util.*;

public class Client {

    private String id;
    private Socket socket;
    private BufferedReader in;
    private PrintWriter out;

    public Client(String id, String host, int port) throws IOException {
        this.id = id;
        this.socket = new Socket(host, port);
        this.in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        this.out = new PrintWriter(socket.getOutputStream(), true);
    }

    public void sendMessage(String msg) {
        out.println(msg);
    }

    public String receiveMessage() throws IOException {
        return in.readLine();
    }

    public void close() throws IOException {
        in.close();
        out.close();
        socket.close();
    }

    public static void main(String[] args) throws IOException {

        Client client = new Client("CS202", "localhost", 5000);


            client.sendMessage("COUNT MA203");
            String resp1 = client.receiveMessage();
            System.out.println(resp1);
            client.sendMessage("NAMES MA203");
            String resp2 = client.receiveMessage();
            System.out.println(resp2);
            client.sendMessage("COUNT CS202");
            String resp3 = client.receiveMessage();
            System.out.println(resp3);
            client.sendMessage("NAMES CS202");
            String resp4 = client.receiveMessage();
            System.out.println(resp4);
            


        client.close();
    }

}