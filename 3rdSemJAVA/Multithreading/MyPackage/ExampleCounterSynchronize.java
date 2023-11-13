package MyPackage;

class Counter{
	int count;
	public void increment() {
		count++;
	}
}

class MyThread8 extends Thread{
	Counter c;
	MyThread8(Counter c){
		this.c=c;
	}
	
	@Override
	public void run() {
		for(int i=0; i<1000;i++) {
			c.increment();
		}
	}
}

public class ExampleCounterSynchronize {
	public static void main(String[] args) throws InterruptedException {
		Counter c=new Counter();
		
		MyThread8 th1=new MyThread8(c);
		MyThread8 th2=new MyThread8(c);
		
		th1.start();
		//th1.join();
		
		th2.start();
		//th2.join();
		
		System.out.println("Final value of c = "+c.count);
	
	}

}
