/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>

int horBeach(char*s){
	if(strlen(s)==1) return 0;
	
	int beachs=0;
	//leftmost:
	if(s[0]=='#') beachs+=(s[1]=='.');
	
	//middle
	int i;
	for(i=1; s[i+1]!='\0'; i++)
		if(s[i]=='#')
			beachs+=( (s[i-1]=='.') + (s[i+1]=='.') );
			
	//rightmost:
	if(s[i]=='#') beachs+=(s[i-1]=='.');
	
	return beachs;
}

int updownBeach(char*up, char*down, bool odd){
	if(strlen(up)==1) return up[0]!=down[0];
	int beachs=0;
	int i;

	for(i=odd; up[i+!odd]!='\0'; i++)
		beachs += (up[i]!=down[i-odd]) + (up[i]!=down[i+!odd]);
	beachs += up[i-odd*i]!=down[i-odd*i];
	
	return beachs;
}

int main(){
	char s[51];
	char last[51];
	while(gets(s)!=NULL){
		int bLength = horBeach(s);
		bool odd = true;
		strcpy(last,s);
		do{
			gets(s);
			if(strlen(s)==0) break;	//blank line
			bLength += horBeach(s)+updownBeach(last,s,odd);
			odd = !odd;
			strcpy(last,s);
		}while(true);
		printf("%d\n",bLength);
	}
	
	return 0;
}
