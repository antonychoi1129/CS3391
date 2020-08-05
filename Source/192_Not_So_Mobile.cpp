#include<stdio.h>

bool isEqlbm;

int checkcheck(){
	int left_w, left_d, right_w, right_d;
	//cin>>left_w>>left_d>>right_w>>right_d;
	scanf("%i %i %i %i",&left_w,&left_d,&right_w,&right_d);
	
	if(left_w==0)
		left_w = checkcheck();
	if(right_w==0)
		right_w = checkcheck();
	
	if(left_w*left_d != right_w*right_d)
		isEqlbm = false;
	
	return left_w + right_w;
}

int main(){
	//ios::sync_with_stdio(false);
	
	int testcases;
	//cin>>testcases;
	scanf("%i",&testcases);
	
	int input;
	for(int t=0;t<testcases; t++){
		isEqlbm = true;
		
		checkcheck();


		if(isEqlbm) printf("YES\n");
		else printf("NO\n");
		
		if(t+1<testcases) printf("\n");	//Weird UvA X(
	}
	
	return 0;
}
