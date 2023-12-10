import java.net.*;  
import java.io.*; 

class MyClient 
{
	public static void main(String args[])throws Exception
	{  
		System.out.println("Connecting to server... ");
		
		Socket socket = new Socket("localhost",3333);  
		
		System.out.println("Connected to server... ");
		
		DataInputStream input=new DataInputStream(socket.getInputStream());  
		DataOutputStream output=new DataOutputStream(socket.getOutputStream());
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));  
		
				
		
		String str="",str2=""; 
		System.out.println("Start comminicating with Server. Write stop to finish ");
		
		while(!str.equals("stop"))
		{  
			str=br.readLine();  
			System.out.println("I want to say: "+str);
			
			output.writeUTF(str);  //send to server
			output.flush();  
			
			str2=input.readUTF(); //receive  
			System.out.println("Server says: "+str2);
		  
		}
		System.out.println("Comes out of loop in client");
		
		output.close();  
		socket.close();

	}

}   
