/*@ ensures \result >= x && \result >= y;
    ensures \result == x || \result == y;
*/
int max(int x, int y) {
    return (x > y) ? x : y;
}

int main(void) {
    max(1, 2);
    return 0;
}