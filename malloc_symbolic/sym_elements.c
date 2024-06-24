#include <stdlib.h>
#include <owi.h>

/*@
    ensures \forall int i; 0 <= i < size ==> buffer[i] >= 0;
*/
void square_buffer(int size, int* buffer) {
    for (int i = 0 ; i < size; ++i) buffer[i] = buffer[i] * buffer[i]; 
}

int main(void) {
    int size = 10;
    int* buffer = malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) buffer[i] = owi_i32(); 
    square_buffer(size, buffer);
    return 0;
}