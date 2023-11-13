package MyPackage;

class Customer{    
    	int amount=10000;    
        
    	synchronized void withdraw(int amount){    
    		System.out.println("going to withdraw...");    
        
    		if(this.amount<amount){    
    			System.out.println("Less balance; waiting for deposit...");    
    			try{
    				wait();
    				}
    			catch(Exception e){}    
    		}    
    		this.amount-=amount;    
    		System.out.println("withdraw completed...");    
    	}    
        
    	synchronized void deposit(int amount)
    	{    
    		System.out.println("going to deposit...");    
    		this.amount+=amount;    
    		System.out.println("deposit completed... ");    
    		notify();    
    	}    
    }   
    
    class MyThread6 extends Thread{
    	Customer c;
    	MyThread6(Customer c){this.c=c;}
    	
    	public void run() {
    		c.withdraw(15000);
    	}
    }
    
    class MyThread7 extends Thread{
    	Customer c;
    	MyThread7(Customer c){this.c=c;}
    	
    	@Override
    	public void run() {
    		c.deposit(20000);
    	}
    }
        
    class InterThreadCom{    
    	public static void main(String args[]){    
    		Customer c=new Customer();
    		MyThread6 th1=new MyThread6(c);
    		MyThread7 th2=new MyThread7(c);
    		
    		th1.start();
    		th2.start();
    		
        
    	}
    
    }    