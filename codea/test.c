#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>



extern int funf(int a);

extern uint64_t funf_uint(uint64_t a);

uint64_t same(uint64_t a){
	return a;
}

int main(){
	printf("%d\n", funf(534));
	//printf("%"PRId64"\n", (uint64_t) same((uint64_t) 2));
}