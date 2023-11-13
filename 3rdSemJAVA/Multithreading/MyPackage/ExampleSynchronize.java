package MyPackage;

class Table{
	synchronized void print(int n) {
		for(int i=0; i<6; i++)
		{
			System.out.println(n*i);
			try {
				Thread.sleep(2);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}

class MyThread1 extends Thread{
	Table t;
	MyThread1(Table t){
		this.t=t;
	}
	
	public void run() {
		t.print(5);
	}
}

class MyThread2 extends Thread{
	Table t;
	MyThread2(Table t){
		this.t=t;
	}
	
	public void run() {
		t.print(10);
	}
}

public class ExampleSynchronize {
	public static void main(String[] args) {
		Table tble=new Table();
		MyThread1 th1=new MyThread1(tble);
		MyThread2 th2=new MyThread2(tble);
		
		th1.start();
		th2.start();
	
	}

}
