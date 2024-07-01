#include <owi.h>
#include <limits.h>

/*@

    behavior neg:
        assumes value < 0;
    behavior pos:
        assumes value >= 0;

    behavior odd:
        assumes value % 2 == 1;
    behavior even:
        assumes value % 2 == 0;

    complete behaviors neg, pos;
    disjoint behaviors neg, pos;
    disjoint behaviors odd, even;
*/
int f(int value) {
    return value;
}

int main() {
    int n = owi_i32();
    f(n);
    return 0;
}
