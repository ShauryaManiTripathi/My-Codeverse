import java.util.Scanner;

public class Song {
    ///////////////////////////////////////////////////
    static Song[] list;
    int songId;
    String songTitle;
    String artistName;
    String albumTitle;
    String genre;
    int durationInSeconds;
    int playCount;
    boolean inPlaylist=false;

    ////////////////////////////////////////////////

    static Scanner input=new Scanner(System.in);

    ////////////////////////////////////////////////

    Song(int durationInSeconds){
        this.durationInSeconds=durationInSeconds;
    }

    ////////////////////////////////////////////////

    Song(){}//default constructor

    ////////////////////////////////////////////////

    void setDetails(){
        System.out.println("Enter Song ID");
       songId=input.nextInt();
       input.nextLine();
        System.out.println("Enter Song Title");
       songTitle=input.nextLine();
        System.out.println("Enter artist name");
       artistName=input.nextLine();
       System.out.println("Enter album name");
       albumTitle=input.nextLine();
        System.out.println("Enter song genre");
       genre=input.nextLine();
        System.out.println("Enter duration of song");
       durationInSeconds=input.nextInt();
       playCount=0;
    }

    ///////////////////////////////////////////////

    void setDetails(int id,String title,String artist,String album,String genre,int duration){
        songId=id;
        songTitle=title;
        artistName=artist;
        albumTitle=album;
        this.genre=genre;
        durationInSeconds=duration;
        playCount=0;
    }

    ///////////////////////////////////////////////

    void getDetails(){
        System.out.println("ID - "+songId+"\ntitle - "+songTitle+"\nartist - "+artistName+"\nalbum - "+albumTitle+"\ngenre - "+genre+"\nduration - "+durationInSeconds+"\nplayCount - "+playCount+"\n");
    }

    ///////////////////////////////////////////////

    static int search(int id){
        int i=0;
        while(i<list.length){
            System.out.println(list[i].songId);
            if(id==list[i].songId)break;
            i++;
        }

        if(i<list.length)return i;
        else return -1;
    }

    ///////////////////////////////////////////////

    static int search(){
        int i=0;
        System.out.println("Enter ID of your song");
        int id= input.nextInt();
        //System.out.println(id);
        while(i<list.length){
            if(id==list[i].songId)break;
            i++;
        }
        //System.out.println(i);
        //System.out.println(list.length);
        if(i<list.length)return i;
        else return -1;
    }

    ///////////////////////////////////////////////


    static void getDetails(int id){
        int i=search(id);
        if(i>=0)list[i].getDetails();
        else System.out.println("Song not found\n");
    }

    ///////////////////////////////////////////////

    static void getDataFromID(){
        int i=search();
        if(i>=0)list[i].getDetails();
        else System.out.println("Song not found\n");
    }

    ////////////////////////////////////////////////

   void play(){
        playCount++;
   }

   ////////////////////////////////////////////////

    static void playWithID(int id){
       // System.out.println(id);
        int i=search(id);
        //System.out.println(i);
        if(i>=0) {
            list[i].play();
            System.out.println("Playing song............ ID -> "+id);
        }
        else System.out.println("Song not found\n");
    }

    ////////////////////////////////////////////////

    static void modifyPlaylist(boolean condition){
        int i=search();
        if(i>=0)list[i].inPlaylist=condition;
        else System.out.println("Song not found");
    }

    ////////////////////////////////////////////////

    static void displayPlaylist(){
        int j=1;
        for (int i = 0; i < list.length; i++) {
            if(list[i].inPlaylist==true){
                System.out.println(j+". "+"SONG TITLE - "+list[i].songTitle+" SONG ID - "+list[i].songId);
                j++;
            }
        }
        System.out.println("\n\n");
    }

    ////////////////////////////////////////////////


    public static void main(String[] args){
        Scanner size=new Scanner(System.in);
        System.out.println("Enter number of songs to put");
        int sizee=size.nextInt();
        Song.list= new Song[sizee];
        for (int i = 0; i < list.length; i++) {
            System.out.println("*-*-*-ENTER DETAILS OF SONG NUMBER " +i +"-*-*-*");
            list[i]=new Song();
            list[i].setDetails();
        }
        int choose=1;
        while(choose!=9){
            System.out.println("Options available");
            System.out.println("1.Set Details");
            System.out.println("2.Get Details");
            System.out.println("3. Play");
            System.out.println("4. Add to playlist");
            System.out.println("5. Remove from playlist");
            System.out.println("6. Display playlist");
            System.out.println("7. PlayFrequency");
            System.out.println("\nEnter your choice\n ............and enter 9 to exit:");

            choose=size.nextInt();

            switch(choose){
                case 1:{
                    int i=search();
                    if(i>=0)list[i].setDetails();
                    else System.out.println("Song not found");
                    break;
                }
                case 2:{
                    getDataFromID();
                    break;
                }
                case 3:{
                    System.out.println("Enter song ID");
                    int id=size.nextInt();
                    playWithID(id);
                     break;
                }
                case 4:{
                    modifyPlaylist(true);
                    break;
                }
                case 5:{
                    modifyPlaylist(false);
                    break;
                }
                case 6:{
                    displayPlaylist();
                    break;
                }
                case 7:{
                    int i=search();
                    if(i>-1) System.out.println("The song has beeen played for "+list[i].playCount+" times");
                    else System.out.println("Song not found");
                    break;
                }
                default:{
                    System.out.println("No valid option selected");
                }
            }


        }
    }
}
