#include <string>

#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST
using namespace std;
class IntSLLNode {
public:
    IntSLLNode() {
        next = 0;
    }
    IntSLLNode(string el, IntSLLNode *ptr = 0) {
        info = el; next = ptr;
    }
    string info;
    IntSLLNode *next;
};

class IntSLList {
public:
    IntSLLNode *head, *tail;
    IntSLList() {
        head = tail = 0;
    }
    ~IntSLList();
    int isEmpty() {
        return head == 0;
    }
    void addToHead(const string&);
    void addToTail(const string&);
    void deleteFromHead(); // delete the head and return its info;
    void deleteFromTail(); // delete the tail and return its info;
    void deleteNode(int);
    bool isInList(int) const;
    void printAll(int) const;
	string& firstEl();
    string& lastEl();
    int get_size();
private:
    
};

#endif
