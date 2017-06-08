#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <ctype.h>
#include <assert.h>

int filesize (FILE * file);
char* file_v_buf (FILE *reading);
int string_count (char*  buf_pointer);
void strings_pointers (char* buf_point, struct pointer* *pointers, int string_counter);
int my_strcmp (const void *string1, const void *string2);
void array_copy (char* *normsort, char* *pointer_on_strings, int string_counter);
void file_print (FILE*writing, struct pointer* *pointers, int string_counter);
int is_rus_letter (char letter);
char my_tolower (char letter);
void struct_copy (struct pointer* *newpointer, struct pointer* *pointers, int string_counter);


typedef struct pointer
    {
    char* begining;
    char* ending;
    };



int main(int argc, char** argv)
{

    FILE* reading = fopen(argv[1], "r");
    assert(reading);

    char* buf_pointer = file_v_buf (reading);

    int string_counter = string_count (buf_pointer);

    printf("string_counter\n");

    pointer pointers_struct[string_counter-1];
    pointer* pointers[string_counter-1];

    for (int i = 0; i < string_counter; i++)
        {
        pointers[i] = &pointers_struct[i];
        }


    strings_pointers (buf_pointer, pointers, string_counter);





    qsort (pointers,         string_counter, sizeof(pointers[0]),         my_strcmp);




    FILE * writing = fopen(argv[2], "wt");

    file_print(writing, pointers, string_counter) ;

    fclose(reading);

    fclose(writing);

    return 0;
    }




char* file_v_buf(FILE *reading)
    {

        int file_size = 0;
        file_size = filesize(reading);
        rewind(reading);
        char* file_string = (char*)calloc(1, file_size);
        fread(file_string, file_size, 1, reading);
        return file_string;
    }


int filesize(FILE *file)
    {
        FILE* Minifile = file ;
        long int file_size=0;

        fseek( file, 0, SEEK_END );
        file_size = ftell( file );


        return (file_size );
    }


int string_count(char*  buf_pointer)
    {
        assert(buf_pointer);
        char* pointer = buf_pointer;
        int string_counter = 0;

        while (1)

            {

            if (strchr(pointer, '\n') == NULL )
                {
                break;
                }

            pointer = strchr(pointer, '\n')+1;

             string_counter++;
            }

       return (string_counter+1);
    }



void strings_pointers(char* buf_point, struct pointer* *pointers, int string_counter)
    {
    assert(buf_point);

    pointers[0] ->begining = buf_point;

    for (int i = 1;    i <= (string_counter-1);     i++)
        {

        char* c = strchr(pointers[i-1] ->begining, '\n');
        *c = '\0';
        pointers[i-1] ->ending = c-1;
        pointers[i] ->begining = c+1;

        assert(pointers[i] ->begining);
        assert(pointers[i-1] ->ending);
        }

    char* c = strchr(pointers[string_counter-1] ->begining, '\0');
    assert(c);
    pointers[string_counter-1] ->ending = c-1;
    }





int my_strcmp(const void *string1, const void *string2)
    {

    char* string_a =  (*(struct pointer **)string1) ->begining;
    char* string_b =  (*(struct pointer **)string2) ->begining;
    assert(string_a);

    while (1)
        {


        while (( !isalnum(*string_a) && (!is_rus_letter(*string_a)))  &&  (*string_a != '\0') )
            {
            string_a++;
            }

        while (( !isalnum(*string_b) && (!is_rus_letter(*string_b))) &&   (*string_b != '\0') )
            {

            string_b++;
            }

        if ( *string_a == '\0')
            {
            if (*string_b == '\0')
                {

                return 0;
                }
            else
                {

                 return -1;
                }
            }
        if ( *string_b == '\0')
            {

             return 1;
            }


        if (my_tolower(*string_a) - my_tolower(*string_b) != 0)
            {

            return (my_tolower(*string_a) - my_tolower(*string_b)) ;
            }
        string_a++;
        string_b++;
        }
    }





void file_print(FILE*writing, struct pointer* *pointers, int string_counter)
    {


    for (int i=0; i<=(string_counter-1); i++)
        {
        assert(pointers[i] ->begining);
        fprintf( writing, "%s", pointers[i] ->begining);
        fputc('\n', writing);
        }
    }


int is_rus_letter(char letter)
    {
    if ((letter >= 'À' && letter <= 'ß') || (letter >= 'à' && letter <= 'ÿ') )
                {
                return 1;
                }
    else
        {
        return 0 ;
        }
    }

char my_tolower (char letter)
    {
    if (is_rus_letter(letter))
        {
         if (letter >= 'À' && letter <= 'ß')
            {
            return (letter + ('à' - 'À'));
            }
        }

    return tolower(letter);



    }



