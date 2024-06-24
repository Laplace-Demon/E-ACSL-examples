void lazy(void) {
    int x;
    x = 1;

    init:
    x = 2;

    step1:
    x = 3;

    step2:
    x = 4;

    final:
    x = 5;

    //@ assert \at(x, init) * 5 == \at(x, final);
}

int main(void) {
    lazy();
    return 0;
}