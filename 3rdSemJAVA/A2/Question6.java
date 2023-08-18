import java.util.Scanner;
public class Question6 {
    String sentence;
    String longestWord="";
    Scanner input=new Scanner(System.in);
    public Question6(){
        System.out.println("Enter the sentence to invoke the object");
        sentence= " "+input.nextLine();
    }
    public void getLongestWord(){
        int init=0,end;
        for (int i = 0; i < sentence.length(); i++) {
            if(i==0 || sentence.charAt(i)==' ' || sentence.charAt(i)==',' || sentence.charAt(i)=='.' || i==sentence.length()-1){
                end=i;
                String temp=sentence.substring(init,end);
                if(temp.length()>longestWord.length()){
                    longestWord=temp;
                }
                init=end;
            }
        }
    }

    public void isPangram(){
    boolean[] isPresent=new boolean[26];
    //isPresent array is auto-Initialized with false
        for (int i = 0; i < sentence.length(); i++) {
                if(sentence.charAt(i)>=97 && sentence.charAt(i)<123){
                    isPresent[(int)(sentence.charAt(i)) - 32 - 65]=true;
                }
                if(sentence.charAt(i)>=65 && sentence.charAt(i)<91) {
                    isPresent[(int) (sentence.charAt(i)) - 65] = true;
                }
        }

        boolean isPan=true;
        for (boolean b : isPresent)
            if (!b) {
                isPan = false;
                break;
            }
        System.out.println(isPan?"Pangram":"Not Pangram");
    }

    void closeINPUT(){
        input.close();
    }

    public static void main(String[] args){
        Question6 object=new Question6();
        object.getLongestWord();
        System.out.println("The longest word is "+object.longestWord);
        object.isPangram();
        object.closeINPUT();
    }


}
