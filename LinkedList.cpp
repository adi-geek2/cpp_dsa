#include <iostream>

using namespace std;

class Node { 
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
}; 


class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        //   +======================================================+
        //   |                 WRITE YOUR CODE HERE                 |
        //   | Description:                                         |
        //   | - Write the LinkedList constructor                   |
        //   | - Constructor takes an int value                     |
        //   | - Create a new node                                  |
        //   | - Initialize head, tail to the new node              |
        //   | - Length starts at 1                                 |
        //   |                                                      |
        //   | Tips:                                                |
        //   | - Use 'new' to allocate memory for the new node      |
        //   | - Make sure to set head and tail pointers            |
        //   | - Make sure to set length                            |
        //   | - Check output from Test.cpp in "User logs"          |
        //   +======================================================+
        
        LinkedList(int value){
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        Node* getHead() {
            return head;
        }

        Node* getTail() {
            return tail; 
        }

        int getLength() {
            return length;
        }

        void append(int value){
            Node* newNode = new Node(value);
            if(length == 0){
                head = newNode;
                tail = newNode;
            }else{
            // Point the next from previous tail node to  node
            tail->next = newNode; 
            // Move the tail to node
            tail = newNode;
            }
            length++;
        }

        void deleteLast(){
            if (length == 0)return;
            else{
                Node* temp = head;
                Node* pre = temp;
                // Case 1 : List len > 1    
                while (temp->next)
                {
                    pre = temp;
                    temp = temp->next;
                }
                tail = pre;
                tail->next = nullptr;
                length--;
                if (length == 0){
                // Case 2 : List len = 1
                head = nullptr;
                tail = nullptr;
                }
                delete temp;
           }
        }

        void prepend(int value){
            Node* new_node = new Node(value); 
            if (length == 0){
                head = new_node;
                tail = new_node;
            }
            else
            {
                new_node->next = head;
                head = new_node;
            }
            length++;
        }

        void deleteFirst(){
            Node* temp = head;
            if (length == 0)
            {
                return;
            }
            else if(length == 1){
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                head = head->next;
            }
            delete temp;
            temp = nullptr;
            length--;
        }
};


