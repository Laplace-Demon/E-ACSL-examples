/*@ requires x == 3;
*/
int f(int x);
/*@ requires y == 2;
*/
int g(int y);

int main(void) {
    f(3);
    return 0;
}

int f(int x) {
    return g(x - 1);
}

int g(int y) {
    return y + 1;
}