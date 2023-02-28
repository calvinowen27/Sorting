#include "stats.h"
#include "gaps.h"

void shell_sort(Stats *stats, uint32_t *arr, uint32_t length) {
    for(uint32_t i = 0; i < GAPS; i++) {
        uint32_t gap = gaps[i];
        for(uint32_t j = gap; j < length; j++) {
            uint32_t k = j;
	    uint32_t temp = move(stats, arr[j]);
	    while(k >= gap && cmp(stats, temp, arr[k - gap]) < 0) {
	        arr[k] = move(stats, arr[k - gap]);
		k -= gap;
	    }

	    arr[k] = move(stats, temp);
	}
    }
}
