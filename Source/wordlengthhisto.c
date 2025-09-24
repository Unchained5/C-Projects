#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define MAXLENGTH 30 /* max length of a word. */
#define DATAPOINT 219 /* ASCII code for a solid block character which I use for the datapoints in the histogram. */
/* Prints number of words of certain length up to length of 30 */
int main() {
	int c, i, nw, wl, state;
	state = OUT;
	nw = i = wl = 0;
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
	for (i = 1; i < MAXLENGTH + 1; ++i) {
		printf("%d long: ", i);
		if (wls[i] > 0) {
			for (int j = 0; j < wls[i]; ++j)	
				printf("%c ", DATAPOINT);
			printf("\n\n");
		}
		else
			printf("\n\n");
	}
}