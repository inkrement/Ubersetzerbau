#include <stdio.h>

extern long f(long x);

long gt(long x, long y) {
	return x > y ? -1L : 0L;
}

long neq(long x, long y) {
	return x != y ? -1L : 0L;
}

long f2(long a) {
	 return neq((0x11223344L * 0x11223344L), (a+1)); // long IM <> R2
}

int main(int argc, char** argv) {
	long vals[] = {0xFFFFFFFFFFFFFFFFL, 0xFFFFFFFFL, 0};
	int num_vals = 3;
	int i;
	int x;
	int disp = 10;

	for(i=0; i<num_vals; i++) {
		for(x = -disp; x <= disp; x++) {
			long val = vals[i] + x;
			if(f(val) != f2(val)) {
				printf("f(%ld)=%ld, expected: %ld\n", val, f(val), f2(val));
				return 3;
			}
		}
		
	}
	return 0;
}
