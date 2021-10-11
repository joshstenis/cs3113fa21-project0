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
	
	char buf[MAX_BUF];

	scanf("%s", buf);

	Char ch[strlen(buf)];

	printf("Buffer string length: %d\n", strlen(buf));

	int idx = 0;
	for (int i=0; i < strlen(buf); i++) {					// parse input string
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

	for (int i=0; i < idx; i++) {
		printf("%c->%d\n", ch[i].c, ch[i].count);
	}


	// ---- QSORT ----



	return 0;
}
