char *mx_strnew(const int size);

char *mx_nbr_to_hex(unsigned long nbr) {
    
    if ((long)nbr < 0) return 0;

    else if (nbr == 0) return "0\0";

    char hexaDeciNum[100];

    int i = 0;
    while (nbr != 0) {
        
        int temp = 0;

        temp = nbr % 16;

        if (temp < 10) {
        
            hexaDeciNum[i] = temp + 48;
            i++;
        
        } else {

            hexaDeciNum[i] = temp + 87;
            i++;
        
        }

        nbr = nbr / 16;
    }
    char *res = mx_strnew(i);

    for (int j = i - 1, k = 0; j >= 0; j--, k++)
        res[k] = hexaDeciNum[j];
    return res;

}
