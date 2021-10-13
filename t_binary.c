#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strtobin(char *str);

char *prepend(char *s, char *c);

char *dtob(int n);


int main(int argc, char **argv) {

	char *str;
	scanf("%s", str);

	char *nstr = prepend(str, "A");

	printf("New string: %s\n", nstr);
	return 0;
}

char *strtobin(char *str) {
	
	int ch[strlen(str)];
	
	for (int i=0; i < strlen(str); i++)
		ch[i] = (int)str[i];

	char *binary;

	// Convert char by char in loop

	return binary;
}

char *dtob(int n) {
	
	char* bin;

	while (n > 1) {
		int r = n % 2;
		// bin = prepend(bin, (char)r);
		n = n / 2;
	}

	return bin;
}

char *prepend(char *s, char *c) {
	char *str;
	strcat(str, c);

	for (int i=0; i < strlen(s); i++) {
		
		str[i+strlen(c)] = s[i];
		printf("str[%d]: %c\n", i+strlen(c), str[i+strlen(c)]);
	
	} printf("str: %s\n", str);
	
	return str;
}
