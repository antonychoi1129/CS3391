/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

#define ll long long

struct Node{
	int num;
	int min;
};

int const k = 10000;

Node stackIN[k];
Node stackOUT[k];

int in=0;
int ot=0;

int getMin(){
	if(in>0&&ot>0) return min( stackIN[in-1].min, stackOUT[ot-1].min);
	if(ot==0){
		int newMin = stackIN[in-1].num;
		while(in!=0){
				if(stackIN[in-1].num<newMin) newMin = stackIN[in-1].num;
				stackOUT[ ot++ ] = {stackIN[ in-1 ].num,newMin};
				in--;
			}
		return stackOUT[ot-1].min;
	}
}

void enq(int i){
	if(in==0) stackIN[in++] = {i, i};
	else{
		int eh = min(i,stackIN[in-1].min);
		stackIN[in++] = {i, eh};
	}
}

void dq(){
	if(ot==0){
		int newMin = stackIN[in-1].num;
		while(in!=0){
				if(stackIN[in-1].num<newMin) newMin = stackIN[in-1].num;
				stackOUT[ ot++ ] = {stackIN[ in-1 ].num,newMin};
				in--;
			}
	}
	ot--;
}

void printStack(){
	int i;
	printf("IN: %i\n[",in);
	for(i=0;i<in;i++)
		printf("(%i,%i) ",stackIN[i].num,stackIN[i].min);
	puts("]");
	printf("OUT %i\n[",ot);
	for(i=0;i<ot;i++)
		printf("(%i,%i)",stackOUT[i].num,stackOUT[i].min);
	puts("]");
}

int main(){
	int input;
	int i,j;

	//For 1-10000
	for(i=0; i<k; i++) {
		scanf("%i",&input);
		enq(input);
		printf("%i\n",getMin());
		//printStack();
	}
	
	while(~scanf("%i",&input)){
		dq();
		enq(input);
		printf("%i\n", getMin());
		//printStack();
	}

	return 0;
}
