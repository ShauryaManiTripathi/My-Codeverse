package MyPackage;

class MyThr1 extends Thread{
	public MyThr1(String name) {
		super(name);
	}
	
	@Override
	public void run() {
		while(true)
		{
			System.out.println("Thread running with name ="+this.getName() );
		}
	}
}

public class Example1 {
	public static void main(String[] args) {
		MyThr1 th1=new MyThr1("Alex1");
		MyThr1 th2=new MyThr1("Alex2");
		MyThr1 th3=new MyThr1("Alex3");
		MyThr1 th4=new MyThr1("Alex4");
		MyThr1 th5=new MyThr1("Alex5");
		
		th1.setPriority(Thread.MAX_PRIORITY);
		th2.setPriority(Thread.MIN_PRIORITY);
		th3.setPriority(Thread.MIN_PRIORITY);
		th4.setPriority(Thread.MIN_PRIORITY);
		th5.setPriority(Thread.MIN_PRIORITY);
		
		
		th1.start();
		th2.start();
		th3.start();
		th4.start();
		th5.start();
		
		
		
		
	}

}
