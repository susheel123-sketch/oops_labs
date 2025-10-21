/*Josephus problem. In the Josephus problem from antiquity, n people are in dire straits and agree to the
following strategy to reduce the population. They arrange themselves in a circle (at positions numbered
from 0 to n − 1) and proceed around the circle, eliminating every m-th person until only one person is
left. Legend has it that Josephus figured out where to sit to avoid being eliminated.
Write a Queue client that takes two integer inputs m and n and prints the order in which people are
eliminated (and thus would show Josephus where to sit in the circle).*/
#include <iostream>
#include <string>

using std::string, std::cout, std::endl;

class LLQueue {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* first = nullptr;
    int N = 0;

public:
    LLQueue() = default;

    ~LLQueue() {
        while (first != nullptr) {
            Node* second = first->next;
            delete first;
            first = second;
        }
    }

    // linear time 
    void enqueue(int item) {
        if (first == nullptr) {
            first = new Node{ item, nullptr };
        }
        else {
            Node* current = first;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node{ item, nullptr };
        }
        N++;  
    }
    int front() {
        if (empty()) {
            throw std::out_of_range("Queue is empty!");
        }
        return first->data;
    }

    int dequeue() {
        if (empty()) {
            throw std::out_of_range("Queue is empty!");
        }

        Node* second = first->next;
        int d = first->data;
        delete first;
        first = second;  // If second is nullptr, first is also nullptr

        if (first == nullptr) N = 0;  // Explicitly reset size if queue is empty
        else N--;

        return d;
    }

    bool empty() {
        return first == nullptr;
        //return N == 0; // Equivalently
    }

    int size() {
        return N;
    }

};

int josephus(int n, int m) {
    LLQueue c;
    
    for (int i = 0; i < n; i++) {
        c.enqueue(i);
    }
    
    while (c.size() > 1) { 
        for (int count = 1; count < m; count++) {
            c.enqueue(c.dequeue());
        }
        cout << c.dequeue() << " ";
    }
    
    cout << endl;
    return c.dequeue();
}



//int main() {
//    LLQueue q;
//    q.enqueue("hello");
//    q.enqueue("world");
//    q.enqueue("how");
//    q.enqueue("are");
//    q.enqueue("you");
//    while (!q.empty()) {
//        cout << q.dequeue() << " ";
//    }
//    cout << endl;
//
//}