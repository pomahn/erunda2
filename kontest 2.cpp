
char * convert (char * dst, const char * src)
{
    char string[100];
    int length = strlen (src);
    int ostatok = 4 - length % 4;
    int k = 0;
    for (k = 0; k < ostatok;)
    {
        string[k] = '0';
        k++;
    }

    strcpy (&string[ostatok], src);
    int j = 0;
    int i = 0;
    char ds[100];
    for (i = 0; i <= (strlen (string)-4); )
    {
        switch (8 * (string[i] - '0') + 4 * (string[i+1] - '0') + 2 * (string[i+2] - '0') + 1 * (string[i+3] - '0'))
        {
            case 10:
                ds[j] = 'A'; break;
            case 11:
                ds[j] = 'B'; break;
            case 12:
                ds[j] = 'C'; break;
            case 13:
                ds[j] = 'D'; break;
            case 14:
                ds[j] = 'E'; break;
            case 15:
                ds[j] = 'F'; break;
            default:
                ds[j] = (8 * (string[i] - '0') + 4 * (string[i+1] - '0') + 2 * (string[i+2] - '0') + 1 * (string[i+3] - '0') + '0'); break;
        }


        j++;
        i += 4;
    }
    ds[j] = '\0';
    j = 0;
    while (ds[j] == '0')
    {
        j++;
    }
    strcpy (dst, &ds[j]);


    return dst;
}
