/*Write a Stack client that reads a string of parentheses, square brackets, and curly braces from standard
input and uses a stack to determine whether they are properly balanced. For example, your program
should print true for [()]{}{[()()]()} and false for [(]).*/
#include <iostream>
#include <stack>
using namespace std;

bool isb() {
    cout << "Enter the set of parentheses: ";
    string str;
    cin >> str;

    stack<char> sctack;
    bool valid = true;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
           sctack.push(str[i]);
        }
        else {
            if (sctack.empty()) {
                valid = false;
                break;
            }

            if ((sctack.top() == '(' && str[i] == ')') ||
                (sctack.top() == '{' && str[i] == '}') ||
                (sctack.top() == '[' && str[i] == ']')) {
                sctack.pop();
            }
            else {
                valid = false;
                break;
            }
        }
    }

    if (!sctack.empty()) {
        valid = false;
    }

    return valid;
}

int main() {
    cout << isb() << endl;
    cout << isb() << endl;
    cout << isb() << endl;
    cout << isb() << endl;

    return 0;
}
