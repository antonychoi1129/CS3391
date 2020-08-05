/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>

int snail(int h, int u, int d, int f){
	//h = dept of well
	//u = 1st day climb dist
	//d = dist slide down
	//f = discount factor
	int day=1;
	double progress = 0;
	double pct = 1;
	double fff = f/100.0;
	do{
		//day
		progress+=u*pct;
		if(progress>=h) return day;
		day++;
		progress-=d;
		if(u*pct-d<0) return -day;
		pct *= fff;
	}while(true);
	return -day;
}

int main(){
	int h, u, d, f;
	while(~scanf("%i %i %i %i",&h,&u,&d,&f)){
		int res = snail(h,u,d,f);
		if(res>0)
			printf("succeeded on day %i\n", res);
		else
			printf("failed on day %i\n", -res);
	}
	
	return 0;
}
