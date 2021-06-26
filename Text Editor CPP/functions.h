#include <string>
#include "project.h"
#include<iostream>
#include<fstream>
#include<stack>
using namespace std;
stack<string> last_action;
stack<int> last_value;
stack<string> last_str;
stack<int> move_1;
stack<int> move_2;
extern int page=0;
 

void open_file(string filename,IntSLList & list){
    ifstream file;
    string line;
    file.open(filename.c_str());
    if(file.is_open()==false)
    {
        cout << "Couldn't open the file" << endl;
         return;
    }
while(getline(file,line)){
    list.addToTail(line);
}    
}
void savefile(string filename,IntSLList & list){
    IntSLLNode *tmp=list.head;
    ofstream file;
    string line;
    file.open(filename.c_str());
    if(file.is_open()){
        while(tmp!=NULL){
            line=tmp->info;
            file<<line<<endl;
            tmp=tmp->next;
        }
        file.close();
        cout<<"File Saved"<<endl;
    }
    else
        cout<<"Error, please try again";
    
}
void next(IntSLList& list){
    page+=1;
    cout<<endl;
    list.printAll(page);
    last_action.push("next");
}

void prev(IntSLList& list){
    page-=1;
    if(page==-1){
        cout<<endl<<"--This was the first page--"<<endl;
        page+=2;
        prev(list);
        return;
    }
    cout<<endl;
    list.printAll(page);
    last_action.push("prev");
}

void replace(int line,string text,IntSLList& list){
int i;
IntSLLNode *tmp = list.head;
for(i=1;i<line;tmp=tmp->next)
    i++;
last_str.push(tmp->info);
last_value.push(line);   
tmp->info=text;
last_action.push("replace");
}

void delete_it(int position,IntSLList& list)
{
int i;
IntSLLNode *tmp = list.head;
for(i=1;i<position;tmp=tmp->next)
    i++;   
last_str.push(tmp->info);
if(position==1){
    list.deleteFromHead();
    last_value.push(position);
    last_action.push("delete");
    return;
}
list.deleteNode(position);
last_value.push(position);
last_action.push("delete");
}

void insert(int line,string word,IntSLList& list){
int i;
last_value.push(line);
IntSLLNode *iter=list.head;
IntSLLNode *tmp=new IntSLLNode(word);
if(line<=list.get_size())
{
    for(i=1;i<line-1;iter=iter->next)
        i++;
if(line==1){
    list.addToHead(word);
    last_action.push("insert");
    return;
}
else{   
tmp->next=iter->next;
iter->next=tmp;
}
}
else{
    for(i=1;i<(line-1);iter=iter->next)
    {
        list.addToTail(" ");
        i++;
    }
tmp->next=iter->next;
iter->next=tmp;
}
last_action.push("insert");
}

void move(int x,int y,IntSLList& list){
IntSLLNode *tmp=list.head;
move_1.push(x);
move_2.push(y);
int i;
if(x<y){
for(i=1;i<x;tmp=tmp->next){
    i++;
}
insert(y+1,tmp->info,list);
if(x==1){
list.deleteFromHead();
}
else
list.deleteNode(x);

}
else{
for(i=1;i<x;tmp=tmp->next){
    i++;
}    
if(y==1)
{
    list.addToHead(tmp->info);
    list.deleteNode(x+1);
    return;
}
else
{
insert(y,tmp->info,list);    
list.deleteNode(x+1); 
}
}
last_action.push("move");   
}
void undo(IntSLList& list){
string action;
action=last_action.top();
if(last_action.top()=="0"){
    cout<<"there is no function"<<endl;
    return;
}
if(action=="next"){
        last_action.pop();
        prev(list);
        last_action.pop();
}
else if(action=="prev"){
    last_action.pop();
    next(list);
    last_action.pop();
}    
else if(action=="replace"){
    last_action.pop();
    replace(last_value.top(),last_str.top(),list);
    last_action.pop();
    last_str.pop();last_str.pop();
    last_value.pop();last_value.pop();

}
else if(action=="insert"){
    last_action.pop();
    delete_it(last_value.top(),list);
    last_action.pop();
    last_value.pop();last_value.pop();
    last_str.pop();
}   
else if(action=="move"){
    last_action.pop();
    move(move_2.top(),move_1.top(),list);
    last_action.pop();
    move_1.pop();move_1.pop();
    move_2.pop();move_2.pop();
}
else if(action=="delete"){
    last_action.pop();
    insert(last_value.top(),last_str.top(),list);
    last_action.pop();
    last_value.pop();last_value.pop();
    last_str.pop();
}
   
}

