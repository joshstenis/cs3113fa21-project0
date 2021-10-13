#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define MAX_BUF 1024

struct Char {
	int count;
	char *c;
};
typedef struct Char Char;


int main(int argc, char **argv) {
	
	char buf[MAX_BUF];

	scanf("%s", buf);

	printf("Buf: %s\n", buf);

	Char ch[strlen(buf)];

	printf("Buffer string length: %d\n", strlen(buf));

	int idx = 0;
	int nbytes;
	for (int i=0; i < strlen(buf); i+=nbytes) {					// parse input string
	
		int found = 0;
		nbytes = 1;
		char hex[8];
		sprintf(hex, "%x", buf[i]);

		char tmp[5];
		tmp[4] = '\0';
		if (hex[6] == 'f') { 
			tmp[0] = buf[i];
			tmp[1] = buf[i+1];
			tmp[2] = buf[i+2];
			tmp[3] = buf[i+3];
			nbytes = 4;
		}
		else if (hex[6] == 'e') {
			tmp[0] = buf[i];
			tmp[1] = buf[i+1];
			tmp[2] = buf[i+2];
			nbytes = 3;
		}
		else if (hex[6] == '8') {
			tmp[0] = buf[i];
			tmp[1] = buf[i+1];
			nbytes = 2;
		}
		else { tmp[0] = buf[i]; }


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
			strcpy(ch[idx].c, tmp);
			printf("ch[%d].c: %s\n", idx, ch[idx].c);
			ch[idx].count = 1;
			printf("ch[%d].count: %d\n", idx, ch[idx].count);
			idx++;
		}
	}

	
	
	// ---- QSORT ----
	
	
	
	for (int i=0; i < idx; i++) {
		printf("%s->%d\n", ch[i].c, ch[i].count);
	} return 0;
}
