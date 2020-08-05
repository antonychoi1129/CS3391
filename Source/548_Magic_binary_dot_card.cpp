/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<algorithm>
using namespace std;

#define ll unsigned long long

int main(){
	int i,j;
	
	ll bits[64];
	bits[0] = 1;
	for(i=1;i<64;i++)
		bits[i] = bits[i-1]*2;
	
	ll a,b;
	while(~scanf("%lli %lli",&a, &b)){
		ll ans = a;
		bool bad[64];
		
		ll huh = 0;
		for(i=64-1;i>=0;i--){
			bad[i] = false;
			if(a >= huh+bits[i]){
				huh += bits[i];
				bad[i] = true;
			}
		}
		
		for(i=0;i<64 & b>ans;i++){
			if(bad[i]) continue;
			ans+=bits[i];
		}
		
		printf("%llu\n",ans);
	}

	return 0;
}
