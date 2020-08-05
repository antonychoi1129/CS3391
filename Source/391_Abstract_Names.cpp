/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>

char name1[21], name2[21];

char aeiou[6]="aeiou";

bool Yes(){
	int len = strlen(name1);
	if(len!=strlen(name2)) return false;
	
	int i,j;
	for(i=0;i<len;i++){
		for(j=0;j<5;j++)
			if(name1[i]==aeiou[j]){
				name1[i] = '7';
				break;
			}
		for(j=0;j<5;j++)
			if(name2[i]==aeiou[j]){
				name2[i] = '7';
				break;
			}
	}
	return (strcmp(name1,name2))==0;
}

int main(){
	int n;
	scanf("%i",&n);
	while(n--){
		scanf("%s",name1);
		scanf("%s",name2);
		if(Yes())puts("Yes");
		else puts("No");
	}
	

	return 0;
}
