#include <stdio.h>

char *strtobin(char *str);

char *prepend(char *s, char c);

char *dtob(int n);


int main(int argc, char **argv) {

	char *str;
	scanf("%s", str);

	str = prepend(str, "A");

	printf("New string: %s\n", str);
	return 0;
}

char *strtobin(char *str) {
	
	int ch[strlen(str)];
	
	for (int i=0; i < strlen(str); i++)
		ch[i] = (int)str[i];

	char *binary;

	while () {


	}

	return binary;
}

char *dtob(int n) {
	
	char* bin;

	while (n > 1) {
		int r = n % 2;
		bin = prepend(bin, (char)r);
		n = n / 2;
	}

	return bin;
}

char *prepend(char *s, char c) {
	char *str;
	for (int i=0; i <= strlen(s); i++) {
		
		*(str+i+1) = *(s+i);

	} return (*str = c);
}
