#include <stdbool.h>

int mx_tolower(int c) {
    if (!((c >= 65) && (c <= 90))) {
        return c;
    } else {
        return (c + 32);
    }
}
