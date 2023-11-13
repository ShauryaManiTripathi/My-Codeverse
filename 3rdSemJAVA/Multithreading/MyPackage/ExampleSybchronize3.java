package MyPackage;

class ABC{
	private int data;
	
	void fun(String str) {
		if(str.equals("MyThread1"))
		{
			data=data+20;
			System.out.println("Thread1a: Data = "+data);
			System.out.println("Thread1b : Data = "+data);
			
			data=0;
			System.out.println("Thread1: Data = "+data);
		}
		else if(str.equals("MyThread2"))
		{
			data=data+150;
			System.out.println("Thread2a : Data = "+data);
			
			data=0;
			System.out.println("Thread2 : Data = "+data);
		}
	}
	
}

class MyThread5 extends Thread{
	ABC a;
	MyThread5(ABC a1){
		a=a1;
	}
	
	@Override
	public void run() {
		String threadName=Thread.currentThread().getName();
		//while(true)
		a.fun(threadName);
	}

}

public class ExampleSybchronize3 {
	public static void main(String[] args) {
		ABC obj=new ABC();
		MyThread5 th1=new MyThread5(obj);
		th1.setName("MyThread1");
		//System.out.println("Th1 name="+th1.getName());
		
		
		MyThread5 th2=new MyThread5(obj);
		th2.setName("MyThread2");
		//System.out.println("Th1 name="+th2.getName());
		
		th1.start();
		th2.start();
	}

}
