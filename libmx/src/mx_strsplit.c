#include "../inc/libmx.h"

char **mx_strsplit(char const *s, char c) {

    if (s == NULL) return NULL;

    int word_count = mx_count_words(s, c);
    char **words = malloc((word_count + 1) * sizeof(char*));
    if (words == NULL) return NULL;

    int word_idx = 0;
    while (*s) {

        if (*s != c) {
            
            int s_len = 0;
            while (s[s_len] != c && s[s_len]) {
                s_len++;
            }
            words[word_idx++] = mx_strndup(s, s_len);
            s += s_len;
            continue;
        
        }
        ++s;
    
    }
    words[word_idx] = NULL;

    return words;
}
