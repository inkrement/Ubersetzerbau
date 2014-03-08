#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define STR_LEN 16

extern void asma(unsigned char *s, unsigned char *t, unsigned char *u);

int main(){

	unsigned char *first = (unsigned char*) malloc(STR_LEN * sizeof(unsigned char));
	unsigned char *second = (unsigned char*)malloc(STR_LEN*sizeof(unsigned char));
	unsigned char *result = (unsigned char*)malloc(STR_LEN*sizeof(unsigned char));

	const char *str_operand1= "abcdefghijklm";
	const char *str_operand2= "haha";
	const char *str_result= "abcdefghijklm";
	
	//strcpy(first, "abcdefghikl");
	//strcpy(second, "haha");
	//strcpy(result, "result");

	memcpy(first, str_operand1, strlen(str_operand1) + 1);
	memcpy(second, str_operand2, strlen(str_operand2) + 1);
	memcpy(result, str_result, strlen(str_result) + 1);

	asma(first, second, result);

	printf("s: ");
	for (int i = 0; i < STR_LEN; i++)
    	printf("%02x ", first[i]);

	printf("\n");

	printf("t: ");
	for (int i = 0; i < STR_LEN; i++)
    	printf("%02x ", second[i]);

	printf("\n");

	printf("result: ");
	for (int i = 0; i < STR_LEN; i++)
    	printf("%02x ", result[i]);

	printf("\n");

	return 0;
}