#include <stdbool.h>

bool mx_isspace(char c) {
    return (c == '\n') || (c == '\t') || (c == '\v') || (c == '\r') || (c == '\f') || (c == ' ');
}
