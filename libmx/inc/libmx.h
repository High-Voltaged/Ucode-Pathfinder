#ifndef LIBMX
#define LIBMX

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <malloc/malloc.h>
#include "../../inc/graph.h"

// List Pack

typedef struct s_list_t {
    void *data;
    struct s_list_t *next;
}              t_list_t;

void mx_foreach_list(t_list_t *list, void (*f)(t_list_t* node));
void mx_push_index(t_list_t **list, void *data, int index);
void mx_pop_index(t_list_t **list, int index);
void mx_del_node_if(t_list_t **list, void *del_data, bool (*cmp)(void *a, void* b));

// String Pack
int mx_strlen(const char* s);
void mx_swap_char(char* s1, char* s2);
void mx_str_reverse(char* s);
void mx_strdel(char **str);
void mx_del_strarr(char ***arr);
int mx_get_char_index(const char* str, char c);
char *mx_strnew(const int size);
char *mx_strdup(const char *s1);
char *mx_strndup(const char *s1, size_t n);
char *mx_strcpy(char* dst, const char* src);
char *mx_strncpy(char* dst, const char* src, int len);
int mx_strcmp(const char *s1, const char *s2);
int mx_strncmp(const char *s1, const char *s2, int n); //// ////
char *mx_strcat(char *restrict s1, const char *restrict s2);
char *mx_strchr(const char *s, int c); //// ////
char *mx_strstr(const char *haystack, const char *needle);
int mx_count_substr(const char *str, const char *sub);
int mx_get_substr_index(const char *str, const char *sub);
int mx_count_words(const char *str, char delim);
char *mx_strtrim(const char* str);
char **mx_strsplit(char const *s, char c);
bool mx_isspace(char c); //// ////
char *mx_del_extra_spaces(const char *str);
char *mx_strjoin(char const *s1, char const *s2);
char *mx_file_to_str(const char *filename);
char *mx_replace_substr(const char *str, const char *sub, const char *replace);
int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd);
bool mx_isdigit(int c); ///////
bool mx_isalpha(int c); ///////
int mx_atoi(const char* str); ///////
void mx_printerr(const char *s); ///////
bool mx_islower(int c);
bool mx_isupper(int c);
int mx_toupper(int c);
int mx_tolower(int c);
bool mx_is_str_found(char** strarr, const char* str);

// Utils Pack
void mx_printchar(char c);
void mx_print_unicode(wchar_t c);
void mx_printstr(const char* s);
void mx_printint(int n);
double mx_pow(double n, unsigned int pow);
int mx_sqrt(int x);
void mx_foreach(int *arr, int size, void (*f)(int));
unsigned long mx_hex_to_nbr(const char *hex);
char *mx_nbr_to_hex(unsigned long nbr);
void mx_print_strarr(char **arr, const char* delim);
char *mx_itoa(int num);
int mx_binary_search(char **arr, int size, const char *s, int *count);
int mx_bubble_sort(char **arr, int size);
int mx_quicksort(char **arr, int left, int right);

// Memory Pack

void *mx_memset(void *b, int c, size_t len);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
int mx_memcmp(const void *s1, const void *s2, size_t n);
void *mx_memchr(const void* s, int c, size_t n);
void *mx_memrchr(const void* s, int c, size_t n);
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len);
void *mx_memmove(void *dst, const void *src, size_t len);
void *mx_realloc(void *ptr, size_t size);

#endif
