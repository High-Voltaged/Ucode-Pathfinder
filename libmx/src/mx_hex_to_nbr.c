#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {

    if (hex == NULL) return 0;

    unsigned long value = 0;
    while (*hex) {
        
        char symb = *hex++; 
        
        if (mx_isdigit(symb)) {
          
            symb = symb - '0';
        
        } else if (mx_islower(symb)) {
        
            symb = symb - 'a' + 10;
       
        } else if (mx_isupper(symb)) {
        
            symb = symb - 'A' + 10;
        
        }
    
        value = (value << 4) | (symb & 0xF);
    }

    return value;
}
