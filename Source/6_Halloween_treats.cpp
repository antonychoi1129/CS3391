/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

//Ref:	http://www.cnblogs.com/ACShiryu/archive/2011/08/09/poj3370.html

#include<stdio.h>
#define ll long long

int main(){
	int c, n;
	while(~scanf("%i %i",&c, &n)){
		if(c==0 && n==0) break;
		
		int mod[100000]={0}, nb[100000];
		for(int i=0; i<n; i++)
			scanf("%i",&nb[i]);
		
		mod[0] = -1; //1 Stone 2 Bird.
		
		ll sum = 0;
		for(int i=0; i<n; i++){
			sum+=nb[i];
			
			if(mod[sum%c]!=0 ){
				for(int j=mod[sum%c]+1; j<=i; j++){
					printf("%i",j+1);
					if(j!=i) printf(" ");
				}
				puts("");
				break;
			}
			mod[sum%c] = i;	//Rmember the location, starts from 1
		}
	}

	return 0;
}
