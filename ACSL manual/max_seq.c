/*@ 
    requires \valid(p + (0 .. n - 1));
    requires n > 0;
    ensures  \forall int i; 0 <= i <= n - 1 ==> \result >= p[i];
    ensures  \exists int e; 0 <= e <= n - 1 &&  \result == p[e];
*/
int max_seq(int* p, int n) {
    int res = *p;
    for (int i = 0; i < n; ++i) {
        if (res < *p) { res = *p; }
        p++;
    }
    return res;
}

int main(void) {
    int* p = (int*)malloc(sizeof(int));
    int n = 1 << 3;
    max_seq(p, n);
    return 0;
}