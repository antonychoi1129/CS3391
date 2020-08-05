/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>

bool isEven(int i){
	return i%2==0;
}

bool bertWins(int hd, int ty){
	//if(isEven(hd) && hd!=0) hd=2;
	int money = hd*100 + ty*10;
	while(money>=220){
		money-=220;
		if(money<0) return false;
		
		if(hd>=2){
			hd-=2;
			ty-=2;
		}
		else if(hd==1){
			hd-=1;
			ty-=12;
		}
		else
			ty-=22;
		if(hd<0 || ty <0) return false;
		
		money -= 220;
		if(money<0) return true;
		if(ty>=22) ty-=22;
		else if(ty>=12){
			hd-=1;
			ty-=12;
		}
		else{
			hd-=2;
			ty-=2;
		}
		if(hd<0 || ty <0) return true;
	}
	return false;
}

int main(){
	int x,y;
	
	bool bWin;
	int lastj;
	for(int i=0; i<=10; i++){
		for(int j=0; j<=44; j++){
			if(j==0){
				bWin = bertWins(i,j);
				lastj = 0;
			}
			else{
				if(bertWins(i,j)!=bWin){
					if(bWin) printf("100:%i\t10:[%i-%i]\t- bert wins\n", i, lastj, j-1);
					else printf("100:%i\t10:[%i-%i]\t- kennth wins\n", i, lastj, j-1);
					bWin = !bWin;
					lastj = j;
				}
			}
		}
		if(bWin) printf("100:%i\t10:[%i-%i]\t- bert wins\n", i, lastj, 44);
		else printf("100:%i\t10:[%i-%i]\t- kennth wins\n", i, lastj, 44);
	}
	
	while(~scanf("%i %i",&x, &y)){
		if(bertWins(x,y))
			printf("Bert\n");
		else printf("Kengood\n");
	}
	
	return 0;
}
