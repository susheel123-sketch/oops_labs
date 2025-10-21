/*Linked List with Encapsulation. Rewrite the Node class in the provided linkedlist.cpp file to make
the data and next attributes private. Make the LinkedList class a friend of the Node class so that it
can access these private members.*/
#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* next;
friend class LinkedList;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Function to insert a node at the end
 void add(int val);

    // Function to insert a node at a specific position
 void insert(int pos, int val);

    // Function to traverse and print the linked list
 void traverse();

    // Function to delete a node by value
 void remove(int val); 

    // Function to delete/destroy the entire linked list
 void destroy();

    // Destructor to ensure proper cleanup
    ~LinkedList() {
        destroy();
    }
};
 void LinkedList::add(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp =head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
void LinkedList::insert(int pos, int val) {
        Node* newNode = new Node(val);
        if (pos == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp; ++i) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Position out of bounds" << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
}
void LinkedList::traverse() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
}
void LinkedList::remove(int val){
        if (!head) return;
        if (head->data == val) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != val) {
            temp = temp->next;
        }
        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
}
void LinkedList::destroy() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
int main() {
   LinkedList list;

   // Adding nodes to the end
   list.add(10);
   list.add(20);
   list.add(30);

   // Traversing and printing the list
   cout << "Initial list: ";
   list.traverse();

   // Inserting a node within the list
   list.insert(1, 15);
   cout << "After insertion at position 1: ";
   list.traverse();

   // Deleting a node
   list.remove(20);
   cout << "After deleting 20: ";
   list.traverse();

   // Destroying the list
   list.destroy();
   cout << "After destroying the list: ";
   list.traverse();

   return 0;
}
