import java.util.ArrayList;
import java.util.Scanner;

public class ArrayL {
    static ArrayList<Integer> arr=new ArrayList<Integer>();
    static void add(int a){
        arr.add(a);
        System.out.println("Added.............\n\n");
    }
    static void remove(int a){
        int i=arr.indexOf(a);
        if(i>=0){
            System.out.println("removing "+i+" index");
            arr.remove(i);
        }
        else{
            System.out.println("cant find\n\n");
        }

    }
    static void search(int a){
        int i=arr.indexOf(a);
        if(i<0){
            System.out.println("Cant find");
            return;
        }
        System.out.println("found at");
        for(int ii=0;ii<arr.size();ii++){
            if(a==arr.get(ii)){
                System.out.print(ii+", ");
            }
        }
        System.out.println("index");

    }
    static void replacealll(int a){
        for(int i=0;i<arr.size();i++){
            arr.set(i,a);
        }
    }

    public static void main(String[] args) {
        Scanner scn=new Scanner(System.in);

        int option;boolean running=true;
        do{
            System.out.print("ArrayList:");
            for(int i=0;i<arr.size();i++){
                System.out.print(arr.get(i)+", ");
            }
            System.out.println("");
            System.out.println("Main:::::::::::::::::::::::::::::::::::::::::::>>");
            System.out.println("1. Add");
            System.out.println("2. Remove");
            System.out.println("3. Search");
            System.out.println("4. Replace");
            System.out.println("5. Exit");
            System.out.println("=================================================");
            option=scn.nextInt();
            switch (option){
                case 1:{
                    int t=scn.nextInt();
                    add(t);
                    break;
                }
                case 2:{
                    int t=scn.nextInt();
                    remove(t);
                    break;
                }
                case 3:{
                    int t=scn.nextInt();
                    search(t);
                    break;
                }
                case 4:{
                    int t=scn.nextInt();
                    replacealll(t);
                    break;
                }
                case 5:{
                    running=false;
                }
            }
        }
        while(running);
    }
}
