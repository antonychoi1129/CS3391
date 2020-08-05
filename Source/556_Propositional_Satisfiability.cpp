/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

//Try a&!b, this code is wrong. Like most of yours.

#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;

#define MAXL 200


int cvv[50];

bool lweak(char a, char b){
	return cvv[a]<cvv[b];
}

//infix permission: r--
void i2p(const char* infix, char*pofix){
	stack<char> stk = stack<char>();
	int i,j;
	int pfPos=0;	//postfix "cursor"

	for(i=0; i<strlen(infix);i++){
		char c = infix[i];

		//Annoying brackets
		if(c=='(') stk.push(c);
		else if(c==')'){
			while(stk.top() != '(' ){
				pofix[pfPos++] = stk.top();
				stk.pop();
			}
			stk.pop();	//remove the stupid '('
		}
		else if(c=='!'||c=='&'||c=='+'){
			while(!stk.empty() && !lweak(stk.top(),c)){
				pofix[pfPos++] = stk.top();
				stk.pop();
			}
			stk.push(c);
		}
		else pofix[pfPos++] = infix[i];
	}

	//Handle the rest.
	while(!stk.empty()){
		pofix[pfPos++] = stk.top();
		stk.pop();
	}
	pofix[pfPos]='\0';
}

int main(){
	cvv['!'] = 3;
	cvv['&'] = 2;
	cvv['+'] = 1;
	cvv['('] = 0;

	char input[MAXL];
	int i,j;
	while(gets(input)!=NULL){
		char infix[MAXL];
		for(i=0, j=0; i<strlen(input);i++)
			if(input[i]!=' ') infix[j++]=input[i];	//remove white spaces
		infix[j]='\0';

		//init
		char pofix[MAXL];
		i2p(infix, pofix);	//infix -> postfix

		//Turns all to true first
		for(i=0;i<strlen(pofix);i++)
			if(pofix[i]>='a') pofix[i]='T';

		stack<char> sk = stack<char>();
		for(i=0;i<strlen(pofix);i++){
			char v1, v2;
			char c = pofix[i];
			if(c=='+'){
				v1 = sk.top();
				sk.pop();
				v2 = sk.top();
				sk.pop();

				if(v1=='T' || v2=='T') sk.push('T');	//T+T T+F
				else sk.push('F');	//F+F
			}
			else if(c=='&'){
				v1 = sk.top();
				sk.pop();
				v2 = sk.top();
				sk.pop();

				if(v1=='T' && v2=='T') sk.push('T');	//T*T
				else sk.push('F');	//F*X
			}
			else if(c=='!'){
				v1 = sk.top();
				sk.pop();

				if(v1=='F') sk.push('T');
				else sk.push('F');
			}
			else
				sk.push(c);
		}

		char ans[MAXL];
		int ansPos = 0;

		while(!sk.empty()){
			ans[ansPos++] = sk.top();
			sk.pop();
		}
		ans[ansPos]='\0';

		if(ans[0]=='T') puts("YES");
		else puts("NO");
	}

	return 0;
}
