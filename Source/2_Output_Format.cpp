#include <iostream>

int main(){
	int input;

	scanf("%i", &input);
	printf("%i\n", input);
	while ( scanf("%i", &input) != EOF ){
		printf("\n%i\n", input);
	}

	return 0;
}
