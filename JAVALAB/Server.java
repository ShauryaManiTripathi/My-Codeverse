import java.io.*;
import java.net.*;

public class Server {
  
  private ServerSocket serverSocket;

  public Server(int port) throws IOException {
    serverSocket = new ServerSocket(port);
  }

  public void start() throws IOException {
    while (true) {
      Socket clientSocket = serverSocket.accept(); 
      ClientHandler handler = new ClientHandler(clientSocket);
      
      Thread thread = new Thread(handler);
      thread.start();
    }
  }

  public static void main(String[] args) throws IOException {
    Server server = new Server(5000);
    server.start();
  }
}