#include <stdio.h>

int main() {
	int c;
	while ((c = getchar()) != EOF) {
		printf("%d ", c);
		if (c == '\n')
			printf("\n");
	}
}