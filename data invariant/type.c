#include <owi.h>

typedef double temperature;
//@ type invariant temperature_in_celsius(temperature t) = t >= -273.15;

temperature t;

void lower_temp() {
    t -= 10.;
}

int main(void) {
    t = -250.;
    lower_temp();
    lower_temp();
    lower_temp();
    lower_temp();
    return 0;
}
