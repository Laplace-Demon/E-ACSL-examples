#include <owi.h>

int main(void) {
    int* p = malloc(4 * sizeof(int)), x;
    x = p[4];
    return 0;
}