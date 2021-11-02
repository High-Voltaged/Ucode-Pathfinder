#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int right) {

    if (arr == NULL) return -1;

    int i = left;
    int j = right;
    int pivot_len = mx_strlen(arr[(left + right) / 2]);
    int swap_count = 0;

    while (i <= j) {

        while (mx_strlen(arr[i]) < pivot_len) ++i;
        while (mx_strlen(arr[j]) > pivot_len) --j;

        if (i <= j) {

            if (mx_strlen(arr[i]) != mx_strlen(arr[j])) {

                char* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

            }
            ++swap_count;
            ++i;
            --j;

        }

    }
    if (left < j) mx_quicksort(arr, left, j);
    if (i < right) mx_quicksort(arr, i, right);
    return swap_count;

}
