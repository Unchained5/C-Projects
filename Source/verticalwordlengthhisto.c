#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define MAXLENGTH 30 /* max length of a word. */
#define DATAPOINT 220 /* ASCII code for a half block character which I use for the datapoints in the vertical histogram. */
/* Prints vertical histogram of number of words of certain length up to length of 30 */
int main() {
	int c, i, j, nw, wl, mo, state;
	state = OUT;
	nw = i = wl = mo = 0;
	int wls[MAXLENGTH + 1];
	for (i = 1; i < MAXLENGTH + 1; ++i) {
		wls[i] = 0;
	}
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t' || c == '.' || c == ',') {
			state = OUT;
			++wls[wl];
			wl = 0;
		}
		else if (state == OUT) {
			state = IN;
			++nw;
		}
		
		if (state == IN) 
			++wl;
	}
	
	int highest = 0;
	
	for (i = 1; i < MAXLENGTH + 1; ++i) {
		if (wls[i] > highest) 
			highest = wls[i];
	}
	/* Goes top to bottom, printing the datapoints or spaces, depending on whether or not they should be there. */
	for (i = highest; i > 0; --i) {
		for (j = 1; j < MAXLENGTH + 1; ++j) {
			if (wls[j] >= i && j < 10)
				printf("%c ", DATAPOINT);
			else if (wls[j] >= i)
				printf("%c  ", DATAPOINT);
			else if (j < 10)
				printf("  ");
			else 
				printf("   ");
		}
		printf("\n");
	}
	/* prints the key for the histogram*/
	for (i = 1; i < MAXLENGTH + 1; ++i) 
		printf("%d ", i);
	printf("\n");
}