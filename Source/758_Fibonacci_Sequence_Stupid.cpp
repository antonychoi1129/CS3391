#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>

#define NMAX 5000001
#define QMAX 1000000000

using namespace std;

long long unsigned *fatNums = new long long unsigned[NMAX];

void bucketSort(unsigned n, unsigned epnt){
	long long unsigned *output = new long long unsigned[n+1];
	long long unsigned *buckets = new long long unsigned[n+1]{0};
	unsigned i;

	for(i=0; i<=n; i++) buckets[ (fatNums[i]/epnt)%n ]++;
	for(i=1; i<=n; i++) buckets[i] += buckets[i-1];

	for(i=n; i>0; i--){
		//cout<<"i: "<<i<<"\t(fatNums[i]/epnt)%n = (" <<fatNums[i]<<"/"<<epnt<<")%"<<n <<endl;
		//cout<<"buckets[ "<<(fatNums[i]/epnt)%n<<" ]:"<<buckets[ (fatNums[i]/epnt)%n ]<<endl;
		output[ buckets[ (fatNums[i]/epnt)%n ] -1 ] = fatNums[i];
		buckets[ (fatNums[i]/epnt)%n ]--;
	}

	for(i=0; i<=n; i++) fatNums[i] = output[i];

	delete[] output;
	delete[] buckets;
}

void genModdedFatSeq(unsigned n, unsigned m){
	fatNums[0] = 0;
	fatNums[1] = 1;

	unsigned i;
	for(i=2;i<=n;i++){
		fatNums[i] = (fatNums[i-1]+fatNums[i-2])%m;
	}
}

unsigned genAns(unsigned n, unsigned m){
	unsigned i;
	unsigned ans = 0;
	for(i=1; i<=n; i++){
		ans+=fatNums[i]*i%m;
		ans%=m;
	}
	return ans;
}

int main(){
	//ios::sync_with_stdio(false);
	int dumbT;
	scanf("%i",&dumbT);
	unsigned n,q;
	unsigned lastn, lastq;
	while(dumbT>0){
		dumbT--;
		scanf("%i %i",&n,&q);
		genModdedFatSeq(n,q);
		if(log(n)<=2*log(q)) sort(fatNums,fatNums+n+1);
		else if(q<10 || n<6) bucketSort(n, 1);
		else{
			bucketSort(n, 1);	//tooSlow
			unsigned radix = n;
			bucketSort(n, radix);
		}
		printf("%i\n",genAns(n,q));
		lastn = n;
		lastq = q;
	}
	return 0;
}
