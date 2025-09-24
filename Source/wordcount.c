#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
/* count words in input */
int main() {
	int c, nw, state;
	state = OUT;
	nw = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("%d \n", nw);
}