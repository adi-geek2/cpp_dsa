#include "LinkedList.cpp"
#include <iostream>

using namespace std;

int main(){
    LinkedList* testLinkedList = new LinkedList(2);
    cout << "LL before delete1 ";
    testLinkedList->printList();
    
    testLinkedList->append(3);
    cout << "LL after append ";
    testLinkedList->printList();

    testLinkedList->prepend(1);
    cout << "LL after prepend ";
    testLinkedList->printList();
    
    testLinkedList->deleteLast();
    cout << "LL after delete2";
    testLinkedList->printList();
    
    testLinkedList->deleteLast();
    cout << "LL after delete3 ";
    testLinkedList->printList(); 

    testLinkedList->deleteFirst();
    cout << "LL after delete first";
    testLinkedList->printList(); 
    //cout << "hi";   
    return 0;
}