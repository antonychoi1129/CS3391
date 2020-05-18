#include <iostream>  
#include <cstring>
#include <stack>
#include <math.h> 
using namespace std;


bool hasHigherPreference(char s_top, char c){
    int s;
    int n;

    switch(s_top){
        case '+':   s = 1; break;
        case '*':   s = 2; break;
        default :   s = 0; break;
    }
    switch(c){
        case '+':  n = 1; break;
        case '*':  n = 2; break;
    }

    if (s >= n)  
        return true; 
    return false; 
}

bool isOperator(char c){
  if (c == '+' || c == '*' || c == '(' || c == ')')
    return true;
  return false;
}

int cal(stack<char> &op, stack<int> &operand){
    int o2 = operand.top();
    operand.pop();
    int o1 = operand.top();
    operand.pop();
    int r;
    switch(op.top()){
        case '+' : 
            r = o1+o2;
            break;
        case '*' : 
            r = o1*o2;
            break;
        default:
            break;
    }
    op.pop();
    operand.push(r);
    return r;
}

int main(){
    stack<char> op;
    stack<int> operand;
    int res = 0;
    const int base = 16;
    string input;
    while(cin >> input){
        for(int i=0; i < input.size(); i++){
            if (input[i]  == '(') 
                op.push(input[i]);
            else if(input[i]  ==')'){

                if (operand.size() == 1){
                    res = operand.top();
                    break;
                }
                

            while(op.top() != '('){  
                res = cal(op, operand);
            }
            op.pop();

            } else if (isOperator(input[i])){
            while(!op.empty() && hasHigherPreference(op.top(),input[i])){
                res = cal(op, operand);
            }
            op.push(input[i]);
            
            } else if(!isOperator(input[i])){

                if(input[i] >= '0' && input[i] <= '9')
                    operand.push(int(input[i] - '0'));   
                else 
                    operand.push(int(input[i] - 'A' + 10));   
                
            }
        }
         while(!op.empty() && operand.size() != 1){
            res = cal(op, operand);
        }
            
        cout << hex << uppercase <<  res << endl ; 
    }
   
   
    
    
    return 0;
}

