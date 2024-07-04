int col = 0;
//@ global invariant I : 0 <= col <= 79;

void out_char(char c) {
    col++;
    if (col >= 80) col = 0;
}

int main(void) {
    out_char(' ');
    return 0;
}
