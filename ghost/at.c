#include <owi.h>

int main(void) {
    int n = owi_i32();
    
    //@ ghost one: ;
    owi_assume(n <= 1);
    //@ ghost two: ;

    //@ assert \at(n, one) <= 1;
    return 0;
}
