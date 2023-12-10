package endSemJava;
import java.net.*;  
import java.io.*; 

class INetDemo 
{
	public static void main(String args[])throws Exception
	{ 
		InetAddress address = InetAddress.getByName("google.com");
		
		System.out.println(address.getHostName());
		
		System.out.println(address.getHostAddress());
	}
}