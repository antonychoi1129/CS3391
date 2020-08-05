/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<algorithm>
using namespace std;

#define ll long long

void showCard(ll input, int length){
	for(int i = length ; i>=0; i--){
		int bit = input>>i;
		if(bit&1)
			printf("1");
		else
			printf("0");
	}
	printf(" (%lli) ",input);
}

ll good(ll b, ll a){
	ll gd = b;
	
	gd |= gd >> 16;
	gd |= gd >> 8;
	gd |= gd >> 4;
	gd |= gd >> 2;
	gd |= gd >> 1;
	gd ^= gd >> 1;
	
	return min(b,gd+(a&b));
}

bool allOne(ll n){
	return ( ((n+1) & (n))==0 );
}

int main(){
	ll a,b;
	while(~scanf("%lli %lli",&a, &b)){
		if(allOne(b)){
			printf("%lli\n",b);
			continue;
		}
		ll ans = b;
		int len = 64;
		ll i,j;
		
		for(i=good(b,a);i>a&&i>b/2;i--){
			/*printf("%lli <- %lli\t\n",i,i-1);
			showCard(i, len);puts("");
			showCard(i-1, len);puts("->");
			showCard(i^(i-1), len);puts("");
			puts("");*/
			if( ans < ( ans | i^(i-1) ) ){
				ans = ( ans | i^(i-1) );
				break;
			}
		}
		printf("%lli\n",ans);
	}

	return 0;
}
