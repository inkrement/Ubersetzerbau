#include <stdio.h>

extern long f(long x, long y);

long gt(long x, long y) {
	return x > y ? -1L : 0L;
}

long neq(long x, long y) {
	return x != y ? -1L : 0L;
}

long f2(long a, long b) {
	 return gt((a+3), (b+2));
}

int main(int argc, char** argv) {
	long vals[] = {0xFFFFFFFFFFFFFFFFL, 0xFFFFFFFFL, 0};
	int num_vals = 3;
	int i;
	int x, y;
	int disp = 10;

	for(i=0; i<num_vals; i++) {
		for(x = -disp; x <= disp; x++) {
			long val = vals[i] + x;

			for(i=0; i<num_vals; i++) {
				for(y = -disp; y <= disp; y++) {
					long val2 = vals[i] + y;
					if(f(val, val2) != f2(val, val2)) {
						printf("f(%ld, %ld)=%ld, expected: %ld\n", val, val2, f(val, val2), f2(val, val2));
						return 3;
					}
				}
			}
		}
	}
	return 0;
}
