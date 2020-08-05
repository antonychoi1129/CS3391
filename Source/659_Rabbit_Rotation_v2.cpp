/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>

int main(){
	int rabbitNum, qryNum, rbRtt;
	
	while(~scanf("%d %d %d",&rabbitNum, &rbRtt, &qryNum)){
		int newHead = rabbitNum-(rbRtt%rabbitNum);
		int rabbits[rabbitNum];
		for(int r=0; r<rabbitNum; r++)
			scanf("%d",&rabbits[r]);
		int qry;
		while(qryNum--){
			scanf("%d",&qry);
			printf("%d\n", rabbits[(newHead+qry)%rabbitNum] );
		}
	}
}
