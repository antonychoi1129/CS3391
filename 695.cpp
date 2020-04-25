#include<iostream>
#include <math.h> 
#include<vector>

using namespace std;

int len;
int product[10000] = { 0 };

void multiply(int a[], int n){
	int carry = 0, i;
	for (i = 0; i < len; i++){
		int tmp = a[i] * n + carry;
		a[i] = tmp % 10;
		carry = tmp / 10;
	}
	while (carry){
		a[i++] = carry % 10;
		carry /= 10;
	}
	len = i;
}

int main(){
    char input[6];
    int n;
    while(cin >> input >> n){
        int num, p = 0;
        for(int i = 0; i < 6; i++){
            if(input[i] == '.') 
                p = i;
            else
                num += (int)(input[i] - '0') * 10;
        }
    }
}
