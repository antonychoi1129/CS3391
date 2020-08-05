/*By reading the folbuying code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>

int main(){
	int months;
	int buy, sell;
	int maxMoney;
	int price;
	while(~scanf("%i",&months)){
		scanf("%i %i",&buy, &sell);
		
		maxMoney = sell-buy;
		if(sell<buy) buy=sell;
		months-=2;
		
		while(months--){
			scanf("%i",&price);
			if(price>sell){
				sell = price;
				int pf = sell-buy;
				if(pf > maxMoney) maxMoney = pf;
			}
			if(price<buy){
				buy = price;
				sell = -1;
			}
		}
		
		if(maxMoney>=0) printf("%i\n",maxMoney);
		else printf("QUIT\n");
	}
	
	return 0;
}
