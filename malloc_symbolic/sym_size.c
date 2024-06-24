#include <stdlib.h>
#include <owi.h>

/*@
    ensures \forall int i; 0 <= i < size - 1 ==> buffer[i] == 1;
*/
void memset_one(int size, int* buffer) {
    for (int i = 0 ; i < size; ++i) buffer[i] = 1;
}

int main(void) {
    int size = owi_i32();
    owi_assume(size > 10);
    owi_assume(size < 20);
    int* buffer = malloc(size * sizeof(int));
    memset_one(size, buffer);
    return 0;
}