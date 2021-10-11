#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define MAX_BUF 1024

struct Char {
	int count, c;
};
typedef struct Char Char;


int main(int argc, char **argv) {
	
	int filein, fileout, flagsout;
	mode_t perms;
	ssize_t numRead;
	char buf[MAX_BUF+1];
	buf[MAX_BUF] = "\0";
	
	flagsout = O_CREAT | O_WRONLY | O_TRUNC;
	perms = S_IRUSR | S_IRGRP | S_IROTH;	// r--r--r--  , writing to input file is not necessary
	
	filein = open(argv[1], O_RDONLY, perms);
	if (filein == -1) { printf("Error opening input file.\n"); }		// open() error check


	while ((numRead = read(filein, buf, MAX_BUF)) > 0) {
		printf("Buffer: %s\n", buf);
	}			// read input file into buffer
	if(numRead == -1) { printf("Error reading input file.\n");  }
	
	if(close(filein) == -1) { printf("Error closing input file.\n"); }	// close() error check


	for (int i=0; i < strlen(buf); i++) {
		if (buf[i] == NULL) { break; }
		
		Char tmp;
		tmp.c = buf[i];
		
		if () {
			for (int j=i; i < strlen(buf); j++) {
				if (tmp.c == buf[j]) { tmp.count++; }
			}
			
			if () {
				printf("Error adding to String struct.");
			}
		} else {}
	}


	// printf("First char utf-8: %x\n", buf[0]);



	// ---- QSORT ----



	return 0;
}
