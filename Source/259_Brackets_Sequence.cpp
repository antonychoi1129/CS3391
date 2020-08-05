/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>

using namespace std;

#define oo 1e9;

bool isBalance(char a, char b){
	if(a=='(' && b ==')') return true;
	if(a=='[' && b ==']') return true;
	return false;
}

int main(){
	int cases;
	scanf("%i",&cases);
	getchar();
	int c = cases;
	char s [1000];
	bool boo = false;
	while(c--){
		getchar();
		gets(s);

		int slen = strlen(s);

		if(boo)
			puts("");
		else
			boo = true;

		if(slen<=0){
			puts("0");
			continue;
		}

		int dp[500][500];
		memset(dp,0,sizeof(dp));

		int i,j,k;
		for(i=0; i<slen; i++)
			dp[i][i]=1;

		for(i=1; i<slen; i++)
			for(int k=0; i+k<slen; k++){
				int j=i+k;
				dp[k][j]=oo;
				if(isBalance(s[k],s[j]))
					dp[k][j]=dp[k+1][j-1];

				for(int l=k; l<j; l++)
					dp[k][j]=min(dp[k][j], dp[k][l]+dp[l+1][j]);
			}
		printf("%i\n",slen+dp[0][slen-1]);
	}

	return 0;
}
