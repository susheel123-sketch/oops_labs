/*Copy constructor for a stack. Create a new constructor for class LLStack (linked-list implementation of
stack) so that LLStack t {s}; makes t reference a new and independent copy of the stack s. That is,
a deep copy of linked list pointed by s.first and make t.first point to the new list.
With deep copy, you should be able to push and pop from either s or t without influencing the other,
demonstrate this by writing client code in the main function.*/
#include <iostream>
#include <string>

using std::string, std::cout, std::endl;

class LLStack {
private:
    struct Node {
        string data;
        Node* next;
    };

    Node* first = nullptr;
    int N = 0;

public:
    LLStack() = default;

    LLStack(const LLStack& M) {
        first = nullptr;
        N = 0;

        if (M.first == nullptr) return;
        LLStack temp;
        Node* current = M.first;

        while (current != nullptr) {
            temp.push(current->data);
            current = current->next;
        }
        while (!temp.empty()) {
            push(temp.pop());
        }
    }

 

    ~LLStack() {
        while (first != nullptr) {
            Node* second = first->next;
            delete first;
            first = second;
        }
    }

    void push(string item) {
        Node* second = first;               
        first = new Node{ item, second };   
        N++;                                
    }

    string pop() {
        Node* second = first->next;  
        string d = first->data;      
        delete first;                
        first = second;              
        N--;                         
        return d;                    
    }                                

    bool empty() {
        return first == nullptr;
    }

    int size() {
        return N;
    }

};

int main() {
    LLStack s;
    s.push("hello");
    s.push("world");
    s.push("how");
    s.push("are");
    s.push("you");
    while (!s.empty()) {
        cout << s.pop() << " ";
    }
    cout << endl;

}