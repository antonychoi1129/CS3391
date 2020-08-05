/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<set>
using namespace std;

const int MAX =  1e7;
int spf[MAX];	//Smallest Prime Factor

void soe(){	//Sieve of Eratosthenes
	int i;
	spf[1] = 1;
	for(i=2; i<MAX; i++)
		spf[i] = i;
	for(i=4; i<MAX; i+=2)
		spf[i] = 2;
	for(i=3; i*i<MAX; i++)
		if(spf[i]==i)
			for(int j=i*i; j<MAX; j+=i)
				if(spf[j]==j)
					spf[j] = i;
}

int key(int num){
	int ans=0;
	set<int> pf;
	
	while(num!=1){
		pf.insert(spf[num]);
		num = num/spf[num];
	}
	
	set<int>::iterator it;
	for(it=pf.begin(); it!=--pf.end(); it++)
		ans+=*it;
	ans = *(--pf.end()) - ans;
	return ans;
}

int main(){
	soe();
	int a,b;
	while(~scanf("%i %i",&a, &b)){
		if(a+b==0) break;
		if(key(a)>key(b)) printf("a\n");
		else printf("b\n");
	}
	
	return 0;
}
