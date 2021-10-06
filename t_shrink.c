#include <stdio.h>
#include <stdlib.h>

char *shrinkstr(char *arr, int size);

int main(int argc, char **argv) {

	char str[24] = "abcdefghijklmnop";
	char *newstr;

	newstr = shrinkstr(str, 24);

	printf("Old: %s, %d\nNew: %s, %d\n", str, sizeof(str), newstr, sizeof(newstr));
	
	return 0;
}

char *shrinkstr(char *arr, int size) {
	int count = 0;

	for (int i=0; i < size; i++) {
		if (arr[i] == NULL) { break; }
		else { count++; }
	} char ret[count];

	for (int i=0; i < count; i++) {
		printf("%c\n", arr[i]);
		ret[i] = arr[i];
	} return ret;
}
