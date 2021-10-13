#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define MAX_BYTES 1024

struct Char {
	int count;
	char c[5];
};
typedef struct Char Char;

int cmpcount(const void *a, const void *b);


int main(int argc, char **argv) {

	char buf[5];
	ssize_t numRead;

	Char ch[MAX_BYTES];

	int idx, nbytes = 0;
	while ((numRead = read(0, buf, 1)) > 0) {
	
		buf[1] = '\0';
		int found = 0;
		nbytes = 1;

		char hex[8];
		char *cbuf;
		sprintf(hex, "%08x", buf[0]);


		if (strcmp(hex, "0000000a") != 0 && strcmp(hex, "00000020") != 0) {		
			if (hex[6] == 'f') {
				numRead = read(0, &cbuf, 1);
				buf[1] = cbuf;
				numRead = read(0, &cbuf, 1);
				buf[2] = cbuf;
				numRead = read(0, &cbuf, 1);
				buf[3] = cbuf;
				buf[4] = '\0';
				nbytes = 4;
			} else if (hex[6] == 'e') {
				numRead = read(0, &cbuf, 1);
				buf[1] = cbuf;
				numRead = read(0, &cbuf, 1);
				buf[2] = cbuf;
				buf[3] = '\0';
				nbytes = 3;
			} else if (hex[6] == 'd' || hex[6] == 'c') {
				numRead = read(0, &cbuf, 1);
				buf[1] = cbuf;
				buf[2] = '\0';
				nbytes = 2;
			}


			for (int i=0; i < idx; i++) {
				if (strncmp(ch[i].c, buf, nbytes) == 0) {
					ch[i].count++;
					found = 1;
					break;
				}
	
			} if (found == 0) {
				strncpy(ch[idx].c, buf, nbytes);
				ch[idx].c[nbytes] = '\0';
				ch[idx].count = 1;
				idx++;
			} strcpy(hex, "");
		}
	}

	if (numRead < 0) { printf("Read error.\n"); }

	qsort(&ch[0], sizeof(ch)/sizeof(Char), sizeof(Char), cmpcount);

	for (int i=0; i < idx; i++) {
		printf("%s -> %d\n", ch[i].c, ch[i].count);
	} return 0;
}

int cmpcount(const void *a, const void *b) {

	a = (const Char *)a;
	b = (const Char *)b;

	return (*a).count - (*b).count;
}

