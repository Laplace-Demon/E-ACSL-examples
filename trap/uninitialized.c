// #include <stdlib.h>

int main(void) {
    int* p, x;
    p = (int*)malloc(sizeof(int));
    // free(p);
    x = *p + 1;
    return x + 1;
}