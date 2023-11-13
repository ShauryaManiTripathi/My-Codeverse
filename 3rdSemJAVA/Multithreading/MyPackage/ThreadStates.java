package MyPackage;

import java.lang.Thread.State;

class MyRunnable3 implements Runnable{
	public void run() {
		int i=0;
		while(i<10)
		{
			System.out.println("\n\n The value of i= "+i);
			try {
				Thread.sleep(1);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			i++;
		}
		
	}
}

public class ThreadStates {
	public static void main(String[] args) {
		MyRunnable3 run=new MyRunnable3();
		Thread th=new Thread(run, "Thread0");
		
		th.start();
		
		while(true) {
			Thread.State state=th.getState();
			System.out.println(state);
			if(state==Thread.State.TERMINATED)
				break;
		}
	
	
	}

}
