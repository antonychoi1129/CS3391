#include <iostream>
#include <iomanip>
#include <stack>

using namespace std;

int pcd(char c) {
    if (c == '*') return 100;
    else if (c == '+') return 10;
    else return -1;
}

stack<char> oprtStack;    // * +
stack<int> oprdStack;    // 123...9ABCDEF

void cal() {
    int v1, v2;
    v1 = oprdStack.top();
    oprdStack.pop();
    v2 = oprdStack.top();
    oprdStack.pop();

    if (oprtStack.top() == '+')
        oprdStack.push(v1 + v2);
    else oprdStack.push(v1 * v2);
    oprtStack.pop();
}

int main() {
    //ios::sync_with_stdio(false);

    char input[100];
    int result;
    while (cin >> input) {

        result = 0;
        oprtStack = stack<char>();
        oprdStack = stack<int>();

        int i;
        for (i = 0; input[i] != '\0'; i++) {
            if (input[i] >= 'A' && input[i] <= 'F')
                oprdStack.push(input[i] - 'A' + 10);

            else if (input[i] >= '0' && input[i] <= '9')
                oprdStack.push(input[i] - '0');

            else if (input[i] == '(')
                oprtStack.push(input[i]);

            else if (input[i] == ')') {
                while (oprtStack.top() != '(')
                    cal();
                oprtStack.pop();
            } else {
                while (!oprtStack.empty() && pcd(oprtStack.top()) >= pcd(input[i]))
                    cal();
                oprtStack.push(input[i]);
            }
        }

        while (!oprtStack.empty())
            cal();

        result = oprdStack.top();
        cout << uppercase << hex << result << endl;
    }
    return 0;
}
