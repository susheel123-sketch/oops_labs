/*Reverse a linked list. Write a function for the provided linked list class that takes the first Node in
a linked list as an argument, and reverses the list, returning the first Node in the result.
Solution: To accomplish this, we maintain references to three consecutive nodes in the linked list,
reverse, first, and second. At each iteration we extract the node first from the original linked
list and insert it at the beginning of the reversed list. We maintain the invariant that first is the
first node of what’s left of the original list, second is the second node of what’s left of the original
list, and reverse is the first node of the resulting reversed list.
2. Write a recursive function to print a linked list in reverse order. You may not use any loops or
iteration.
*/
#include <iostream>
using namespace std;
class node {
public:
    int val;
    node* next;

    node(int data) {
        val = data;
        next = nullptr;
    }
};
class linkedlist {
public:
    node* head;

    linkedlist() {
        head = nullptr;
    }
    
    //function to insert at tail
    
    void insert(int val){
        node* temp = head;
        node* newnode = new node(val);
        if (head == nullptr) {
            head = newnode;
            return;
        }

        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    //function to display the linglist

    void display() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->val << "->";
            temp = temp->next;

        }
        cout << "Null" << endl;
    }

    //function to reverse the linklist

    void reverse() {
        node* prev = nullptr;
        node* curr = head;
        node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;

        }
        head = prev;
    }

    //function to recursively reverse the linkedlist

    node* recursivereverse(node *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        node* newhead = recursivereverse(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newhead;
    }
};



int main() {
    cout << "Hello World!\n";

    linkedlist list1;

    list1.insert(10);
    list1.insert(20);
    list1.insert(30);
    list1.insert(40);
    list1.display();
    list1.head=list1.recursivereverse(list1.head);
    list1.display();

    return 0;
}

