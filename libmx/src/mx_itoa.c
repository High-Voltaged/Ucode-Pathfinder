#include "../inc/libmx.h"

int mx_digit_count(int num) {

    int count = 0;
    do {
        num /= 10;
        ++count;
    } while (num != 0);
    return count;

}

char *mx_itoa(int num) {

    if (num == -2147483648) {
        return mx_strdup("-2147483648");
    } else if (num == 2147483647) {
        return mx_strdup("2147483647");
    }

    char *result = mx_strnew(mx_digit_count(num));
    int sign = num;

    if (sign < 0) num *= -1;
    
    int i = 0;
    do {
        result[i] = (num % 10) + '0';
        num /= 10;
        ++i;
    } while (num > 0);
    
    if (sign < 0)
        result[i++] = '-';
    
    result[i] = '\0';
    mx_str_reverse(result);
    
    return result;

}
