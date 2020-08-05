/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
int main(){
	int cases;
	scanf("%d\n",&cases);
	
	while(cases--){
		int hh,mm;
		scanf("%02d:%02d",&hh,&mm);
		
		int realh=12, realm=0;
		
		if(mm>0){
			realm=60;
			realh--;
		}
		
		realh-=hh;
		realm-=mm;
		if(realh<1) realh+=12;
		printf("%02i:%02i\n",realh,realm);
	}
	
	return 0;
}
