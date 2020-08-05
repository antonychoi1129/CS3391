#include<stdio.h>
using namespace std;

int main(){
    int testcases;
    scanf("%i",&testcases);
    for(int t=0; t<testcases; t++){
        int n;
        scanf("%i",&n);

        n-=2;
        printf( "%i\n", ( n & -(0 < n) ) );
    }
    return 0;
}
