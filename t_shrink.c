#include <stdio.h>
#include <stdlib.h>

char *shrinkstr(char *arr, int size);

int main(int argc, char **argv) {

	char str[24] = "abc";
	char *newstr;

	newstr = shrinkstr(str, 24);

	printf("Old size: %d\nNew size: %d\n", sizeof(str), sizeof(newstr));
	
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
