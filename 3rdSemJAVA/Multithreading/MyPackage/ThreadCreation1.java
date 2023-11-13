//Thread created by extending the Thread class
package MyPackage;

class MyThread1 extends Thread{
	@Override
	public void run() {
		while(true)
		System.out.println("Thread 1 is running");
	}
}

class MyThread2 extends Thread{
	@Override
	public void run() {
		while(true)
		System.out.println("Thread 2 is running");
	}
}

public class ThreadCreation1 {
	public static void main(String[] args) {
		MyThread1 t1=new MyThread1();
		MyThread2 t2=new MyThread2();
		
		t1.start();
		t2.start();
		//t1.run();
		//t2.run();
	}

}
