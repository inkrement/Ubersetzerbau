#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define STR_LEN 26

extern void asmb(unsigned char *s, unsigned char *t, unsigned char *u);

int main(){

	int i;

	unsigned char *first = (unsigned char*)malloc(STR_LEN * sizeof(unsigned char));
	unsigned char *second = (unsigned char*)malloc(STR_LEN*sizeof(unsigned char));
	unsigned char *result = (unsigned char*)malloc(STR_LEN*sizeof(unsigned char));

	const char *str_operand1= "\x8c\x18\xa4\x30\xbc\x48\xd4\x60\xec\x78\x04\x90\x1c\xa8\x34\xc0\x4c\xd8\x64\xf0\x7c\x08\x94\x20\xac\x38";
	const char *str_operand2= "\xfb\xec\xdd\xce\xbf\xb0\xa1\x92\x83\x74\x65\x56\x47\x38\x29\x1a\x0b\xfc\xed\xde\xcf\xc0\xb1\xa2\x93\x00";
	const char *str_result= "abcdefghij";
	
	//strcpy(first, "abcdefghikl");
	//strcpy(second, "haha");
	//strcpy(result, "result");

	memcpy(first, str_operand1, strlen(str_operand1));
	memcpy(second, str_operand2, strlen(str_operand2));
	memcpy(result, str_result, strlen(str_result));

	asmb(first, second, result);

	//fwrite(result, sizeof(unsigned char), STR_LEN, stdout);

	printf("s: ");
	for ( i = 0; i < STR_LEN; i++)
    	printf("%02x ", first[i]);

	printf("\n");

	printf("t: ");
	for ( i = 0; i < STR_LEN; i++)
    	printf("%02x ", second[i]);

	printf("\n");

	printf("r: ");
	for (i = 0; i < STR_LEN; i++)
    	printf("%02x ", result[i]);
    printf("\n");

    printf("p: ");
    printf("%s\n", result);

	printf("\n");
	//printf("%.*s\n", STR_LEN, result);

	return 0;
}