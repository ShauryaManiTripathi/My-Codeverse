package MyPackage;

class MyTable{
	void print(int n) {
		synchronized (this) 
		{
			for(int i=0; i<6; i++)
			{
				System.out.println(n*i);
				try {
					Thread.sleep(200);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
	}
}

class MyThread3 extends Thread{
	MyTable t;
	MyThread3(MyTable t){
		this.t=t;
	}
	
	public void run() {
		t.print(5);
	}
}

class MyThread4 extends Thread{
	MyTable t;
	MyThread4(MyTable t){
		this.t=t;
	}
	
	public void run() {
		t.print(10);
	}
}

public class ExampleSynchronize2 {
	public static void main(String[] args) {
		MyTable ble=new MyTable();
		MyThread3 th1=new MyThread3(ble);
		MyThread4 th2=new MyThread4(ble);
		
		th1.start();
		th2.start();
		
	}

}
