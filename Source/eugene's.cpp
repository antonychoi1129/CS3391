#include <iostream>
#include <cmath>
#define ull unsigned long long int

using namespace std;

bool notAllowed(ull n, int startWith){
	while (n > 0) {
		if (n % 10 >= startWith)
			return true;
		else
			n /= 10;
	}
	return false;
}


int convTo10(ull i, int base){
	int res = 0;
	int k = 1;
	while (i > 0) {
		res += (i % 10) * k;
		i /= 10;
		k *= base;
	}
	return res;
}


int main(){
	ull n;
	while (cin >> n) {
		if (n == 0) break;
		int startWith = 1;
		double a;
		do {
here:
			startWith++;
			if (startWith >= 100) break;
			if (startWith < 10 && notAllowed(n, startWith))
				goto here;
			a = sqrt(convTo10(n, startWith));
		} while (a != (int)a);
		cout << startWith << endl;
	}
	return 0;
}
