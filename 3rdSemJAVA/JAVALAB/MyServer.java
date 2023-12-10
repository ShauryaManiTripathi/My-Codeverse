import java.net.*;  
import java.io.*;  

class MyServer 
{
	public static void main(String args[]) throws Exception 
	{
		ServerSocket server = new ServerSocket(3333);
		
		System.out.println("Waiting for client to connect");
		
		Socket connection = server.accept();
		
		System.out.println("Just connected ");
		
		DataInputStream input=new DataInputStream(connection.getInputStream());
		DataOutputStream output=new DataOutputStream(connection.getOutputStream());
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in)); 
		
		String str="",str2="";  
		System.out.println("Start comminicating with Client. Write stop to finish ");
		
		while(!str.equals("stop"))
		{ 
			
			str=input.readUTF();  //receive
			System.out.println("client says: "+str);  
			
			System.out.println("Say something Ms Server: "+str2);
			str2=br.readLine();  
			
			output.writeUTF(str2); //send
			
			output.flush();
		}
		
		input.close();
		connection.close();
		server.close();
	}
}
