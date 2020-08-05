/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>

int main(){
	int rabbitNum, qryNum, rbRtt;
	
	while(~scanf("%i %i %i",&rabbitNum, &rbRtt, &qryNum)){
		int newHead = (rabbitNum-(rbRtt%rabbitNum))%rabbitNum;
		int rabbits[rabbitNum+1];
		for(int r=0; r<rabbitNum; r++)
			scanf("%i",&rabbits[r]);
		int qry;
		while(qryNum--){
			scanf("%i",&qry);
			printf("%i\n", rabbits[(newHead+qry)%rabbitNum] );
		}
	}
	
	return 0;
}
