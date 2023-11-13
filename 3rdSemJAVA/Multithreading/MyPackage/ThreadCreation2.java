//Thread created by implementing the Runnable interface
package MyPackage;

class MyRunnable1 implements Runnable{
	public void run() {
		while(true)
		System.out.println("Thread 1 is running");
	}
}

class MyRunnable2 implements Runnable{
	public void run() {
		while(true)
		System.out.println("Thread 2 is running");
	}
}

public class ThreadCreation2 {
	public static void main(String[] args) {
		MyRunnable1 bullet1=new MyRunnable1();
		Thread gun1=new Thread(bullet1);
		
		MyRunnable2 bullet2=new MyRunnable2();
		Thread gun2=new Thread(bullet2);
		
		gun1.start();
		gun2.start();
		
	}

}
