import java.util.Scanner;
import java.util.ArrayList;
class Account{
    int accountNumber;
    String accountType;
    String serviceBranchIFSC;
    float minimumBalance;
    float availableBalance;
    int customerID;
    String customerName;
    static int totalAccountCreated=0;
    public Account(){
        totalAccountCreated++;
    }

    public int getId(){
        return accountNumber;
    }
    Scanner sc= new Scanner(System.in);
    public void setDetails(){
        System.out.println("Enter the account Number:");
        accountNumber=sc.nextInt();
        sc.nextLine();
        System.out.println("Enter account type:");
        accountType=sc.nextLine();
        System.out.println("Enter the IFSC code:");
        serviceBranchIFSC =sc.nextLine();
        System.out.println("enter Minimum Balance:");
        minimumBalance=sc.nextFloat();
        sc.nextLine();
        System.out.println("enter Available balance:");
        availableBalance=sc.nextFloat();
        sc.nextLine();
        System.out.println("Enter CustomerID:");
        customerID=sc.nextInt();
        sc.nextLine();
        System.out.println("Enter Customer's name");
        customerName=sc.nextLine();




    }

    public void getDetails(int id){

        System.out.println("Account number:"+accountNumber);
        System.out.println("Account type:"+accountType);
        System.out.println("IFSC number:"+serviceBranchIFSC);
        System.out.println("Minimum Balance:"+minimumBalance);
        System.out.println("Available balance:"+availableBalance);
        System.out.println("Customer ID -> "+customerID);
        System.out.println("Customer name -> "+ customerName);

    }

    public void updateDetails(int id){
        setDetails();
    }

    public float getAvailableBalance(int id){
        return availableBalance;
    }

    public void deposit(int id,float bal){
        this.availableBalance+=bal;

    }

    public void withdraw(int id,float bal){
        if((availableBalance-minimumBalance)>(bal)){
            availableBalance-=bal;
        }
        else{
            System.out.println("No sufficient balance available");
        }
    }

    public static int totalAccounts(){
        return totalAccountCreated;
    }
}
public class BankManagement  {
    // void compare(arr,int id1,int id2){

    // }

    public static void compare(int id1,int id2,ArrayList<Account> arr){
        int i=0;
        int j=0;
        for(int k=0;k<arr.size();k++){
            if(arr.get(k).getId()==id1){
                i=k;
            }
            else if(arr.get(k).getId()==id2)
            {j=k;

            }
        }
        if(arr.get(i).getAvailableBalance(id1)>arr.get(j).getAvailableBalance(id2)){
            arr.get(i).getDetails(id1);
        }
        else{
            arr.get(i).getDetails(id2);
        }
    }

    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        System.out.println(">>> Enter the number of accounts to manage when opening----------------->");
        int totalAccountEnrolled= s.nextInt();
        Account.totalAccountCreated=totalAccountEnrolled;

        ArrayList<Account> arr=new ArrayList<Account>();
        arr.ensureCapacity(totalAccountEnrolled);

        for(int i=0;i<totalAccountEnrolled;i++){
            arr.add(new Account());

            arr.get(i).setDetails();
        }
        System.out.println("check"+arr.size()) ;
        while(true){
            int choice=0;
            System.out.println("The available options are----------------->\n");
            System.out.println("1. Set Details/Change Details");
            System.out.println("2. Fetch Account details");
            System.out.println("3. deposit");
            System.out.println("4. Display Number of account available");
            System.out.println("5. Withdraw");
            System.out.println("6. Enter '6' To Exit");
            System.out.println("7. Add another Account");
            System.out.println("8. Remove Account");
            choice=s.nextInt();


            boolean flag=false;
            boolean breakflag=false;


            int i=0;
            switch(choice){
                case 1:
                    System.out.print("Enter the Account number-->");
                    int id=s.nextInt();
                    i=0;
                    for(;i<arr.size();i++){
                        System.out.println("i:"+i);
                        if(arr.get(i).getId()==id){
                            arr.get(i).updateDetails(id);
                            flag=true;}
                    }
                    if(! flag){
                        System.out.println("WARNING -- the entered Account Number is not found!!!");
                    }
                    System.out.println("DETAIL OF :"+i);

                    break;
                case 2:
                    System.out.println("enter account number:");
                    id=s.nextInt();
                    i=0;
                    for(;i<arr.size();i++){
                        if(arr.get(i).getId()==id){
                            arr.get(i).getDetails(id);
                            flag=true;}
                    }
                    if(! flag){
                        System.out.println("WARNING -- the entered number is not found!!!");
                    }



                    break;

                case 3:
                    System.out.println("enter Account number:");
                    id=s.nextInt();
                    i=0;
                    for(;i<arr.size();i++){
                        if(arr.get(i).getId()==id){
                            System.out.println("Enter Balance to add in account number:"+arr.get(i).accountNumber);
                            float newGPA= s.nextFloat();
                            arr.get(i).deposit(id,newGPA);
                            flag=true;}
                    }
                    if(! flag){
                        System.out.println("WARNING -- the entered Account is not found!!!");
                    }

                    break;
                case 4:
                    System.out.println("total students enrolled are:"+arr.size());
                    break;

                case 5:
                    System.out.println("enter Account number:");
                    id=s.nextInt();
                    i=0;
                    for(;i<arr.size();i++){
                        if(arr.get(i).getId()==id){
                            System.out.println("Enter Balance to remove in account number:"+arr.get(i).accountNumber);
                            float newGPA= s.nextFloat();
                            arr.get(i).withdraw(id,newGPA);
                            flag=true;}
                    }
                    if(! flag){
                        System.out.println("WARNING -- the entered Account is not found!!!");
                    }

                    break;


                case 6:
                    breakflag=true;
                    break;

                case 7:
                    arr.add(new Account());
                    arr.get(arr.size()-1).setDetails();
                    break;

                case 8:
                    int tt=s.nextInt();
                    int ii;
                    for(ii=0;ii<arr.size();ii++){
                        if(arr.get(ii).getId()==tt){
                            break;
                        }
                    }
                    if(ii<arr.size()){
                        arr.remove(ii);
                        Account.totalAccountCreated--;
                    }
                    else{
                        System.out.println("Cant find");
                    }
                    break;
            }



            if(breakflag) break;
        }

        s.close();
    }}
