#include<stdio.h>
int main(){
	int r,w,l;
	int pizza = 1;
	
	while(~scanf("%i",&r)){
		if(r==0) break;
		printf("Pizza %i ",pizza++);
		
		scanf("%i %i",&w, &l);
		int dm=r*2;
		if(w*w+l*l<=dm*dm)
			printf("fits on the table.\n");
		else
			printf("does not fit on the table.\n");
	}
	
	return 0;
}
