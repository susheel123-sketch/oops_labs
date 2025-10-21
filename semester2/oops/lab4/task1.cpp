/*Circular Linked List. Using CircularLinkedList.cpp, where the last node points back to the first
node, extend its functionality by adding a feature that counts and returns the total number of
nodes in the circular linked list.*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* last;

public:
    CircularLinkedList() {
        last = nullptr;
    }

    // Insert at the beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (last == nullptr) {
            last = newNode;
            last->next = last;
        }
        else {
            newNode->next = last->next;
            last->next = newNode;
        }
    }


    // Insert at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (last == nullptr) {
            last = newNode;
            last->next = last;
        }
        else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    // Traverse and print the list
    void traverse() {
        if (!last) return;
        Node* temp = last->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }
    int count_nodes(){
    if(!last ){
        return 0;
    }
    int count = 0;
    Node*temp = last->next; 
    do{
      count++;
      temp = temp->next;
    }
    while(temp != last->next);
      
    return count;
  }
  
};

int main() {
   CircularLinkedList cll;
   cll.insertAtEnd(10);
   cll.insertAtEnd(10);
   cll.insertAtEnd(10);
   cll.insertAtEnd(10);

   cout << "Circular Linked List: ";
   cll.traverse();
   cout<<"Number of nodes :"<<cll.count_nodes()<<endl;

   return 0;
}
