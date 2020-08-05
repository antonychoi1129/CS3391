#include<stdio.h>
#include<set>
#include<math.h>
#include<string.h>

#include<stdlib.h>
using namespace std;

#define ll unsigned long long

const int n = 125;

int main(){
	bool ved[n];
	memset(ved,false,sizeof(ved));

	int p[n], pc = 0;
	ll i, j;
	for(i=2; i<65;i++){
		if(ved[i]){
			p[pc++] = i;
			continue;
		}
		for(j=i*2;j<65;j+=i)
			ved[j] = true;
	}
	
	set<ll> op;
	op.insert(1);
	
	ll mt = 1<<16;
	for(i=2;i<mt;i++){
		ll in = i*i*i*i;
		op.insert(in);
		int jEnd = ceil(64 * log(2) / log(i));
		for(j=1; p[j] < jEnd; j++){
			in*=i;
			if( p[j]-p[j-1] != 1 )
				in*=i;
			op.insert(in);
		}
	}
	
	set<ll>::iterator it = op.begin();
	for(it;it!=op.end();it++)
		printf("%llu\n",*it);
}
