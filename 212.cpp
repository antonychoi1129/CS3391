#include<iostream>
#include <math.h> 
#include<vector>

using namespace std;

unsigned ModExp(unsigned a, unsigned b, unsigned c)
{
    unsigned tmp;

    if(a==0) return 0;

    a%=c;
    
    if(b==1) return a;

    if(b==0) return (1);

    tmp = ModExp(a, b>>1, c);

    tmp = (tmp*tmp)%c;

    if (b&1) tmp = (tmp*a)%c;

    return tmp;

}

int main(){
    unsigned B, P, M;
    while(cin >> B >> P >> M){
        unsigned ans = ModExp(B, P, M);
        cout << ans << endl;
    }
}
