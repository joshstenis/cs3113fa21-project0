#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define MAX_BUF 1025

struct Char {
	int count;
	char c[5];
};
typedef struct Char Char;


int main(int argc, char **argv) {
	
	char buf[MAX_BUF];
	buf[MAX_BUF] = '\0';

	scanf("%s", buf);

	printf("Buf: %s\n", buf);

	Char ch[strlen(buf)];

	printf("Buffer string length: %d\n", strlen(buf));

	int idx = 0;
	int nbytes;
	for (int i=0; i < strlen(buf); i+=nbytes) {					// parse input string

		printf("i: %d\n", i);

		int found = 0;
		char hex[8];
		sprintf(hex, "%x", buf[i]);

		char tmp[5];
		if (hex[6] == 'f') { 
			// tmp = malloc(5);
			tmp[0] = buf[i];
			tmp[1] = buf[i+1];
			tmp[2] = buf[i+2];
			tmp[3] = buf[i+3];
			tmp[4] = '\0';
			nbytes = 4;
		} else if (hex[6] == 'e') {
			printf("3 byte char.\n");
			// tmp = malloc(4);
			tmp[0] = buf[i];
			tmp[1] = buf[i+1];
			tmp[2] = buf[i+2];
			tmp[3] = '\0';
			nbytes = 3;
		} else if (hex[6] == 'c' || hex[6] == 'd') {
			// tmp = malloc(3);
			tmp[0] = buf[i];
			tmp[1] = buf[i+1];
			tmp[2] = '\0';
			nbytes = 2;
		} else {
			// tmp = malloc(2);
			tmp[0] = buf[i];
			tmp[1] = '\0';
			nbytes = 1;
		}

		printf("Current character: %s\n", tmp);


		for (int j=0; j < idx; j++) {				// look for existing Char obj in ch[]
			if (strncmp(ch[j].c, tmp, nbytes) == 0) {
				ch[j].count++;
				printf("Tmp: %s, Idx: %d	", tmp, idx);
				printf("ch[%d].c: %s, new count: %d\n", j, ch[j].c, ch[j].count);
				found = 1;
				break;
			}
		} if (found == 0) {							// if not found, append new Char obj to ch[]
			printf("Added %s.\n", tmp);
			// ch[idx].c = malloc(nbytes+1);
			strcpy(ch[idx].c, tmp);
			// ch[idx].c += '\0';
			printf("ch[%d].c: %s\n", idx, ch[idx].c);
			ch[idx].count = 1;
			printf("ch[%d].count: %d\n", idx, ch[idx].count);
			idx++;
			printf("nbytes: %d\n", nbytes);
		} // free(tmp);
	}

	
	
	// ---- QSORT ----
	
	
	
	for (int i=0; i < idx; i++) {				// prints output
		printf("%s -> %d\n", ch[i].c, ch[i].count);
	} 
	
	/*for (int i=0; i < idx; i++) {				// frees allocated memory from all the Char.c member vars
		free(ch[i].c);
	} */ return 0;
}
