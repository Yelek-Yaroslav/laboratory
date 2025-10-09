#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));

    const int variant = 4;
    const int S = variant * 5 + 50;

    stack<int> mainStack;
    stack<int> evenStack;
    stack<int> oddStack;

    for (int i = 0; i < S; i++) {
        int num = rand() % 1000 + 1;
        mainStack.push(num);
    }

    while (!mainStack.empty()) {
        int num = mainStack.top();
        mainStack.pop();

        if (num % 2 == 0)
            evenStack.push(num);
        else
            oddStack.push(num);
    }

    cout << "Even numbers" << endl;
    while (!evenStack.empty()) {
        cout << evenStack.top() << " ";
        evenStack.pop();
    }

    cout << "\nOdd numbers" << endl;
    while (!oddStack.empty()) {
        cout << oddStack.top() << " ";
        oddStack.pop();
    }

    cout << endl;
    return 0;
}
