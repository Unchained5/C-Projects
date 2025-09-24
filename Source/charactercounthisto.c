#include <stdio.h>
#define ASCII 256 /* Number of ASCII characters */
#define DATAPOINT 219 /* ASCII code for a solid block character which I use for the datapoints in the horizontal histogram. */
/* count characters in input; 1st version */
int main() {
	int chars[ASCII];
	int i, j;
	i = j = 0;
	char c = 0;
	
	for (i = 0; i < ASCII; ++i)
		chars[i] = 0;
	
	while ((c = getchar()) != EOF)
		for (i = 0; i < ASCII; ++i)
			if (c == i)
				++chars[i];

	for (i = 0; i < ASCII; ++i) {
		if (chars[i] > 0) {
			if (i == ' ')
				printf("Space: ");
			else if (i == '\n')
				printf("Newline: ");
			else if (i == '\t')
				printf("Tab: ");
			else
				printf("%c: ", i);
			for (j = 0; j < chars[i]; ++j)
				printf("%c ", DATAPOINT);
			printf("\n\n");
		}
	}
		
	
}