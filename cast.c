#include <owi.h>
#include <limits.h>

int main(void) {
    long long x = owi_i64();
    int result = (x <= (long long)INT_MAX);
    owi_assert(result);

    // long x = INT_MAX + 1;
    // owi_assert(x > 0);
    return 0;
}