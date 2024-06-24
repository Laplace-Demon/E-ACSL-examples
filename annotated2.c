#include <owi.h>

/*@ requires \valid(array + (0 .. size-1));
    ensures  \forall integer i; 0 <= i < size ==> array[i] == 0;
*/
void zero_array(int* array, int size) {
    memset(array, 0, (size - 1) * sizeof(int));
}

int main(void) {
    int size = owi_i32();
    owi_assume(size > 0);
    owi_assume(size <= 10);
    int numbers[10];
    zero_array(numbers, size);
    return 0;
}
