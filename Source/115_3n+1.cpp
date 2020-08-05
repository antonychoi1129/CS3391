/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>

const int upBound = 1000000;
//bool ved[upBound]={0};
int pLengths[upBound]={0};

int min(int a, int b){
	if(a>b) return b;
	return a;
}

int max(int a, int b){
	if(a>b) return a;
	return b;
}

int psycho(long long n){
	if(n==1) return 1;
	if(n&1) n+= (n<<1)+1;	//n<<1 = n*2	n*2+n+1
	else n >>= 1;
	
	if(n<upBound){
		if(!pLengths[n])
			pLengths[n] = psycho(n);
		return 1 + pLengths[n];
	}
	return psycho(n)+1;
}

int main(){
	int left, right;
	while(~scanf("%i %i",&left, &right)){
		int ans=0;
		for(int i=min(left,right); i<=max(left,right); i++){
			int res = psycho(i);
			if(res>ans) ans = res;
		}
		printf("%i %i %i\n",left, right, ans);
	}

	return 0;
}
