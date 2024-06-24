int main (void) {
  int i;
  int n = 10;
  int sum = 0;
  int t[10];

  for (i = 0; i < n; i++) t[i] = i;

  /*@ loop invariant 0 <= i < n;
    @ loop invariant sum == \sum(0, i - 1, \lambda integer k; t[k]);
    @ loop variant n - i;
   */
  for (i = 0; i < n; i++) sum += i;
  return 0;
}