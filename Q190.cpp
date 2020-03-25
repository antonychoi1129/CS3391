#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool hasHigherPreference(char s_top, char c){

  if ((c == '+' || c== '-') && (s_top == '*' || s_top == '/'))
    return true;

  if ((c == '+' || c== '-') && (s_top == '+'  || s_top == '-'))
    return true;

  if ((c == '*' || c== '/') && (s_top == '*' || s_top == '/'))
    return true;

  return false;
}

bool isOperator(char c){
  if (c == '+' || c == '-' || c == '*' || c== '/')
    return true;
  return false;
}

int main() {
  int t;
  char c;
  stack<char> s;
  string postfix;
  
  cin >> t;
  cin.ignore(1, '\n');
 
    while (t--) {
      postfix = "";

      cin.ignore(11, '\n');
  
      while (cin >> c) {
        
        if (c == '(') 
            s.push(c);
        else if(c ==')'){
         while(s.top() != '('){  
            postfix += s.top(); 
            s.pop();
          }
          s.pop(); 
        } else if (!isOperator(c)) {
          postfix += c;
        } else if (isOperator(c)){
          while(!s.empty() && hasHigherPreference(s.top(),c)){
            postfix += s.top();
            s.pop();
          }
          s.push(c);
        }
      }
      while(!s.empty()){
        postfix += s.top();
        s.pop();
      }
      if (t)
        cout << postfix << endl << endl;
      else
        cout << postfix << endl;
    }
  }
