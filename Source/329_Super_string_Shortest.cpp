/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char s1[1005];
char s2[1005];
int s1l, s2l;

int lcs(){
	int i,j;
	int dp[s1l+1][s2l+1];
	
	for(i=0;i<=s1l;i++)
		dp[i][0] = 0;
		
	for(i=0;i<=s2l;i++)
		dp[0][i] = 0;
	
	for(i=1; i<=s1l; i++)
		for(j=1; j<=s2l; j++){
			if(s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	
	return dp[s1l][s2l];
}

int main(){
	int cases;
	scanf("%i\n",&cases);
	
	while(cases--){
		gets(s1);
		gets(s2);
		
		s1l = strlen(s1);
		s2l = strlen(s2);
		
		printf("%i\n", s1l + s2l - lcs());
	}
	
	return 0;
}
