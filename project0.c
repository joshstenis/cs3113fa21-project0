#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define MAX_BUF 1024


int main(int argc, char **argv) {
	
	int filein, fileout, flagsout;
	mode_t perms;
	ssize_t numRead;
	char buf[MAX_BUF+1];

	flagsout = O_CREAT | O_WRONLY | O_TRUNC;
	perms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;	// rw-rw-rw-
	
	filein = open(argv[1], O_RDONLY, perms);
	if (filein == -1) { printf("Error opening input file.\n"); }		// open() error check


	while ((numRead = read(filein, buf, MAX_BUF)) > 0) {}			// read input file into buffer
	if(numRead == -1) { printf("Error reading input file.\n");  }
	
	if(close(filein) == -1) { printf("Error closing input file.\n"); }	// close() error check
	buf[MAX_BUF] = "\0";

	

	printf("First char utf-8: %x\n", buf[0]);



	// ---- QSORT ----



	return 0;
}
