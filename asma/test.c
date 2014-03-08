#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define STR_LEN 16

extern void asma(unsigned char *s, unsigned char *t, unsigned char *u);

int main(){

	unsigned char *first = (unsigned char*) malloc(STR_LEN * sizeof(unsigned char));
	unsigned char *second = (unsigned char*)malloc(STR_LEN*sizeof(unsigned char));
	unsigned char *result = (unsigned char*)malloc(STR_LEN*sizeof(unsigned char));

	strcpy(first, "abcdefghikl");
	strcpy(second, "haha");
	strcpy(result, "result");

	asma(first, second, result);

	printf("%s\n", result);

	return 0;
}