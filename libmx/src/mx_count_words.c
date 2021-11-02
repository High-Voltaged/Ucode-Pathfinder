int mx_count_words(const char *str, char delim) {
    
    int words = 0, count = 0;
    str++;
    
    while (*str != '\0') {

        if (*str == delim) {
            if (*(str - 1) != delim) {
                words++;
            }
        }

        str++;
        count++;
    
    }
    if ((*(str - 1) != delim) && count) ++words;
    return words;

}
