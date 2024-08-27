#include<bits/stdc++.h>
using namespace std;
bool isBalanced(string expression) 
{
    // Write your code here
    stack<char> s;

    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];
        if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            if (s.empty() || s.top() != '(') {
                return false;
            }
            s.pop();
        }
    }

    return s.empty(); 
}
int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}