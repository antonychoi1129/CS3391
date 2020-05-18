#include <iostream>
#include <string>
using namespace std;

#define MAXL 6
#define MAXN 10000

int p[MAXN] = {0};
string s;
int n, size, num, d;

void print(){
    int i, j;
    j = 0;
    if(size > d){
			while (p[j] == 0 && j < d)
				j++;
			for (i = size - 1; i >= j; i--){
				if (i == d-1)
					cout << '.';
				cout << p[i];
			}
        }
        else {
            cout << ".";
            for (i = 0; i < d - size; i++)
				cout << 0;
            
            while(p[j] == 0)
                j++;

            for (i = size-1; i >= j; i--)
                cout << p[i];
        }
        cout << endl;
}

void multiply(int num){
	int carry = 0;
    int temp, i;
	for (i = 0; i < size; i++){
		temp = carry + p[i] * num;
		carry = temp / 10;
		p[i] = temp % 10;
	}
	while (carry > 0){
		p[i++] = carry % 10;
		carry /= 10;
	}
    size = i;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i, j;
    while(cin >> s >> n){
        num = d = 0;
        for(i = 0; i < MAXL; i++){
            if(s[i] != '.'){
                num =  num * 10 + (s[i] - '0');
            }
            else {
                d = (MAXL - i - 1) * n;;
            }
        } 
        size = 1;
        p[0] = 1;
        for (i = 0; i < n; i++){
			multiply(num);
        }
        print();
    }
    return 0;
}