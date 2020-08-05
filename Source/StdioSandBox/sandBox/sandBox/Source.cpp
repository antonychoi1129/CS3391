/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>	//Memory Monster
using namespace std;

#define oo (int)1e9;
#define r0 1e-9

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

#define ll long long
#define ull unsigned long long

#define sfd(n) scanf("%d",&n)
#define sfc(n) scanf("%c",&n)
#define sfl(n) scanf("%lld",&n)

#define pd(n) printf("%d\n",n)


// #define DEBUG true
#if DEBUG
#endif
#define $(v) if(DEBUG) cout<<#v<<"\t=\t"<<v<<endl

struct C {
	int btra;
	int num;
}forSort[30];

bool cmp(C a, C b) {
	bool aFirst = true;
	if (a.num>b.num) return aFirst;
	if (a.btra<b.btra) return aFirst;
	return false;
}

char plate[40][40];

int h, w;

int gogogo(int i, int j, char b) {
	bool alone = true;
	plate[i][j] = '0';
	if (i>0 && plate[i - 1][j] == b) {
		gogogo(i - 1, j, b);
		alone = false;
	}
	if (j>0 && plate[i][j - 1] == b) {
		gogogo(i, j - 1, b);
		alone = false;
	}
	if (i<h - 1 && plate[i + 1][j] == b) {
		gogogo(i + 1, j, b);
		alone = false;
	}
	if (j<w - 1 && plate[i][j + 1] == b) {
		gogogo(i, j + 1, b);
		alone = false;
	}
	return !alone;
}

void m() {
	int cases;
	sfd(cases);
	for (int ccc = 1; ccc <= cases; ccc++) {
		int cln[30] = { 0 };
		int i, j;
		printf("Plate #%i\n", ccc);
		scanf("%i %i\n", &h, &w);
		for (i = 0; i<h; i++)
			gets_s(plate[i]);

		for (i = 0; i<h; i++)
			for (j = 0; j<w; j++) {
				char me = plate[i][j];
				if (me == '0') continue;
				cln[me - 'a'] += gogogo(i, j, me);
			}

		int itr = 0;
		for (i = 0; i<26; i++)
			if (cln[i]>0)
				forSort[itr++] = { i,cln[i] };

		sort(forSort, forSort + itr, cmp);

		for (i = 0; i<itr; i++)
			printf("%c: %i\n", forSort[i].btra + 'a', forSort[i].num);
	}
}

int main() {
#if DEBUG
	puts("DEBUGGING");
#endif

	m();
}
