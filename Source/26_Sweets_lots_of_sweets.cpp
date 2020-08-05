/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>

char box[401][401];

int main(){
	int cases;
	scanf("%i",&cases);
	while(cases--){
		int i,j;
		
		int r,c;
		scanf("%i %i\n",&r, &c);
		for(i=0;i<r;i++)
			gets(box[i]);
		
		int candies=0;
		for(i=0; i<r; i++)
			for(j=0; j<c; j++){
				if(box[i][j]!='o') continue;
				//>o<
				if(j>0&&j<c-1)
					if(box[i][j-1]=='>'&&'<'==box[i][j+1]) candies++;
				//vo^
				if(i>0&&i<r-1)
					if(box[i-1][j]=='v'&&'^'==box[i+1][j]) candies++;
			}
		
		printf("%i\n",candies);
	}

	return 0;
}
