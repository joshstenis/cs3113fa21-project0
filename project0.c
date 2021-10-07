#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define MAX_BUF 1024

struct Char {
	int count, c;
};
typedef struct Char Char;

struct String {
	int len = 0;
	int size;
	Char str[size];

	int contains(Char c) {
		for (int i=0; i < size; i++) {
			if (str[i].c == (int)c.c) { return 1; }
		} return 0;
	}

	int contains(char c) {
		for (int i=0; i < size; i++) {
			if (str[i].c == (int)c) { return 1; }
		} return 0;
	}

	Char find(char c) {
		for (int i=0; i < size; i++) {
			if (str[i].c == (int)c) { return str[i]; }
		} return NULL;
	}

	int add(char c, int count) {
		Char tmp;
		tmp.c = c;
		tmp.count = count;
		if (len > 0 && len < size) {
			str[len] = tmp;
			len++;
			return 0;
		} else { return -1; }
	}

	void toString() {
		for (int i=0; i < size; i++) { printf("Characters: %c\n", str[i].c); }
	}
};
typedef struct String String;


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


	String ch;
	ch.size = strlen(buf);
	
	for (int i=0; i < strlen(buf); i++) {
		if (buf[i] == NULL) { break; }
		
		Char tmp;
		tmp.c = buf[i];
		
		if (!ch.contains(tmp.c)) {
			for (int j=i; i < strlen(buf); j++) {
				if (tmp.c == buf[j]) { tmp.count++; }
			}
			
			if (ch.add(tmp) == 0) {
				printf("Error adding to String struct.");
			}
		} else {
			(ch.find(tmp.c))++;
		}
	}

	ch.toString();


	// printf("First char utf-8: %x\n", buf[0]);



	// ---- QSORT ----



	return 0;
}
