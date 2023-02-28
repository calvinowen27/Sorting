#include "batcher.c"
#include "heap.c"
#include "quick.c"
#include "set.c"
#include "set.h"
#include "shell.c"
#include "stats.c"
#include "stats.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define OPTIONS "ahbsqr:n:p:H"

void print_results(
    char *name, uint32_t *result_arr, uint32_t size, Stats *stats, uint32_t elements) {
    printf("%s, %d elements, %lu moves, %lu compares", name, size, stats->moves, stats->compares);
    for (uint32_t i = 0; i < elements && i < size; i++) {
        if (i % 5 == 0) {
            printf("\n");
        }
        printf("%13d", result_arr[i]);
    }
    printf("\n");
}

void create_array(uint32_t *arr, uint32_t size, uint32_t seed) {
    srand(seed);
    for (uint32_t i = 0; i < size; i++) {
        arr[i] = rand() & 1073741823;
    }
}

void usage(char *exec) {
    fprintf(stderr,
        "SYNOPSIS\n"
        "   Tests different sorting algorithms, including Shell sort, Heap sort, Batcher sort, and "
        "Quick sort.\n"
        "\n"
        "USAGE\n"
        "   %s [-ahbsqr:n:p:H] [-r seed] [-n size] [-p elements]\n"
        "\n"
        "OPTIONS\n"
        "   -a            runs all sorting algorithms.\n"
        "   -h            runs heap sort.\n"
        "   -b            runs batcher sort.\n"
        "   -s            runs shell sort.\n"
        "   -q            runs quick sort.\n"
        "   -r seed       sets the seed for the randomly generated array.\n"
        "   -n size       sets the size of the randomly generated array.\n"
        "   -p elements   set the number of sorted elements to print after sorting.\n"
        "   -H            displays usage help.\n",
        exec);
}

int main(int argc, char **argv) {
    Stats s;
    uint32_t seed = 13371453;
    uint32_t size = 100;
    uint32_t elements = 100;
    Set set = set_empty();

    int opt = 0;
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a':
            // run all sorting algorithms
            set = set_insert(set_insert(set_insert(set_insert(set, 0), 1), 2), 3);
            break;
        case 'h':
            set = set_insert(set, 0);
            reset(&s);
            break;
        case 'b':
            set = set_insert(set, 1);
            reset(&s);
            break;
        case 's':
            set = set_insert(set, 2);
            reset(&s);
            break;
        case 'q':
            set = set_insert(set, 3);
            reset(&s);
            break;
        case 'r':
            // set seed of random
            seed = (uint32_t) strtoul(optarg, NULL, 10);
            break;
        case 'n':
            size = (uint32_t) strtoul(optarg, NULL, 10);
            // set size of array
            break;
        case 'p':
            elements = (uint32_t) strtoul(optarg, NULL, 10);
            // print out p number of elements from the array
            break;
        default:
            // prints program usage
            usage(argv[0]);
            return EXIT_FAILURE;
        }
    }

    uint32_t *arr = malloc(size * sizeof(uint32_t));

    if (set_member(set, 0)) {
        create_array(arr, size, seed);
        heap_sort(&s, arr, size);
        print_results("Heap Sort", arr, size, &s, elements);
        reset(&s);
    }

    if (set_member(set, 1)) {
        create_array(arr, size, seed);
        batcher_sort(&s, arr, size);
        print_results("Batcher Sort", arr, size, &s, elements);
        reset(&s);
    }

    if (set_member(set, 2)) {
        create_array(arr, size, seed);
        shell_sort(&s, arr, size);
        print_results("Shell Sort", arr, size, &s, elements);
        reset(&s);
    }

    if (set_member(set, 3)) {
        create_array(arr, size, seed);
        quick_sort(&s, arr, size);
        print_results("Quick Sort", arr, size, &s, elements);
        reset(&s);
    }

    free(arr);
}
