/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>

int main(){
	int cases;
	scanf("%i",&cases);
	
	while(cases--){
		int y, m, d;
		scanf("%i %i %i",&y,&m,&d);
		int ans=0;
		
		/*I don't want to think.*/
		
		/*if(d!=1){
			ans += 19 + (y%3==0 || m%2!=0) - d + 1;
			d=1;
			m++;
			if(m>10){
				m=1;
				y++;
			}
		}
		
		if(m!=1){
			if(y%3==0)
				ans += (10-m+1)*20;
			else{
				ans += (10-m+1)*20-
			}
			m=1;
			y++;
		}*/
		
		
		while(y!=1000){
			d++;
			ans++;
			if(d > 19+(y%3==0 || m%2!=0) ){
				d=1;
				m++;
			}
			if(m>10){
				m=1;
				y++;
			}
		}
		printf("%i\n",ans);
	}
	
	return 0;
}
