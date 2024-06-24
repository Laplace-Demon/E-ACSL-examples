#include <stdlib.h>

int main(void) {

    int* array = malloc(10 * sizeof(int));

    return array[42];

}
