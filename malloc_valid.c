int main(void) {
    int *x;
    x = (int*)malloc(sizeof(int));

    /*@ assert \valid(x); */
    
    return 0;
}

// #include <owi.h>
// #include <stdlib.h>

// int main(void) {
//   int size = owi_i32();
//   owi_assume(size >= 0);

//   int *x;
//   x = (int*)malloc(size * sizeof(int));

//   /*@ assert \valid(x); */

//   free(x);
//   return 0;
// }