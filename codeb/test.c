#include <stdio.h>

extern long long int neq(long long int a, long long int b);
extern long long int oder(long long int a, long long int b, long long int c);
extern long long int greater(long long int a, long long int b);
extern long long int f(long long int a, long long int b);

int main(){
	printf("%lld\n", neq(0,0));
	printf("%lld\n", neq(1,0));
	printf("%lld\n", neq(0,1));
	printf("%lld\n", neq(1,1));
	printf("%lld\n", neq(255,255));

	printf("%lld\n", oder(1,1, 0));
	printf("%lld\n", oder(1,1, 1));
	printf("%lld\n", oder(1,0, 1));
	printf("%lld\n", oder(1,0, 0));
	printf("%lld\n", oder(0,0, 1));
	printf("%lld\n", oder(0,0, 0));

	printf("%lld\n", greater(5,10));
	printf("%lld\n", greater(5,0));
	printf("%lld\n", greater(1230,10));

	printf("%lld\n", f(1,1));
	printf("%lld\n", f(1,0));
	printf("%lld\n", f(-1,-3));
}