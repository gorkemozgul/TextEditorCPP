
#include "project.h"
#include"functions.h"
#include<iostream>
#include<string>
using namespace std;
int main()
{
string file_if,file_of, word,first,text,n;
IntSLList mylist;

while(word!="q"){
    cout<<"Enter your command(press q for exit):"<<endl;

    getline(cin,word);
    first=word.substr(0,word.find(" "));
    if(first=="open")
        {
        file_if=word.substr(5,word.find("."));
        open_file(file_if,mylist);
        cout<<endl;
        mylist.printAll(page);
        }
    else if(first=="save"){
        file_of=word.substr(5,word.find("."));
        savefile(file_of,mylist);
        cout<<endl;
    }
    else if(first=="next"){
        next(mylist);
    }
    else if(first=="prev"){
        prev(mylist);
    }
    else if(first=="insert"){
        word.erase(0,7);
        int number=stoi(word.substr(0,word.find(" ")));
        if(number<10)
            word.erase(word.begin(),word.begin()+2);
        else
            word.erase(word.begin(),word.begin()+3);
        insert(number,word,mylist);
        cout<<endl;
        mylist.printAll(page);
    }
    else if(first=="replace"){
        word.erase(0,8);
        int number=stoi(word.substr(0,word.find(" ")));
        if(number<10)
            word.erase(word.begin(),word.begin()+2);
        else
            word.erase(word.begin(),word.begin()+3);
        replace(number,word,mylist);
        cout<<endl;
        mylist.printAll(page);
    }
    else if(first=="delete"){
       word.erase(0,7);
       int number=stoi(word.substr(0,word.find(" ")));
        delete_it(number,mylist);
        cout<<endl;
        mylist.printAll(page);
    }
    else if(first=="move"){
        word.erase(0,5);
        int number1=stoi(word.substr(0,word.find(" ")));
        if(number1<10)
            word.erase(word.begin(),word.begin()+2);
        else
            word.erase(word.begin(),word.begin()+3);
        int number2=stoi(word.substr(0,word.find(" ")));
        move(number1,number2,mylist);
        cout<<endl;
        mylist.printAll(page);
    }
    else if(first=="undo"){
        undo(mylist);
        cout<<endl;
        mylist.printAll(page);
    }
    else if(first=="q"){
        cout<<"Program exited"<<endl;
        return 0;
    }
    else 
        cout<<"unknown command";
    
}

}
