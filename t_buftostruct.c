#include <stdio.h>


/*
 *
 *
 *		DEPRECATED -- INCOMPLETE
 *
 *
 *
 *
 */





struct codepoint {
	int count, c;
};
typedef struct codepoint codepoint;


codepoint *buftostruct(char *buf);


int main() {


	return 0;
}

codepoint *buftostruct(char *buf) {
	codepoint *chars;

	for (int i=0; i < strlen(buf); i++) {
		int found = 0;
		
		for (int j=0; j < sizeof(chars)/sizeof(codepoint); i++) {
			
			if ((int)buf[i] == chars[j].c) {
				chars[j].count++;
				found = 1;
				break;
			}
		}

		if (!found) {
			chars
		}
	}
}
