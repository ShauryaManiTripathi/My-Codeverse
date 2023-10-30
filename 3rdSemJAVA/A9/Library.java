import java.util.*;

class LibraryItem {
    int itemcode;
    static int ISBNLength = 5;
    String title;
    String author;
    String publicationDate;
    String ISBN;
    int availableQuantity;

    public LibraryItem(String title, String author, String publicationDate, String ISBN, int availableQuantity,
            int itemcode) {
        this.title = title;
        this.author = author;
        this.publicationDate = publicationDate;
        this.ISBN = ISBN;
        this.availableQuantity = availableQuantity;
        this.itemcode = itemcode;
    }

    boolean validate() {
        boolean one = ISBN.length() == 5;
        boolean two = ISBN.matches("[a-zA-Z0-9]+");
        String[] splithead = publicationDate.split("-");
        if(splithead.length<3)return false;
        else{
        boolean three = splithead[0].length() == 4 && splithead[0].matches("[0-9]+");
        boolean four = splithead[1].length() == 2 && splithead[1].matches("[0-9]+");
        boolean five = splithead[2].length() == 2 && splithead[2].matches("[0-9]+");
        boolean six = splithead.length == 3;
        boolean seven = availableQuantity >= 0;
        return one && two && three && four && five && six && seven;}
    }

    public void setinfo(String title, String author, String publicationDate, String ISBN, int availableQuantity,
            int itemcode) {
        this.title = title;
        this.author = author;
        this.publicationDate = publicationDate;
        this.ISBN = ISBN;
        this.availableQuantity = availableQuantity;
        this.itemcode = itemcode;
    }
}

class Book extends LibraryItem {
    public Book(String title, String author, String publicationDate, String ISBN, int availableQuantity, int itemcode) {
        super(title, author, publicationDate, ISBN, availableQuantity, itemcode);
    }
}

class Magazine extends LibraryItem {
    public Magazine(String title, String author, String publicationDate, String ISBN, int availableQuantity,
            int itemcode) {
        super(title, author, publicationDate, ISBN, availableQuantity, itemcode);
    }
}

class Newspaper extends LibraryItem {
    public Newspaper(String title, String author, String publicationDate, String ISBN, int availableQuantity,
            int itemcode) {
        super(title, author, publicationDate, ISBN, availableQuantity, itemcode);
    }
}

public class Library {
    public static void main(String[] args) {
        ArrayList<LibraryItem> items = new ArrayList<LibraryItem>();
        Scanner scn = new Scanner(System.in);
        int n;
        System.out.println("Enter the number of items to add");
        n= scn.nextInt();
        scn.nextLine();
        for (int i = 0; i < n; i++) {
            System.out.println("Enter title");
            String title=scn.nextLine();
            System.out.println("Enter author");
            String author=scn.nextLine();
            System.out.println("Enter ISBN, five charactor only and must be alphanumeric");
            String ISBN=scn.nextLine();
            System.out.println("Enter publication date in format yyyy-MM-dd and must be numerical");
            String publicationDate=scn.nextLine();
            System.out.println("Enter the number of available item");
            int availableq;
            availableq=scn.nextInt();
            scn.nextLine();
            System.out.println("which type of item is it , 1 for book, 2 for magazine, 3 for newspaper");
            int itemcode;
            itemcode=scn.nextInt();
            scn.nextLine();
            if(itemcode==1) items.add(new Book(title, author, publicationDate, ISBN, availableq, itemcode));
            else if(itemcode==2) items.add(new Magazine(title, author, publicationDate, ISBN, availableq, itemcode));
            else if(itemcode==3) items.add(new Newspaper(title, author, publicationDate, ISBN, availableq, itemcode));
            else {
                items.remove(i);
                System.out.println("the itemcode is wrong enter the info again");
                i--;
            }
            if(!items.get(i).validate()){
                items.remove(i);
                System.out.println("the given object information is not compatible, please try again");
                i--;
            }

        }
        String[] typedef=new String[4];
        typedef[1]="Book";
        typedef[2]="Magazine";
        typedef[3]="Newspaper";
        typedef[0]="null";

        for(int i=0;i<items.size();i++){
            System.out.println("title : "+items.get(i).title+" author : "+items.get(i).author+" ISBN : "+items.get(i).ISBN+" available quantity : "+items.get(i).availableQuantity+ " publicationDate : "+items.get(i).publicationDate+" item type : "+typedef[items.get(i).itemcode]);
        }
        System.out.println("choose your compare technique");
        int compCode;
        System.out.println("Enter 1 to sort on basis of title");
        System.out.println("Enter anything else to sort on the basis of date");
        compCode=scn.nextInt();
        if(compCode==1){
            Collections.sort(items,Comparator.comparing(s -> s.title));
        }
        else{
            Collections.sort(items,new DateCompare());
        }
        for(int i=0;i<items.size();i++){
            System.out.println("title : "+items.get(i).title+" author : "+items.get(i).author+" ISBN : "+items.get(i).ISBN+" available quantity : "+items.get(i).availableQuantity+ " publicationDate : "+items.get(i).publicationDate+" item type : "+typedef[items.get(i).itemcode]);
        }
        scn.close();




    }

}

class DateCompare implements java.util.Comparator<LibraryItem>{
    public int compare(LibraryItem a,LibraryItem b){
        String[] ar1=a.publicationDate.split("-");
        String[] ar2=b.publicationDate.split("-");
        int ayear=Integer.parseInt(ar1[0]);
        int byear=Integer.parseInt(ar2[0]);
        int amonth=Integer.parseInt(ar1[1]);
        int bmonth=Integer.parseInt(ar2[1]);
        int aday=Integer.parseInt(ar1[2]);
        int bday=Integer.parseInt(ar2[2]);
        return ayear*365+amonth*30+aday-byear*365-bmonth*30-bday;
    }
}
