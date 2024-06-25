#include <owi.h>
#include <limits.h>

int main(void) {
    int x, y = 2147483646;
    x = y + y;
    return 0;
}