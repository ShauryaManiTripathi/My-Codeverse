package MyPackage;

class MyThr extends Thread{
	
	public MyThr(String name)
	{
		super(name);
	}
	
	@Override
	public void run() {
		while(true) {
			System.out.println("Thread running");
		}
	}
}

public class ThreadConstructor1 {
	public static void main(String[] args) {
		MyThr th1=new MyThr("Alex");
		MyThr th2=new MyThr("Harry");
		//th1.start();
		
		System.out.println("First thread = "+th1.getId());
		System.out.println("Second thread = "+th2.getId());
		
		System.out.println("First thread name= "+th1.getName());
		System.out.println("Second thread = "+th2.getName());
	
	
	}

}
