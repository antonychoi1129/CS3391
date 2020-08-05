#include<iostream>
#include <cstring>
#include <bitset>
using namespace std;

int b2d(char*s){
	int b = atoi (s);
	int d=0;
	for(int i=0; b>0; ++i){
		if( (b%10)==1 )
			d+=(1<<i);

		b /= 10;
	}
	return d;
};

int main(){
	//ios::sync_with_stdio(false);

	unsigned char accu, pc, memory[32];
	char input[9];

	unsigned char isrt;
	unsigned char type, value;
	while(cin>>input){
		memory[0]=b2d(input);
		for(int i=1; i<32;i++){
			cin>>input;
			memory[i] = b2d(input);
		}

		//Go go go
		accu = pc = 0;
		while(true){
			isrt = memory[pc++];
			if(pc>=32) pc=0;
			type = (isrt>>5);
			value = (isrt&0b11111);

			//000 STA x
			if (type==0)
				memory[value] = accu;

			//001 LDA x
			else if (type==1)
				accu = memory[value];

			//010 BEQ x
			else if(type==2){
				if(accu==0) pc = value;
			}

			//011 NOP
			else if (type==3){}

			//100 DEC
			else if (type==4)
				accu-=1;

			//101 INC
			else if (type==5)
				accu+=1;

			//110 JMP x
			else if (type==6)
				pc=value;

			//111 HLT
			else if (type==7){
				cout<<bitset<8>(accu).to_string()<<endl;
				break;
			}
	}

		/*cout<<b2d(input)<<endl;
		cout<<"type:"<<(memory[0]>>5)<<endl;
		cout<<"valueess:"<<(memory[0]&0b11111)<<endl;*/
	}
	return 0;
}
