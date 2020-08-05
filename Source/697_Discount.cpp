/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
int main(){
	int n;

	while(~scanf("%i",&n)){
		int bucket[101]={0};
		int sum = 0;
		for(int i=0; i<n; i++){
			int a,b,c;
			scanf("%i %i",&a, &b);
			sum+=a;
			c=a-b;
			bucket[c]++;
		}
		if (sum < 100)
			printf("%i\n",sum);
		else{
			for(int i=100, item=n/2; item>0;){
				if(bucket[i]>0){
					item--;
					bucket[i]--;
					sum-=i;
				}
				else i--;
			}
			printf("%i\n",sum);
		}
	}

	return 0;
}
