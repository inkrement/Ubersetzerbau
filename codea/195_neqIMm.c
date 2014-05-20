#include <stdio.h>

extern long f(long x);

long gt(long x, long y) {
	return x > y ? -1L : 0L;
}

long neq(long x, long y) {
	return x != y ? -1L : 0L;
}

long f2(long **a) {
	 return neq(3, a[1][1]); // IM <> MEM(MEM)
}

int main(int argc, char** argv) {
	long vals[] = {0xFFFFFFFFFFFFFFFFL, 0xFFFFFFFFL, 0};
	int num_vals = 3;
	int i;
	int x;
	int disp = 10;
	long val[3];
	long *ref[] = {&val[0], &val[1], &val[2]};

	for(i=0; i<num_vals; i++) {
		for(x = -disp; x <= disp; x++) {
			val[0] = vals[i] + x;
			val[1] = vals[i] + x + 1;
			val[2] = vals[i] + x + 2;
			if(f((long)ref) != f2(ref)) {
				printf("f({%ld,%ld,%ld})=%ld, expected: %ld\n", val[0],val[1],val[2], f((long)ref), f2(ref));
				return 3;
			}
		}
		
	}
	return 0;
}
