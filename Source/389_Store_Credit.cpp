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
		int prices[numOfItems];
		
		for(int i=0; i<numOfItems; i++){
			scanf("%i",&prices[i]);
			if(prices[i]<credit)
				for(int j=0; j<i; j++)
					if(prices[j]+prices[i]==credit){
						printf("Case #%d: %i %i\n",ccc++ ,j+1, i+1);
						break;
					}
		}
	}
	
	return 0;
}
