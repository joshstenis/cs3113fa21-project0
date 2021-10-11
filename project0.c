#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define MAX_BUF 1024

struct Char {
	int count;
	char c;
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



	Char ch[strlen(buf)];

	printf("Buffer string length: %d\n", strlen(buf));

	for (int i=0; i < strlen(buf); i++) {					// parse input string
		int idx = 0;
		int found = 0;
		char tmp = buf[i];
		
		for (int j=0; j < idx+1; j++) {				// look for existing Char obj in ch[]
			if (ch[j].c == tmp) {
				ch[j].count++;
				printf("ch[j].c: %c, new count: %d\n", ch[j].c, ch[j].count);
				found = 1;
				break;
			}
		} if (found == 0) {							// if not found, append new Char obj to ch[]
			printf("Added %c.\n", tmp);
			ch[idx].c = tmp;
			printf("ch[idx].c: %c\n", ch[idx].c);
			ch[idx].count = 1;
			printf("ch[idx].count: %d\n", ch[idx].count);
			idx++;
		}
	}

	printf("First char: %c\nCount: %d\n", ch[1].c, ch[1].count);



	// ---- QSORT ----



	return 0;
}
