/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>

int key(int num){
	int sum=0;
	int largest;
	
	if(num%2==0){
		largest = 2;
		sum+=2;
		do{num/=2;}while(num%2==0);
	}
	
	for(int i=3; i*i<=num; i+=2)
		if(num%i==0){
			largest = i;
			sum+=i;
			do{num/=i;}while(num%i==0);
		}
	if(num>2){
		largest = num;
		sum+=num;
	}
	return largest*2-sum;
}

int main(){
	int a,b;
	while(~scanf("%i %i",&a, &b)){
		if(a+b==0) break;
		if(key(a)>key(b)) printf("a\n");
		else printf("b\n");
	}
}
