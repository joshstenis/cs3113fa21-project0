#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define MAX_BUF 1024

struct codepoint {
	int count, c;
};
typedef struct codepoint codepoint;


codepoint *buftostruct(char *buf, int bufsize);


int main(int argc, char **argv) {
	
	int filein, fileout, flagsout;
	mode_t perms;
	ssize_t numRead;
	char buf[MAX_BUF+1];
	codepoint *inputchars;

	flagsout = O_CREAT | O_WRONLY | O_TRUNC;
	perms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;	// rw-rw-rw-
	
	filein = open(argv[1], O_RDONLY, perms);
	if (filein == -1) { printf("Error opening input file.\n"); }		// open() error check


	while ((numRead = read(filein, buf, MAX_BUF)) > 0) {}			// read input file into buffer
	if(numRead == -1) { printf("Error reading input file.\n");  }
	
	if(close(filein) == -1) { printf("Error closing input file.\n"); }	// close() error check
	buf[MAX_BUF] = "\0";

	

	

	//inputchars = buftostruct(buf, sizeof(buf));				// Store characters contained in buffer to an array of codepoint structs



	// ---- QSORT ----



	return 0;
}


/**
 * Returns a pointer to a series of codepoint objects given a string buf and its size.
 **/
codepoint *buftostruct(char *buf, int bufsize) {
	codepoint counts[bufsize];
	
	for (int i=0; i < bufsize; i++) {
		int found = 0;
		printf("i = %d\n", i);
		
		for (int j=0; j < (sizeof(counts)/sizeof(codepoint)); j++) {
			printf("j = %d", j);
			
			if (buf[i] == counts[j].c) {
				counts[j].count++;
				found = 1;
				break;
			}
		}
		if (found == 0) {
			counts[sizeof(counts)/sizeof(codepoint)].c = buf[i];
			counts[sizeof(counts)/sizeof(codepoint)].count++;
		}
	} return counts;
}
