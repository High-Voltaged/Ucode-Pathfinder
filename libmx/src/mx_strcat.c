int mx_strlen(const char* s);

char *mx_strcat(char *restrict s1, const char *restrict s2) {

    const int length = mx_strlen(s1) + mx_strlen(s2) + 1;
    char new_str[length];

    for (int i = 0; i < (mx_strlen(s1) + 1); ++i) {

        new_str[i] = s1[i];

    }
    for (int i = 0; i < (mx_strlen(s2) + 1); ++i) {

        new_str[i + mx_strlen(s1)] = s2[i];

    }
    for (int i = 0; i < length; ++i) {
        s1[i] = new_str[i];
    }
    return s1;

}
