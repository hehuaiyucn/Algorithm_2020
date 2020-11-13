#include<stdio.h>

unsigned int MaxCommonFactor(int a, int b) {
	if (b <= 0)
		return a;
	return MaxCommonFactor(b, a % b);
}

unsigned int Gcd(unsigned int M, unsigned int N) {
	unsigned int Rem;
	while (N > 0) {
		Rem = M % N;
		M = N;
		N = Rem;
	}
	return M;
}

/**
int main() {
	int a, b;
	scanf_s("%d %d", &a, &b);
	printf("the greatest common factor of %d and %d is ", a, b);
	printf("%d\n", Gcd(a, b));
	printf("recursion: % d\n",MaxCommonFactor(a,b));
	return 0;
}
*/
