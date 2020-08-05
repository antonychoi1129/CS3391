/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<algorithm>
using namespace std;

int students[50];
int main(){
	int i;
	int sNum;
	while(~scanf("%i",&sNum)){
		int best, worst;
		
		for(i=0;i<sNum;i++)
			scanf("%i",&students[i]);
		sort(students,students+sNum);
		
		best = worst = students[sNum-1]+students[0];
		for(i=1;i<sNum/2;i++){
			int kl = students[i]+students[sNum-i-1];
			if(kl>best) best = kl;
			else if(kl<worst) worst = kl;
		}
		printf("%i\n",best-worst);
	}

	return 0;
}
