/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct C{
	char btra;
	int num;
}forSort[1000];

bool cmp(C a, C b){
	if(a.num>b.num) return true;
	if(a.num==b.num && a.btra<b.btra) return true;
	return false;
}

char plate [40][40];

int h, w;

void gogogo(int i, int j, char b){
	plate[i][j] = 'X';
	if(i>0&&plate[i-1][j]==b)
		gogogo(i-1,j,b);
	if(j>0&&plate[i][j-1]==b)
		gogogo(i,j-1,b);
	if(i<h-1&&plate[i+1][j]==b)
		gogogo(i+1,j,b);
	if(j<w-1&&plate[i][j+1]==b)
		gogogo(i,j+1,b);
}

void m(){
	int cases;
	scanf("%i",&cases);
	for(int ccc=1; ccc<=cases;ccc++){
		int cln[1000]={0};
		int i,j;
		printf("Plate #%i\n",ccc);
		scanf("%i %i\n",&h,&w);
		for(i=0;i<h;i++)
			gets(plate[i]);
		
		for(i=0;i<h;i++)
			for(j=0;j<w;j++){
				char me = plate[i][j];
				if(me=='X') continue;
				gogogo(i,j,me);
				cln[me-'a']+=1;
			}
		
		int itr=0;
		for(i=0;i<26;i++)
			if(cln[i]>0)
				forSort[itr++] = {i,cln[i]};
		
		sort(forSort,forSort+itr,cmp);
		
		for(i=0;i<itr;i++)
			printf("%c: %i\n",forSort[i].btra+'a',forSort[i].num);
	}
}

int main(){
	m();
}
