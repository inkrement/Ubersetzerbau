#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

//extern int funf(int a);

extern int oder(int a, int b, int c);

//extern uint64_t funf_uint(uint64_t a);

/*uint64_t same(uint64_t a){
	return a;
}*/

int main(){
	printf("%d\n", oder(0,0, 0));
	printf("%d\n", oder(1,0, 0));
	printf("%d\n", oder(0,0, 1));
	//printf("%"PRId64"\n", (uint64_t) same((uint64_t) 2));
}