/*@ requires length > 0;
    requires \valid(a + (0 .. length - 1));
    assigns  \nothing;
    ensures  0 <= \result <= length - 1;
    ensures  \forall int i; 0 <= i <= length - 1 ==> a[\result] <= a[i]; 
*/
int find_min(int* a, int length) {
    int min, min_idx;
    min_idx = 0;
    min = a[0];
    /*@ loop invariant 1 <= i <= length;
        loop invariant 0 <= min_idx <= length - 1;
        loop invariant \forall int j; 0 <= j <= i - 1 ==> a[j] >= min;
        loop invariant a[min_idx] == min;
        loop assigns   min_idx, min, i;
        loop variant   length - i;
    */
    for (int i = 1; i < length; ++i) {
        if (a[i] < min) {
            min_idx = i;
            min = a[i];
        }
    }
    return min_idx;
}

int main(void) {
    
}