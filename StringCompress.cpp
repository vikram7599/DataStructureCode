// input - given string
// You need to update in the given string itself i.e. in input. No need to return or print.

#include<string>
#include<iostream>
using namespace std;

void stringCompression(char input[])
{
  	int newCharStIndex=0;
    int i=0;
    int start=0;
    int last=0;
    int count=0;
    //int arr[]
    char newChar=input[0];
    while(input[i]!='\0')
    {
    	
        if(input[i]!=newChar)
        {
            
            input[last++]=newChar;
            if(count>1){
                char cp=count+48;
                //cout<<cp;
                //cout<<count;
                input[last++]=count+48;
                //cout<<last<<"s";
                //cout<<"asda";
            }
            newChar=input[i];
            count=0;
            
        }
        count++;
        i++;
    }
    input[last++]=newChar;
    if(count>1){
        input[last++]=count+48;
        //cout<<last<<"r";
    }
    input[last]='\0';
    //cout<<input[4]<<"sa";
    //string result;
    
    
   // return input;
    
}



int main(){

    string s("hello");
cout << s.size() << ' ';
s[1] = '\0';
cout << s.size() << '\n';
}