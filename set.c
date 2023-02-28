#include "set.h"

Set set_empty(void) {
    return (uint32_t) 0;
}

Set set_universal(void) {
    return (uint32_t) 4294967295;
}

Set set_insert(Set s, uint8_t x) {
    return s | (1 << x);
}

Set set_remove(Set s, uint8_t x) {
    return s & (-1 << x);
}

bool set_member(Set s, uint8_t x) {
    return (s & (1 << x)) != 0;
}

Set set_intersect(Set s, Set t) {
    return s & t;
}

Set set_complement(Set s) {
    return !s;
}
