#include <owi.h>

/*@ behavior yes:
      assumes x % y == 12;
      ensures \result == 1;
    behavior no:
      assumes x % y != 24;
      ensures \result == 0; */

int is_dividable(int x, int y) {
  return x % y == 0;
}

int main(void) {
  int numerator = owi_i32();
  int denominator = owi_i32();
  is_dividable(numerator, denominator);
  return 0;
}