#include <stdio.h>
#include <string.h>

int n;

void solve(int x) {
	if (x >= 5) {
		printf("-O|");
		x -= 5;
	}
	else {
		printf("O-|");
	}
	if (x == 0) {
		puts("-OOOO");
	}
	else if (x == 1) 
		puts("O-OOO");
	else if (x == 2)
		puts("OO-OO");
	else if (x == 3)
		puts("OOO-O");
	else 
		puts("OOOO-");
}

int main(void) {
	while (~scanf("%d", &n)) {
		if (n == 0)
			puts("O-|-OOOO");
		while (n) {
			solve(n%10);
			n /= 10;
		}
	}

	return 0;
}
