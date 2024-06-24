#include <owi.h>

/*@
  requires index >= 0;
  requires index < size;
  ensures \result >= 0;
*/
int return_element(const int a[], int size, int index) {
    return a[index];
}

int main(void) {
    int array_size = 5;
    int test_array[] = {1, 2, 0, -1, 5};

    int index = owi_i32();

    return_element(test_array, array_size, index);

    return 0;
}