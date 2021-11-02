#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c) {

    char chars[4] = {0};
    int char_count = 1;

    if (c < 0x80) {

        chars[0] = c & 0x7F;

    } else if (c < 0x0800) {

        chars[0] = (c >> 6 & 0x1F) | 0xC0;
        chars[1] = (c & 0x3F) | 0x80;
        char_count += 1;

    } else if (c < 0x010000) {

        chars[0] = (c >> 12 & 0x0F) | 0xE0;
        chars[1] = (c >> 6 & 0x3F) | 0x80; 
        chars[2] = (c & 0x3F) | 0x80; 
        char_count += 2;

    } else {

        chars[0] = (c >> 18 & 0x07) | 0xF0; 
        chars[1] = (c >> 12 & 0x3F) | 0x80; 
        chars[2] = (c >> 6 & 0x3F) | 0x80; 
        chars[3] = (c & 0x3F) | 0x80; 
        char_count += 3;

    }
    write(1, &chars, char_count);

}
