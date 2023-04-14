#include <iostream>
#include <cstring>
#include <cmath>
#include "MyStack/MyStack.h"

using namespace std;

void Multipliers(int n, MyStack<int>& stack) {
    if (n < 2) {
        stack.push(n);
        return;
    }

    while (n % 2 == 0) {
        stack.push(2);
        n /= 2;
    }

    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            stack.push(i);
            n /= i;
        }
    }

    if (n != 1) {
        stack.push(n);
    }
}

int demo(int N=3960) {
    MyStack<int> stack, reverseStack;
    
    Multipliers(N, stack);
    cout << "Множители по возрастанию для N = " << N << endl;
    cout << N << "=" << stack.top_inf();
    reverseStack.push(stack.top_inf());
    stack.pop();
    while (!stack.empty()) {
        cout << " * " << stack.top_inf();
        reverseStack.push(stack.top_inf());
        stack.pop();
    }
    cout << endl;

    cout << "Множители по возрастанию для N = " << N << endl;
    cout << N << "=" << reverseStack.top_inf();
    reverseStack.pop();
    while (!reverseStack.empty()) {
        cout << " * " << reverseStack.top_inf();
        reverseStack.pop();
    }
    cout << endl;


    return 0;
}

int interactive() {
    cout << "Введите число, которое нужно разложить до простых множителей\n";
    int a;
    cin >> a;
    return demo(a);
}


int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");
    if ((argc == 2) && strcmp(argv[1], "i") == 0) {
        return interactive();
    }
    return demo();
}
