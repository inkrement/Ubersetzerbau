#include <stdio.h>

extern long f(long x, long y);

long gt(long x, long y) {
	return x > y ? -1L : 0L;
}

long neq(long x, long y) {
	return x != y ? -1L : 0L;
}

long f2(long **a, long b) {
	 return neq(a[1][1], (b+1));
}

int main(int argc, char** argv) {
	long vals[] = {0xFFFFFFFFFFFFFFFFL, 0xFFFFFFFFL, 0};
	int num_vals = 3;
	int i;
	int x, y;
	int disp = 10;
	long val[3];
	long val2[3];
	long *ref[] = {&val[0], &val[1], &val[2]};

	for(i=0; i<num_vals; i++) {
		for(x = -disp; x <= disp; x++) {
			val[0] = vals[i] + x;
			val[1] = vals[i] + x + 1;
			val[2] = vals[i] + x + 2;

			for(i=0; i<num_vals; i++) {
				for(y = -disp; y <= disp; y++) {
					val2[0] = vals[i] + y;
					val2[1] = vals[i] + y + 1;
					val2[2] = vals[i] + y + 2;

					if(f((long)ref, val2[0]) != f2(ref, val2[0])) {
						printf("f({%ld,%ld,%ld},%ld)=%ld, expected: %ld\n", val[0],val[1],val[2], val2[0], f((long)ref, val2[0]), f2(ref, val2[0]));
						return 3;
					}
				}
			}
		}
	}
	return 0;
}
