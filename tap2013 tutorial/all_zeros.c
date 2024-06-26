#include <owi.h>

/*@ requires n >= 0 && \valid(t + (0 .. n - 1));
    assigns  \nothing;
    ensures  \result != 0 <==>
                 (\forall int j; 0 <= j < n ==> t[j] == 0);
*/
int all_zeros(int t[], int n) {
    int k;
    /*@ loop invariant 0 <= k <= n;
        loop invariant \forall int j; 0 <= j < k ==> t[j] == 0;
        loop variant   n - k;
    */
    for (k = 0; k < n; k++)
        if (t[k] != 0)
            return 0;
    return 1;
}

int main(void) {
    int* t;
    int n;
    n = 10;
    t = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) t[i] = owi_i32();
    all_zeros(t, n);
    return 0;
}