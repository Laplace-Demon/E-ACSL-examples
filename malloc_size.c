#include <owi.h>
#include <string.h>

/*@ 
  requires size > 0;
  ensures \result == \null || \forall integer i; 0 <= i < 15 ==> ((int*)\result)[i] == 0;
*/
void* malloc_and_init(int size) {
    void* ptr = malloc(size);
    if (ptr != NULL) {
        memset(ptr, 0, size);
    }
    return ptr;
}

int main(void) {
    int size;
    size = owi_i32();

    int* buffer;
    buffer = (int*) malloc_and_init(size);

    free(buffer);
    return 0;
}