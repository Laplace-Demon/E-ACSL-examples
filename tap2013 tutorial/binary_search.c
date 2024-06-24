/*@
    predicate sorted{L} (int* a, int length) =
        \valid(a + (0 .. length - 1)) && (\forall int i, j; 0 <= i <= j <= length - 1 ==> a[i] <= a[j]);
*/

/*@ requires length >= 0;
    requires \valid(a + (0 .. length - 1));
    requires sorted(a, length);
    assigns  \nothing;
    behavior exists:
        assumes \exists int i; 0 <= i <= length - 1 && a[i] == key;
        ensures 0 <= \result <= length - 1 && a[\result] == key;
    behavior not_exists:
        assumes \forall int i; 0 <= i <= length - 1 ==> a[i] != key;
        ensures \result == -1;
    complete behaviors;
    disjoint behaviors;
*/
int binary_search(int* a, int length, int key) {
    int low = 0, high = length - 1;
    /*@ loop invariant 0 <= low <= high + 1;
        loop invariant high < length;
        loop invariant \forall int k; 0 <= k < low ==> a[k] < key;
        loop invariant \forall int k; high < k < length ==> a[k] > key;
        loop assigns low, high;
        loop variant high - low;
    */
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (key == a[mid]) return mid;
        else if (key < a[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}