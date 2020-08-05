#include<stdio.h>
#include<string.h>

int main(){
	int n;
	while(~scanf("%i\n",&n)){
		int stNum=1;
		char s[81];
		while(n--){
			gets(s);
			int bacons=0;
			
			for(int i=0; i<strlen(s); i++){
				if(strncmp(s+i,"France",6)==0){
					bacons++;
					i+=6-1;
				}
			}
			printf("Sentence #%i: %i\n",stNum++, bacons);
		}
	}
	return 0;
}
