#include <iostream>
#include <cstring>
using namespace std;


//char *strtok (char *s, char *delimiters)
// returns a token on each subsequent call
// on the first call function should be passed with string argument for 's'
// on subsequent calls we should pass the string argument as null

char * mystrtok(char *ss,char delim){//going to choose a character for deliminator, we can use a string too.....
    static char* input=NULL;
    if(ss!=NULL){//If input is not null, then only we are goign to initialize oterwise the input will retain state from prev function call
        //we are making first call
        input=ss;
    }
    //base case
    if(input==NULL)return NULL; 
    //start extracting tokens and store it in array
    char *output=new char[strlen(input)+1];
    int i=0;
    for(;input[i]!='\0';i++){
        if(input[i]!=delim) 
        output[i]=input[i];
        else {
            output[i]='\0';
            input=input+i+1;
            return output; 
        }
    }
    //corner state, where '\0' is encountered
    input=NULL;
    output[i]='\0';
    return output;

}

int main() {

    char s[100] = "Today is a rainy day";
    char ss[100] = "Tomarrow isn't a sunny night";
    cin.getline(s,100,'\n');
    cin.getline(ss,100,'\n');

    char *ptr=strtok(s," ");
    cout<<ptr<<endl;
    
    //it copies the char array and returns the first token
    //to get next tokens, we shoudl pass NULL
    //it maintains a static array
    while(ptr!=NULL){
    ptr=strtok(NULL," ");
    cout<<(ptr==NULL?"":ptr)<<endl;}
    //cout<<(char *)NULL<<endl;
    //own custom tokensizer
    char *pr=mystrtok(ss,' ');
    cout<<pr<<endl;
    
    //it copies the char array and returns the first token
    //to get next tokens, we shoudl pass NULL
    //it maintains a static array
    while(pr!=NULL){
        pr=mystrtok(NULL,' ');
        cout<<pr<<endl;
    }

}