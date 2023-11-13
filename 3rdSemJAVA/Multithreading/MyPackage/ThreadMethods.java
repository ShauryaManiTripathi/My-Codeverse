package MyPackage;

class MyTr1 extends Thread{
	@Override
	public void run() {
		int i=0;
		while(i<500)
		{
			System.out.println("Thread 1 is executing");
			
//			try { Thread.sleep(1); } catch (InterruptedException e) {
//			 e.printStackTrace(); }
			 
			i++;
		}
	}
}

class MyTr2 extends Thread{
	@Override
	public void run() {
		int i=0;
		while (i<50)
		{
			System.out.println("Thread 2 is executing");
			i++;
		}
	}
}

public class ThreadMethods {
	public static void main(String[] args) throws InterruptedException {
		MyTr1 th1=new MyTr1();
		MyTr2 th2=new MyTr2();
		
			
		th1.start();
		th2.start();
		//th1.yield();
		th2.join();
		th1.join();
		
		
		//th1.join();
		//th2.join();
		
		System.out.println("Plllllllllllllllllllllllllll");
		
	}
}
