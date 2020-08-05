#include<stdio.h>
#include<string.h>

char s[51];

int main(){

while( gets(s)!=NULL){
if ( s[ 0 ] == 'A' || s[ strlen(s) -1] == 'A' ) puts("Ryan");
else puts("Bret");
}
}
