/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define sfd(n) scanf("%d",&n)
//--------------------------------------------------------------------------

short coders[50];
short betterThanMeInRoom[51];
void m(){
	int n;
	while(~sfd(n)){
		memset(betterThanMeInRoom,0,sizeof betterThanMeInRoom);
		int me;
		int meRoom;
		int i,j;
		for(i=0;i<n;i++) sfd(coders[i]);
		me = coders[0];
		
		sort(coders,coders+n);
		int k;
		sfd(k);
		if(me==coders[n-1]){
			puts("0");
			continue;
		}
		for(i=n-1;i>=0;i--){
			if(coders[i]==me)
				meRoom = i%k+1;
			else if(coders[i]>me)
				betterThanMeInRoom[i%k+1]++;
		}
		printf("%i\n",betterThanMeInRoom[meRoom]);
	}
}

int main(){
	m();
}
