#include <stdio.h>

//extern long long int f(long long int a, long long int b);

//extern  long long int mymin(long long int a, long long int b);

extern  long long int recall(long long int a, long long int b);



extern  long long int mysgn(long long int a);

int main(){
	printf("%lld\n", mysgn(5)); //1
	printf("%lld\n", mysgn(0)); //0
	printf("%lld\n", mysgn(-2)); //-1
	/*printf("%lld\n", mymin(2,3));
	printf("%lld\n", mymin(0,-1));
	printf("%lld\n", mymin(-5,-6));
	printf("%lld\n", mymin(0,1));*/
}