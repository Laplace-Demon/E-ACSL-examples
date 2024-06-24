/*@ requires n > 0;
    requires \valid(p + (0 .. n - 1));
    assigns  \nothing;
    ensures  \forall int i; 0 <= i <= n - 1 ==> \result >= p[i];
    ensures  \exists int e; 0 <= e <= n - 1 &&  \result == p[e];
*/
int max_seq(int* p, int n) {
    int res = *p;
    //@ ghost int e = 0;
    /*@ loop invariant 0 <= i <= n;
        loop invariant p == \at(p, Pre) + i;
        loop invariant \forall int j; 0 <= j <= i - 1 ==> res >= \at(p, Pre)[j];
        loop invariant 0 <= e < n;
        loop invariant res == \at(p, Pre)[e];
        loop assigns i, res, p, e;
        loop variant n - i;
    */
    for (int i = 0; i < n; ++i) {
        if (res < *p) {
            res = *p;
            //@ ghost e = i;
        }
        p++;
    }
    return res;
}