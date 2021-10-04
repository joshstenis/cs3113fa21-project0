#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_BUF 1024

int main(int argc, char **argv) {
	
	int filein, fileout, flagsout;
	mode_t perms;
	ssize_t numRead;
	char buf[MAX_BUF];

	filein = open(argv[1], O_RDONLY, perms);
	if (filein == -1) { printf("Error opening input file.\n"); }		// open() error check

	flagsout = O_CREAT | O_WRONLY | O_TRUNC;
	perms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;	// rw-rw-rw-
	fileout = open(argv[2], flagsout, perms);
	if (filein == -1) { printf("Error opening output file.\n"); }		// open() error check

	while ((numRead = read(filein, buf, MAX_BUF)) > 0) {			// Count characters in filein
		if(write(fileout, buf, numRead) != numRead) { printf("Error writing to output file.\n"); }		
	}
	
	if(numRead == -1) { printf("Error reading input file.\n"); }		// read() error check
	if(close(filein) == -1) { printf("Error closing input file.\n"); }	// close() error checks
	if(close(fileout) == -1) { printf("Error closing output file.\n"); }
	


	// ---- QSORT ----



	return 0;
}
