#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s1[100] ="";
    char s2[100] ="";
    FILE * onegin ;
    onegin = fopen("C:\\Users\\pomah_000\\Desktop\\Onegin\\reading.txt" , "rt");
    FILE * writing = fopen("C:\\Users\\pomah_000\\Desktop\\Onegin\\writing.txt" , "wt"  );


    while ( fgets(s1, 100, onegin) != NULL )
        {
            if (strcmp(s1,s2)!=0)
                {
                    fprintf( writing, "%s", s1);
                    sprintf(s2,"%s", s1);
                }

            printf("%s",s2);
        }
    return 0 ;
}
