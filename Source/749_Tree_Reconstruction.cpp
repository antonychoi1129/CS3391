#include <stdio.h>

//Global variable <<DANGEROUS>>
//Print postOrder while building the tree
//And now the tree doesnt even exist
//Invisible tree @_@
//Try with stdio.h...

int preOrderItr;
bool postFirst;
void reConstructor(int * preO, int * inO, int from, int to){
	if (from > to) return;

	int treeRootData = preO[preOrderItr];
	preOrderItr++;
	
	if (from == to){
		if(!postFirst)
			printf(" ");
		else postFirst = false;
		
		printf("%i",treeRootData);
		return;
	 }

	int iORootIndex;
	for (iORootIndex = from; iORootIndex < to; iORootIndex++)
		if (inO[iORootIndex] == treeRootData) break;

	reConstructor(preO, inO, from, iORootIndex - 1);
	reConstructor(preO, inO, iORootIndex + 1, to);

	printf(" %i",treeRootData);
	return;
}


int main(){
	int T;
	int preOrder[100];
	int inOrder[100];
	int N;
	int i;

	scanf("%i",&T);
	for (int cases = 0; cases < T; cases++) {
		scanf("%i",&N);
		for (i = 0; i < N; i++)
			scanf("%i",&preOrder[i]);
		for (i = 0; i < N; i++)
			scanf("%i",&inOrder[i]);
			
		preOrderItr = 0;
		postFirst = true;
		reConstructor(preOrder, inOrder, 0, N-1);
		printf("\n");
	}

	return 0;
}
