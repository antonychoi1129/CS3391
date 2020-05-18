#include<iostream>
#include<string>
#include <string.h> 
#include <algorithm>
using namespace std;

#define MAXL 1000000

string ACGT = "ACGT";
int cnt[MAXL];
int nxt[MAXL][4];
char s[MAXL], p[MAXL];

int itr;
int oDepth, oNum;

void search(int i, int d){
	s[d] = 0;
	if(cnt[i] > 1 && d > oDepth){
		oDepth = d;
		oNum = cnt[i];
        strcpy(p, s);
	}
	
	for(int j = 0; j < 4; j++)
		if(nxt[i][j] != -1){
			s[d] = ACGT[j];
			search(nxt[i][j], d+1);
		}
}

int index(char c){
    if(c == 'A') return 0;
	if(c == 'C') return 1;
	if(c == 'G') return 2;
	if(c == 'T') return 3;
    return -1;
}

void add(int i, char *sfx){
	cnt[i]++;
	if(sfx[0]=='\0') return;
	int &newi = nxt[i][index(sfx[0])];
	if(newi == -1) {
        newi = itr++;
    }
	add(newi, sfx+1);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin >> s;
        for(int i = 0; i < MAXL; i++){
            cnt[i] = 0;
            for(int j = 0; j < 4; j++){
                nxt[i][j] = -1;
            }
        }
		
		itr = 1;
		for(int i = 0; i < strlen(s); i++)
			add(0, s + i);
			
		oDepth = oNum = 0;
		search(0, 0);
		if(oNum>0)
            cout << p << " " << oNum << endl;
		else cout << "No repetitions found!" << endl;
	}
	return 0;
}
