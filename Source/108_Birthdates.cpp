/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>

int main(){
	int n;
	scanf("%i",&n);
	
	char young[15];
	char old[15];
	int yage = 0, oage = 99999999;
	while(n--){
		int i;
		char name[15];
		int dd,mm,yy;
		scanf("%s %d %d %d",name,&dd,&mm,&yy);
		int val = yy*10000+mm*100+dd;
		if(val>yage){
			yage = val;
			for(i=0; name[i]!='\0'; i++)
				young[i] = name[i];
			young[i] = '\0';
		}
		if(val<oage){
			oage = val;
			for(i=0; name[i]!='\0'; i++)
				old[i] = name[i];
			old[i] = '\0';
		}
	}
	puts(young);
	puts(old);
	
	return 0;
}
