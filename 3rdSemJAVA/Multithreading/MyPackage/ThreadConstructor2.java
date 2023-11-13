package MyPackage;

class MyRun implements Runnable{
	@Override
	public void run() {
		while(true)
		{
			System.out.println("Thread running "+Thread.currentThread().getName());
		}
	}
}

public class ThreadConstructor2 {
	public static void main(String[] args) {
		MyRun r=new MyRun();
		Thread t1=new Thread(r, "Alex");
		Thread t2=new Thread(r, "Harry");
		
		t1.start();
		t2.start();
				
	}

}
