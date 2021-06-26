#include <string>
#include <iostream>
#include "project.h"
using namespace std;
IntSLList::~IntSLList() {
    for (IntSLLNode *p; !isEmpty(); ) {
        p = head->next;
        delete head;
        head = p;
    }
}

void IntSLList::addToHead(const string& el) {
    head = new IntSLLNode(el,head);
    if (tail == 0)
       tail = head;
}

void IntSLList::addToTail(const string& el) {
    if (tail != 0) {      // if list not empty;
         tail->next = new IntSLLNode(el);
         tail = tail->next;
    }
    else head = tail = new IntSLLNode(el);
}

void IntSLList::deleteFromHead() {
    string el = head->info;
    IntSLLNode *tmp = head;
    if (head == tail)     // if only one node on the list;
         head = tail = 0;
    else head = head->next;
    delete tmp;

}

void IntSLList::deleteFromTail() {
    string el = tail->info;
    if (head == tail) {   // if only one node on the list;
         delete head;
         head = tail = 0;
    }
    else {                // if more than one node in the list,
         IntSLLNode *tmp; // find the predecessor of tail;
         for (tmp = head; tmp->next != tail; tmp = tmp->next);
         delete tail;
         tail = tmp;      // the predecessor of tail becomes tail;
         tail->next = 0;
    }
}
void IntSLList::deleteNode(int number){
    int count=1;
    IntSLLNode *back;
    IntSLLNode *current=head;
    while(current!=NULL){
        if(count==number){
            back->next=current->next;
            delete current;
            return;
        }
        count++;
        back=current;
        current=current->next;
    }
    
}
int IntSLList::get_size(){
    int size=0;
    for (IntSLLNode *tmp = head; tmp != 0; tmp = tmp->next)
        size++;
    
    return size;
}


void IntSLList::printAll(int page) const {
    int i=page; int x=0,j=0,m=0;
    if(page==0)
{
    for (IntSLLNode *tmp = head; tmp != 0; tmp = tmp->next)
    {
   if(i<page+10)
    cout <<i+1<<")"<< tmp->info << endl;
    i++;
    }
    cout<<endl<<endl;
	cout <<"----Page: "<<page+1<<"-----"<<endl;
}
else{
IntSLLNode *tmp=head;
    while(x<page*10)
    {
        x++;
        tmp=tmp->next;
        m++;

    }
while(j<10&&(tmp!=NULL)){
    cout<<m+1<<")"<<tmp->info<<endl;
    tmp=tmp->next;
    j++;
    m++;
}
cout<<endl<<endl; 
cout <<"----Page: "<<page+1<<"-----"<<endl;   
return;
}
}


string& IntSLList::firstEl() {
    return head->info;
}
string& IntSLList::lastEl() {
    return tail->info;
}
