#include <stdbool.h>

int mx_toupper(int c) {
    if (!((c >= 97) && (c <= 122))) {
        return c;
    } else {
        return (c - 32);
    }
}
