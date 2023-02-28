#include "stats.h"

void comparator(Stats *s, uint32_t *A, uint32_t x, uint32_t y) {
    if(cmp(s, A[x], A[y]) > 0) {
        swap(s, &A[x], &A[y]);
    }
}

void batcher_sort(Stats *stats, uint32_t *A, uint32_t n) {
    if(n == 0) {
        return;
    }

    uint32_t t = 0;
    uint32_t num = n;
    while(num > 0) {
        num = (uint32_t)(num / 2);
	t++;
    }
    uint32_t p = 1 << (t - 1);

    while(p > 0) {
        uint32_t q = 1 << (t - 1);
        uint32_t r = 0;
	uint32_t d = p;

	while(d > 0) {
	    for(uint32_t i = 0; i < n - d; i++) {
	        if((i & p) == r) {
	            comparator(stats, A, i, i + d);
		}
	    }

	    d = q - p;
	    q = q >> 1;
	    r = p;
	}
        
	p = p >> 1;
    }
}
