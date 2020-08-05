/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>

int main(){
	int cases;
	scanf("%i",&cases);
	
	int ccc=1;
	while(cases--){
		int credit, numOfItems;
		scanf("%i %i",&credit, &numOfItems);
		int prices[1001]={0};
		int p;
		
		for(int i=1; i<=numOfItems; i++){
			scanf("%i",&p);
			
			if(prices[p]==0)
				prices[p]=i;
				
			int tp = credit-p;
			if(tp>0 && prices[tp]>0 && prices[tp]!=i){
				printf("Case #%d: %i %i\n",ccc++ ,prices[tp], i);
				for(int j=i+1; j<=numOfItems; j++)
					scanf("%i",&p);
				i=numOfItems+1;
			}
		}
	}
	
	return 0;
}
