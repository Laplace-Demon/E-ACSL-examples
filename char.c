#include <owi.h>

int main() {
    int c = owi_i32();
    c = 2;
    owi_assert(c == 2);
    return 0;
}