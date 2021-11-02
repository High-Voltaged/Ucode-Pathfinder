#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {

    if (lineptr == NULL || fd < 0 || buf_size < 0) {
        return -2;
    }

    *lineptr = mx_realloc(*lineptr, buf_size);
    mx_memset(*lineptr, '\0', malloc_size(*lineptr));

    char c;
    buf_size = 1;
    size_t count = 0;
    while (read(fd, &c, buf_size) > 0) {

        if (c == delim) 
            return count;
        
        if (count >= buf_size) {
            *lineptr = mx_realloc(*lineptr, count + 1);
        }

        (*lineptr)[count++] = c;
        
    }

    if (count == 0) {
        return -1;
    }

    mx_memset(&(*lineptr)[count], '\0', malloc_size(*lineptr) - count);
    return count;

}
