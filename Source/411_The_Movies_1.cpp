/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#define ll long long

#include <set>
using namespace std;

int main(){
	int cases;
	scanf("%i",&cases);
	for(int c=1; c<=cases; c++){
		set< pair<ll,ll> > house;
		ll rowNum,seatNum;
		int sSize;
		scanf("%lld%lld%i",&rowNum,&seatNum,&sSize);

		ll row[sSize];

		int i;
		for(i=0; i<sSize; i++)
			scanf("%lld",&row[i]);

		ll s;
		ll ans = rowNum*(seatNum-1);
		for(i=0; i<sSize; i++){
			scanf("%lld",&s);
			if(house.find( make_pair(row[i], s) ) != house.end())
				continue;

			pair<ll,ll> left (row[i],s-1);
			pair<ll,ll> right (row[i],s+1);

			bool lo, ro;
			lo = s==1 || house.find(left)!=house.end();
			ro = s==seatNum|| house.find(right)!=house.end();

			if(lo&&ro);
			else if(lo || ro)
				ans -=1;
			else ans-=2;
			house.insert( make_pair(row[i],s) );
		}
		printf("Case #%i: %lld\n",c,ans);
	}

	return 0;
}
