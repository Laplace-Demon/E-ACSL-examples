#include <limits.h>

/*@ requires x > INT_MIN;
    ensures (x >= 0 ==> \result == x) && (x < 0 ==> \result == -x);
    assigns \nothing;
*/
int abs(int x) {
    //@ ghost int y = 0;
    if (x >= 0) return x;
    return -x;
}

int main() {
    return 0;
}