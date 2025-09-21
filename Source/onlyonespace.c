#include <stdio.h>
/* Ensure one space per gap in word. */
main() {
	int c, lastC;
	lastC = 0;
	while ((c = getchar()) != EOF) {
		if (lastC == ' ' && c == ' ') 
			;
		else
			putchar(c);
		lastC = c;
	}
}