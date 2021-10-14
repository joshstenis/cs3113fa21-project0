#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define MAX_BYTES 143849

struct Char {		// Stores utf-8 character and its count
	int count;
	char c[5];
};
typedef struct Char Char;

int cmpcount(const void *l, const void *r) {		// Comparator for qsort() between Char objects

	const Char *a = (const Char *)l;
	const Char *b = (const Char *)r;

	return b->count - a->count;
}


int main(int argc, char **argv) {

	char buf[5];
	ssize_t numRead;

	Char ch[MAX_BYTES];

	int idx, nbytes = 0;
	while ((numRead = read(0, buf, 1)) > 0) {		// Parses stdin
	
		buf[1] = '\0';		// assumes 1 byte character (ASCII)
		int found = 0;
		nbytes = 1;

		char hex[8];		// raw hex value of buf[0]
		char *cbuf;		// used for reading following bytes of a single character
		sprintf(hex, "%08x", buf[0]);

	
		if (hex[6] == 'f') {				// 4 byte character
			numRead = read(0, &cbuf, 1);
			buf[1] = cbuf;
			numRead = read(0, &cbuf, 1);
			buf[2] = cbuf;
			numRead = read(0, &cbuf, 1);
			buf[3] = cbuf;
			buf[4] = '\0';
			nbytes = 4;
		} else if (hex[6] == 'e') {			// 3 byte character
			numRead = read(0, &cbuf, 1);
			buf[1] = cbuf;
			numRead = read(0, &cbuf, 1);
			buf[2] = cbuf;
			buf[3] = '\0';
			nbytes = 3;
		} else if (hex[6] == 'd' || hex[6] == 'c') {	// 2 byte character
			numRead = read(0, &cbuf, 1);
			buf[1] = cbuf;
			buf[2] = '\0';
			nbytes = 2;
		}


		for (int i=0; i < idx; i++) {					// checks if current character has been found previously
			if (strncmp(ch[i].c, buf, nbytes) == 0) {
				ch[i].count++;
				found = 1;
				break;
			}

		} if (found == 0) {						// appends buf to array of found characters
			strncpy(ch[idx].c, buf, nbytes);
			ch[idx].c[nbytes] = '\0';
			ch[idx].count = 1;
			idx++;
		} strcpy(hex, "");	// empties hex
	}


	if (numRead < 0) { printf("Read error.\n"); }		// error check

	
	qsort(ch, idx, sizeof(Char), cmpcount);		// sorts array from highest -> lowest character count
	
	for (int i=0; i < idx; i++) {					// prints characters and their count
		printf("%s->%d\n", ch[i].c, ch[i].count);
	} return 0;
}
